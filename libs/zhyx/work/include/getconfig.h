// getconfig.h read configuration in /adm/etc

#ifndef _GETCONFIG_H_
#define _GETCONFIG_H_

#include "runtime_config.h"

#define RELEASE_SERVER()        ((string) CONFIG_D->query_string("release server"))
#define LOCAL_MUD_NAME()        ((string) get_config(__MUD_NAME__))
// A bare (int) cast does NOT perform a real runtime string->int
// conversion on this driver (it's compile-time-only type bookkeeping;
// get_config(__MUD_PORT__) itself doesn't come back as a plain int
// here) -- confirmed via a live runtime crash ("Bad argument 2 to
// socket_bind() Expected: int Got: \"10\"") the very first time
// messaged.lpc's startup_udp() called this macro. to_int() performs
// the actual coercion.
#define LOCAL_PORT()            (to_int(get_config(__MUD_PORT__)))

#endif
