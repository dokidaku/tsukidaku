#include <libdaku/daku.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static int tolua__move_by(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    lua_pushinteger(L, daku_fx_moveby(arg1, arg2, arg3));
    return 1;
}

static int tolua__move_to(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    lua_pushinteger(L, daku_fx_moveto(arg1, arg2, arg3));
    return 1;
}

static int tolua__fade_to(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    int arg2 = luaL_checkinteger(L, 2);
    lua_pushinteger(L, daku_fx_fadeto(arg1, arg2));
    return 1;
}

static int tolua__fade_in(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    lua_pushinteger(L, daku_fx_fadein(arg1));
    return 1;
}

static int tolua__fade_out(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    lua_pushinteger(L, daku_fx_fadeout(arg1));
    return 1;
}

static int tolua__scale_to(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    lua_pushinteger(L, daku_fx_scaleto(arg1, arg2, arg3));
    return 1;
}

static int tolua__scale_by(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    lua_pushinteger(L, daku_fx_scaleby(arg1, arg2, arg3));
    return 1;
}

static int tolua__zoom_to(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    lua_pushinteger(L, daku_fx_zoomto(arg1, arg2));
    return 1;
}

static int tolua__zoom_by(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    lua_pushinteger(L, daku_fx_zoomby(arg1, arg2));
    return 1;
}

static int tolua__rotate_to(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    lua_pushinteger(L, daku_fx_rotateto(arg1, arg2));
    return 1;
}

static int tolua__rotate_by(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    lua_pushinteger(L, daku_fx_rotateby(arg1, arg2));
    return 1;
}

static int tolua__skew_to(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    lua_pushinteger(L, daku_fx_skewto(arg1, arg2, arg3));
    return 1;
}

static int tolua__skew_by(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    lua_pushinteger(L, daku_fx_skewby(arg1, arg2, arg3));
    return 1;
}

static int tolua__flip_x(lua_State *L) {
    lua_pushinteger(L, daku_fx_flip_x());
    return 1;
}

static int tolua__flip_y(lua_State *L) {
    lua_pushinteger(L, daku_fx_flip_y());
    return 1;
}

static int tolua__freeze(lua_State *L) {
    lua_pushinteger(L, daku_fx_freeze());
    return 1;
}

static int tolua__thaw(lua_State *L) {
    lua_pushinteger(L, daku_fx_thaw());
    return 1;
}

static int tolua__transition_erase_l(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    int arg2 = luaL_checkinteger(L, 2);
    lua_pushinteger(L, daku_tr_erase_l(arg1, arg2));
    return 1;
}

static int tolua__transition_erase_circle(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    int arg2 = luaL_checkinteger(L, 2);
    lua_pushinteger(L, daku_tr_erase_circle(arg1, arg2));
    return 1;
}

static int tolua__reverse_w(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    lua_pushinteger(L, daku_audio_reverse(arg1));
    return 1;
}

static int tolua__video_clip(lua_State *L) {
    char* arg1 = luaL_checkstring(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    lua_pushinteger(L, daku_video_clip(arg1, arg2, arg3));
    return 1;
}

static int tolua__image_clip(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    char* arg2 = luaL_checkstring(L, 2);
    lua_pushinteger(L, daku_image_clip(arg1, arg2));
    return 1;
}

static int tolua__audio_clip(lua_State *L) {
    char* arg1 = luaL_checkstring(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    float arg3 = luaL_checknumber(L, 3);
    lua_pushinteger(L, daku_audio_clip(arg1, arg2, arg3));
    return 1;
}

static int tolua__text_clip(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    char* arg2 = luaL_checkstring(L, 2);
    char* arg3 = luaL_checkstring(L, 3);
    int arg4 = luaL_checkinteger(L, 4);
    int arg5 = luaL_checkinteger(L, 5);
    int arg6 = luaL_checkinteger(L, 6);
    int arg7 = luaL_checkinteger(L, 7);
    lua_pushinteger(L, daku_text(arg1, arg2, arg3, arg4, arg5, arg6, arg7));
    return 1;
}

static int tolua__shape(lua_State *L) {
    float arg1 = luaL_checknumber(L, 1);
    int arg2 = luaL_checkinteger(L, 2);
    int arg3 = luaL_checkinteger(L, 3);
    int arg4 = luaL_checkinteger(L, 4);
    lua_pushinteger(L, daku_shape(arg1, arg2, arg3, arg4));
    return 1;
}

static int tolua__ease_sine_in(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_sine_in(arg1));
    return 1;
}

static int tolua__ease_sine_out(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_sine_out(arg1));
    return 1;
}

static int tolua__ease_sine_inout(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_sine_inout(arg1));
    return 1;
}

static int tolua__ease_quad_in(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_quad_in(arg1));
    return 1;
}

static int tolua__ease_quad_out(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_quad_out(arg1));
    return 1;
}

static int tolua__ease_quad_inout(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_quad_inout(arg1));
    return 1;
}

static int tolua__ease_cubic_in(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_cubic_in(arg1));
    return 1;
}

static int tolua__ease_cubic_out(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_cubic_out(arg1));
    return 1;
}

static int tolua__ease_cubic_inout(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_cubic_inout(arg1));
    return 1;
}

static int tolua__ease_quart_in(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_quart_in(arg1));
    return 1;
}

static int tolua__ease_quart_out(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_quart_out(arg1));
    return 1;
}

static int tolua__ease_quart_inout(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_quart_inout(arg1));
    return 1;
}

static int tolua__ease_quint_in(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_quint_in(arg1));
    return 1;
}

static int tolua__ease_quint_out(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_quint_out(arg1));
    return 1;
}

