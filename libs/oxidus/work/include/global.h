#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <clean_up.h>
#include <colour.h>
#include <daemons.h>
#include <gmcp_defines.h>
#include <input.h>
#include <inventory.h>
#include <lib.h>
#include <messaging.h>
#include <ext.h>
#include <handlers.h>
#include <modules.h>
#include <move.h>
#include <mudlib.h>
#include <objects.h>
#include <promise.h>
#include <rooms.h>
#include <runtime_config.h>
#include <signal.h>
#include <driver/type.h>
#include <custom_type.h>
#include <etc.h>

#define SIMUL_OB     "/adm/obj/simul_efun"
#define LOGIN_OB     "/adm/obj/login"

#define true 1
#define false 0
#define null ([])[0]
#define nullzilla ([])[0]
#define undefined ([])[0]

#define DATE "%F"
#define TIME "%T"
#define DATE_TIME "%F %T"

#define NONAME "noname"

#endif // __GLOBAL_H__
