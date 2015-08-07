#include <libdaku/daku.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static int tolua__matter_create(lua_State *L) {
    lua_pushinteger(L, daku_matter_create());
    return 1;
}

static int tolua__life(lua_State *L) {
    daku_matter* arg1 = luaL_checkinteger(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    daku_matter_setlife(arg1, arg2);
    return 0;
}

static int tolua__size(lua_State *L) {
    daku_matter* arg1 = luaL_checkinteger(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    daku_matter_setsize(arg1, arg2, arg3);
    return 0;
}

static int tolua__grosssize(lua_State *L) {
    daku_matter* arg1 = luaL_checkinteger(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    float arg4 = luaL_checknumber(L, 4);
    float arg5 = luaL_checknumber(L, 5);
    daku_matter_setgrosssize(arg1, arg2, arg3, arg4, arg5);
    return 0;
}

static int tolua__anchor(lua_State *L) {
    daku_matter* arg1 = luaL_checkinteger(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    daku_matter_setanchor(arg1, arg2, arg3);
    return 0;
}

static int tolua__pos(lua_State *L) {
    daku_matter* arg1 = luaL_checkinteger(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    daku_matter_setpos(arg1, arg2, arg3);
    return 0;
}

static int tolua__act(lua_State *L) {
    daku_matter* arg1 = luaL_checkinteger(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    daku_action* arg3 = luaL_checkinteger(L, 3);
    daku_matter_act(arg1, arg2, arg3);
    return 0;
}

static int tolua__wave_create(lua_State *L) {
    lua_pushinteger(L, daku_wave_create());
    return 1;
}

static int tolua__life_w(lua_State *L) {
    daku_wave* arg1 = luaL_checkinteger(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    daku_wave_setlife(arg1, arg2);
    return 0;
}

static int tolua__play(lua_State *L) {
    daku_wave* arg1 = luaL_checkinteger(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    daku_instrument* arg3 = luaL_checkinteger(L, 3);
    daku_wave_play(arg1, arg2, arg3);
    return 0;
}

static int tolua__world_create(lua_State *L) {
    int arg1 = luaL_checkinteger(L, 1);
    int arg2 = luaL_checkinteger(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    lua_pushinteger(L, daku_world_create(arg1, arg2, arg3));
    return 1;
}

static int tolua__populate(lua_State *L) {
    daku_world* arg1 = luaL_checkinteger(L, 1);
    daku_matter* arg2 = luaL_checkinteger(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    int arg4 = luaL_checkinteger(L, 4);
    daku_world_populate(arg1, arg2, arg3, arg4);
    return 0;
}

static int tolua__clang(lua_State *L) {
    daku_world* arg1 = luaL_checkinteger(L, 1);
    daku_wave* arg2 = luaL_checkinteger(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    daku_world_clang(arg1, arg2, arg3);
    return 0;
}

static int tolua__write(lua_State *L) {
    daku_world* arg1 = luaL_checkinteger(L, 1);
    char* arg2 = luaL_checkstring(L, 2);
    daku_world_write(arg1, arg2);
    return 0;
}

void register_core(lua_State *L) {
    lua_pushcfunction(L, tolua__matter_create);
    lua_setglobal(L, "matter_create");
    lua_pushcfunction(L, tolua__life);
    lua_setglobal(L, "life");
    lua_pushcfunction(L, tolua__size);
    lua_setglobal(L, "size");
    lua_pushcfunction(L, tolua__grosssize);
    lua_setglobal(L, "grosssize");
    lua_pushcfunction(L, tolua__anchor);
    lua_setglobal(L, "anchor");
    lua_pushcfunction(L, tolua__pos);
    lua_setglobal(L, "pos");
    lua_pushcfunction(L, tolua__act);
    lua_setglobal(L, "act");
    lua_pushcfunction(L, tolua__wave_create);
    lua_setglobal(L, "wave_create");
    lua_pushcfunction(L, tolua__life_w);
    lua_setglobal(L, "life_w");
    lua_pushcfunction(L, tolua__play);
    lua_setglobal(L, "play");
    lua_pushcfunction(L, tolua__world_create);
    lua_setglobal(L, "world_create");
    lua_pushcfunction(L, tolua__populate);
    lua_setglobal(L, "populate");
    lua_pushcfunction(L, tolua__clang);
    lua_setglobal(L, "clang");
    lua_pushcfunction(L, tolua__write);
    lua_setglobal(L, "write");
}
