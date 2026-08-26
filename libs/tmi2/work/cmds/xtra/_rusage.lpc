// _rusage.c: coded by Truilkan@TMI, 1992/08/06
// Help added by Mobydick@TMI, 11-21-92. BEAT CAL!

#include <mudlib.h>

inherit DAEMON ;

void write_rusage(mapping r, string header, string key)
{
        printf("%-35s %9d\n",header, r[key]);
}

int cmd_rusage()
{
    mapping r;

    r = rusage();
    write_rusage(r, "user time used", "utime");
    write_rusage(r, "system time used", "stime");
    write_rusage(r, "maximum shared text memory size", "maxrss");
    write_rusage(r, "integral shared text memory size", "ixrss");
    write_rusage(r, "integral unshared data size", "idrss");
    write_rusage(r, "integral unshared stack size", "isrss");
    write_rusage(r, "page reclaims", "minflt");
    write_rusage(r, "page faults", "majflt");
    write_rusage(r, "swaps", "nswap");
    write_rusage(r, "block input operations", "inblock");
    write_rusage(r, "block output operations", "oublock");
    write_rusage(r, "messages sent", "msgsnd");
    write_rusage(r, "messages received", "msgrcv");
    write_rusage(r, "signals received", "nsignals");
    write_rusage(r, "voluntary context switches", "nvcsw");
    write_rusage(r, "involuntary context switches", "nivcsw");
    return 1;
}

int help() {
	write ("Usage: rusage\n\n"+
"The rusage command gives data on how the CPU and memory are being used.\n") ;
	return 1 ;
}
