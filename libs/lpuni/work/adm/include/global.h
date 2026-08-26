//global.h

//Tacitus @ LPUniversity
//02-APR-05
//LPUniversity

//Last updated: October 9th, 2006 by Tacitus

#include <mudlib.h>
#include <ansi.h>

#define LIB_VERSION "A-0610-R7"

#define SIMUL_DIR  "/adm/simul_efun/"
#define SIMUL_OB   "/adm/obj/simul_efun"
#define LOGIN_OB   "/adm/obj/login"
#define USER_OB    "/std/user/user"
#define VOID_OB    "/areas/std/void"

#ifdef __SENSIBLE_MODIFIERS__
#define staticf protected
#define staticv nosave
#else
#define staticf nosave
#define staticv nosave
#endif

#ifndef __CONFIG_H__
#define __CONFIG_H__
#endif
