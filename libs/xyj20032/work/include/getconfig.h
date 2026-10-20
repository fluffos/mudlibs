// getconfig.h read configuration in /adm/etc

#ifndef _GETCONFIG_H_
#define _GETCONFIG_H_

#include "runtime_config.h"

#define LOCAL_MUD_NAME()        ((string) get_config(__MUD_NAME__))
#define LOCAL_PORT()            __PORT__

#endif

