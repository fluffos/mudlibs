// profile daemon
// if you turn on a compile option in config.h, it'll call the log_cmd
// function in this daemon. That function logs each user's command and
// the time taken thereby. It thus provides a record of how much times
// is being taken by each command in the lib, providing hints for people
// interested in optimizing performance.
// Hacked on by Mobydick starting 8-15-93.

#include <mudlib.h>

inherit DAEMON ;

#define MAX_CMDS 500
#define OUTPUT_FILE "/CMD_DUMP"
mapping calls, systime, usertime ;
string *cmds ;

void create() {
	::create() ;
	calls = allocate_mapping(MAX_CMDS) ;
	systime = allocate_mapping(MAX_CMDS) ;
	usertime = allocate_mapping(MAX_CMDS) ;
}

void log_cmd (string cmd, mapping before, mapping after) {
	systime[cmd] += after["stime"] - before["stime"] ;
	usertime[cmd] += after["utime"] - before["utime"] ;
	calls[cmd] += 1 ;
}

int dump_data() {

	int i ;
	float avgsys, avguser ;

    rm (OUTPUT_FILE) ;
    write_file(OUTPUT_FILE,"Command         Calls    SysTime   UserTime   Avg. Sys   Avg. User\n") ;
    cmds = keys(systime) ;
    cmds = sort_array(cmds,"sort_cmds",this_object()) ;
    for (i=0;i<sizeof(systime);i++) {
	avgsys = systime[cmds[i]]/calls[cmds[i]] ;
	avguser = usertime[cmds[i]]/calls[cmds[i]] ;
	write_file(OUTPUT_FILE,sprintf("%8-s %10d %10d %10d %10O %10O\n",cmds[i],calls[cmds[i]],systime[cmds[i]],usertime[cmds[i]],avgsys,avguser)) ;
    }
    write ("List dumped to "+OUTPUT_FILE+".\n") ;
   return 1 ;
}

int sort_cmds (string cmd1, string cmd2) {
	return (systime[cmd2]-systime[cmd1]) ;
}
