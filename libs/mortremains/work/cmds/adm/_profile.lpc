// _profile.c
// hacked on by Mobydick, 8-15-93
// Prints the command use data kept by the profile daemon.

#include <mudlib.h>
#include <config.h>

inherit DAEMON ;

int cmd_profile() {

#ifdef PROFILING
   "/adm/daemons/profile"->dump_data() ;
   return 1 ;
#else
    write ("Profiling is not currently enabled.\n") ;
    return 1 ;
#endif
}

string help() {
	return ("Usage: profile\n\n"+
"If PROFILING is #defined in config.h, and the mud is rebooted, then\n"+
"thereafter the daemon object /adm/daemons/profile.c keeps track of\n"+
"all commands entered by users, and the system and user time taken in\n"+
"executing them. The profile command writes this information to the\n"+
"file CMD_DUMP in the root directory where it can be examined, usually\n"+
"to find out what commands are in need of speed improvements.\n"+
"This option eats up a lot of CPU, so it's a wise idea to keep it turned\n"+
"off unless you need the information for some reason.\n"+
"") ;
}
