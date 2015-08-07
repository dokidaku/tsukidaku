#include <libdaku/daku.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include <stdio.h>
#include <stdlib.h>

lua_State *L;

void register_core(lua_State *L);
void register_actions(lua_State *L);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <script>\n", argv[0]);
        return 888888;
    }
    av_register_all();

    // Open Lua
    L = luaL_newstate();
    luaL_openlibs(L);
    // Export all C functions to Lua
    register_core(L);
    register_actions(L);
    // Execute
    int ret = luaL_dofile(L, argv[1]);
    if (ret != 0) {
        printf("Lua exited with error (code %d) T^T\n", ret);
        puts(lua_tostring(L, -1));
    }

    lua_close(L);
    return 0;
}
