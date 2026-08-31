/* global.h
 *
 * Tacitus @ LPUniversity
 * 02-APR-05
 * LPUniversity
 *
 */
 
#include <mudlib.h>
#include <ansi.h>

#define LIB_VERSION "Unreleased"
#define BASELIB_VERSION "Pre-Alpha"

#define SIMUL_DIR  "/adm/simul_efun/"
#define SIMUL_OB   "/adm/obj/simul_efun"
#define LOGIN_OB   "/adm/obj/login"
#define USER_OB    "/std/user/user"
#define VOID_OB    "/areas/std/void"

#ifdef __SENSIBLE_MODIFIERS__
#define privatef protected
#define privatev nosave

#define staticf protected
#define staticv nosave
#else
#define privatef nosave
#define privatev nosave

#define staticf nosave
#define staticv nosave

/* Just in-case someone really wants to use these */
#define protected private
#define nosave    nosave
#endif

#define UNDEFINED_VALUE ( ([ ])[0] )

#ifndef __CONFIG_H__
#define __CONFIG_H__
#endif
