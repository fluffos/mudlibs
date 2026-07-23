// filename : /include/mudlib.h

#ifndef __MUDLIB_H__
#define __MUDLIB_H__

//  The base distribution mudlib name.  

#define MUDLIB_NAME				"Xiao Ao Jiang Hu"
#define MUDLIB_VERSION_NUMBER	"0.9"
#define MUDLIB_VERSION			(MUDLIB_NAME + " " + MUDLIB_VERSION_NUMBER)

#define INTERMUD_MUD_NAME		"Xiao Ao"

#define mudlib() MUDLIB_NAME
//#define version() MUDLIB_VERSION_NUMBER
#define ADMIN_EMAIL "zhc@funny"
#define MUD_STATUS "Release"
#define SERVICES_D "/system/daemon/channeld"
#endif
