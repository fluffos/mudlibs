//global.h

//Global Include File

//Tacitus @ Tmi-3
//02-APR-05
//Tmi-3 Macro File

//Last updated: May 16th, 2005 by Tacitus

#define OBJECT     "/std/object.lpc"
#define CLEAN_UP   "/std/clean_up.lpc"
#define OB_E       "/std/ob_prop.lpc"
#define ROOM       "/std/room.lpc"


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





