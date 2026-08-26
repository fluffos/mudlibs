#include <config.h>

//	File	:  /adm/simul_efun/system.c
//
//	This file contains simul_efuns used to account for driver efuns
//	that were made into system defines at MudOS 0.9.16+ release.

#ifdef __VERSION__
// new, as of 0.9.17.9

string version() { return __VERSION__; }
string arch() { return __ARCH__; }
#else
#ifdef MUDOS_VERSION
// this stuff appeared until 0.9.17.8 (inclusive)

string version() { return MUDOS_VERSION; }
string arch() { return MUDOS_ARCH; }
#else
#ifdef VERSION
// this stuff appeared briefly in one or two versions

string version() { return VERSION; }
string arch() { return ARCH; }
#endif // VERSION
#endif // MUDOS_VERSION
#endif // __VERSION__

#ifdef MUD_NAME
string mud_name() { return MUD_NAME; }
#endif

#ifdef __PORT__
int mud_port() { return __PORT__; }
#else
#ifdef MUD_PORT
int mud_port() { return MUD_PORT; }
#endif // MUD_PORT
#endif

// These are defined in config.h
string mudlib_name() 	{ return (MUDLIB_NAME); }
string mudlib_version()	{ return (MUDLIB_VERSION_NUMBER); }
