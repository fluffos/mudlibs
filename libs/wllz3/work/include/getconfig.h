// getconfig.h read configuration in /adm/etc

#ifndef _GETCONFIG_H_
#define _GETCONFIG_H_

#include "runtime_config.h"

#define code_name()        ((string) get_config(__MUD_NAME__))

#endif
