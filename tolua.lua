#!/usr/local/bin/lua

function split(s)
    local a, w, i
    a = {}
    i = 0
    for w in s:gmatch('%S+') do
        i = i + 1
        a[i] = w
    end
    return a
end

function luatype(t)
    if t == 'int' then return 'integer'
    elseif t == 'float' or t == 'double' then return 'number'
    elseif t == 'char*' then return 'string'
    elseif t:sub(#t) == '*' then return 'integer'
    else return 'UNKNOWN'
    end
end

function tolua(list)
    local s = 'static int tolua__' .. list[#list] .. '(lua_State *L) {\n'
    local i, argc
    argc = #list - 3
    for i = 1, argc do
        s = s .. '    ' .. list[i + 2] .. ' arg' .. i .. ' = luaL_check' ..
            luatype(list[i + 2]) .. '(L, ' .. i .. ');\n'
    end
    if list[1] ~= 'void' then
        s = s .. '    lua_push' .. luatype(list[1]) .. '(L, ' .. list[2] .. '('
        for i = 1, argc do
            if i > 1 then s = s .. ', ' end
            s = s .. 'arg' .. i
        end
        s = s .. '));\n    return 1;\n}\n'
    else
        s = s .. '    ' .. list[2] .. '('
        for i = 1, argc do
            if i > 1 then s = s .. ', ' end
            s = s .. 'arg' .. i
        end
        s = s .. ');\n    return 0;\n}\n'
    end
    return s
end

print('#include <libdaku/daku.h>\n' ..
    '#include <lua.h>\n' ..
    '#include <lauxlib.h>\n' ..
    '#include <lualib.h>\n')

module = io.read()
regist_code = ''
list = nil
for s in io.lines(module .. '.fundefs') do if s ~= '' then
    list = split(s)
    print(tolua(list))
    regist_code = regist_code ..
        '    lua_pushcfunction(L, tolua__' .. list[#list] .. ');\n' ..
        '    lua_setglobal(L, "' .. list[#list] .. '");\n'
end end

print('void register_' .. module .. '(lua_State *L) {')
print(regist_code .. '}')