static int tolua__ease_quint_inout(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_quint_inout(arg1));
    return 1;
}

static int tolua__ease_circ_in(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_circ_in(arg1));
    return 1;
}

static int tolua__ease_circ_out(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_circ_out(arg1));
    return 1;
}

static int tolua__ease_circ_inout(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    lua_pushinteger(L, daku_ease_circ_inout(arg1));
    return 1;
}

static int tolua__ease_time_scale(lua_State *L) {
    daku_action* arg1 = luaL_checkinteger(L, 1);
    float arg2 = luaL_checknumber(L, 2);
    lua_pushinteger(L, daku_ease_time_scale(arg1, arg2));
    return 1;
}

void register_actions(lua_State *L) {
    lua_pushcfunction(L, tolua__move_by);
    lua_setglobal(L, "move_by");
    lua_pushcfunction(L, tolua__move_to);
    lua_setglobal(L, "move_to");
    lua_pushcfunction(L, tolua__fade_to);
    lua_setglobal(L, "fade_to");
    lua_pushcfunction(L, tolua__fade_in);
    lua_setglobal(L, "fade_in");
    lua_pushcfunction(L, tolua__fade_out);
    lua_setglobal(L, "fade_out");
    lua_pushcfunction(L, tolua__scale_to);
    lua_setglobal(L, "scale_to");
    lua_pushcfunction(L, tolua__scale_by);
    lua_setglobal(L, "scale_by");
    lua_pushcfunction(L, tolua__zoom_to);
    lua_setglobal(L, "zoom_to");
    lua_pushcfunction(L, tolua__zoom_by);
    lua_setglobal(L, "zoom_by");
    lua_pushcfunction(L, tolua__rotate_to);
    lua_setglobal(L, "rotate_to");
    lua_pushcfunction(L, tolua__rotate_by);
    lua_setglobal(L, "rotate_by");
    lua_pushcfunction(L, tolua__skew_to);
    lua_setglobal(L, "skew_to");
    lua_pushcfunction(L, tolua__skew_by);
    lua_setglobal(L, "skew_by");
    lua_pushcfunction(L, tolua__flip_x);
    lua_setglobal(L, "flip_x");
    lua_pushcfunction(L, tolua__flip_y);
    lua_setglobal(L, "flip_y");
    lua_pushcfunction(L, tolua__freeze);
    lua_setglobal(L, "freeze");
    lua_pushcfunction(L, tolua__thaw);
    lua_setglobal(L, "thaw");
    lua_pushcfunction(L, tolua__transition_erase_l);
    lua_setglobal(L, "transition_erase_l");
    lua_pushcfunction(L, tolua__transition_erase_circle);
    lua_setglobal(L, "transition_erase_circle");
    lua_pushcfunction(L, tolua__reverse_w);
    lua_setglobal(L, "reverse_w");
    lua_pushcfunction(L, tolua__video_clip);
    lua_setglobal(L, "video_clip");
    lua_pushcfunction(L, tolua__image_clip);
    lua_setglobal(L, "image_clip");
    lua_pushcfunction(L, tolua__audio_clip);
    lua_setglobal(L, "audio_clip");
    lua_pushcfunction(L, tolua__text_clip);
    lua_setglobal(L, "text_clip");
    lua_pushcfunction(L, tolua__shape);
    lua_setglobal(L, "shape");
    lua_pushcfunction(L, tolua__ease_sine_in);
    lua_setglobal(L, "ease_sine_in");
    lua_pushcfunction(L, tolua__ease_sine_out);
    lua_setglobal(L, "ease_sine_out");
    lua_pushcfunction(L, tolua__ease_sine_inout);
    lua_setglobal(L, "ease_sine_inout");
    lua_pushcfunction(L, tolua__ease_quad_in);
    lua_setglobal(L, "ease_quad_in");
    lua_pushcfunction(L, tolua__ease_quad_out);
    lua_setglobal(L, "ease_quad_out");
    lua_pushcfunction(L, tolua__ease_quad_inout);
    lua_setglobal(L, "ease_quad_inout");
    lua_pushcfunction(L, tolua__ease_cubic_in);
    lua_setglobal(L, "ease_cubic_in");
    lua_pushcfunction(L, tolua__ease_cubic_out);
    lua_setglobal(L, "ease_cubic_out");
    lua_pushcfunction(L, tolua__ease_cubic_inout);
    lua_setglobal(L, "ease_cubic_inout");
    lua_pushcfunction(L, tolua__ease_quart_in);
    lua_setglobal(L, "ease_quart_in");
    lua_pushcfunction(L, tolua__ease_quart_out);
    lua_setglobal(L, "ease_quart_out");
    lua_pushcfunction(L, tolua__ease_quart_inout);
    lua_setglobal(L, "ease_quart_inout");
    lua_pushcfunction(L, tolua__ease_quint_in);
    lua_setglobal(L, "ease_quint_in");
    lua_pushcfunction(L, tolua__ease_quint_out);
    lua_setglobal(L, "ease_quint_out");
    lua_pushcfunction(L, tolua__ease_quint_inout);
    lua_setglobal(L, "ease_quint_inout");
    lua_pushcfunction(L, tolua__ease_circ_in);
    lua_setglobal(L, "ease_circ_in");
    lua_pushcfunction(L, tolua__ease_circ_out);
    lua_setglobal(L, "ease_circ_out");
    lua_pushcfunction(L, tolua__ease_circ_inout);
    lua_setglobal(L, "ease_circ_inout");
    lua_pushcfunction(L, tolua__ease_time_scale);
    lua_setglobal(L, "ease_time_scale");
}
