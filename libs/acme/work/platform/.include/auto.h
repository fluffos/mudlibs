#ifndef _PLATFORM_AUTO_H
#define _PLATFORM_AUTO_H

#pragma combine_strings
#pragma strong_types
#pragma save_types
#pragma verbose_errors
#pragma local_scopes
#pragma sloppy
#pragma no_range_check
#pragma warn_deprecated
#pragma warn_empty_casts
#pragma warn_missing_return
#pragma warn_function_inconsistent

#define AutoInclude          "auto.h"
#define TopLevelDomain       "acme"
#define WebClientTerm        "acme-web"

#define FlavorDir            "/flavor"
#define PlatformDir          "/platform"
#define SecureDir            "/secure"
#define UserDir              "/user"

#define _BinDir              "/.bin"
#define _EtcDir              "/.etc"
#define _IncludeDir          "/.include"
#define _LibDir              "/.lib"
#define _ModuleDir           "/.module"
#define _ObjDir              "/.obj"

#include "platform.h"

#define MasterObject         __MASTER_OBJECT__
#define SimulEfunObject      SecureDir "/simul_efun"

#define THISO                this_object()
#define THISP                this_player()
#define THISI                this_interactive()
#define FINDO(o)             find_object(o)
#define FINDP(p)             find_player(p)
#define PID                  THISP->query_primary_id()
#define CAP(s)               capitalize(s)
#define ENV(o)               environment(o)
#define UNAME                THISP->query_username()
#define PNAME                THISP->query_name()

#define MAXINT               0xf0000000
#define MININT               0xf0000001

#endif  // _PLATFORM_AUTO_H
