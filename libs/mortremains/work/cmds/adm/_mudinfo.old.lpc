 
//	File	:  /cmds/xtra/_mudinfo.c
//	Creator	:  Inspiral@Tabor  (5/93)
//
//	Integrated into the TMI-2 mudlib by Watcher@TMI-2 (5/93)
//
//	This file displays the current status of the mud and its driver.
 
#include <config.h>
#include <mudlib.h>
#include <commands.h>

inherit DAEMON;
 
#define PAD 		48
#define STATUS		"Mudlib Development"
#define SCALE		(1.0/10.0)
#define pad(x,y)	sprintf("%-" + y + "s", x)

string do_info();

int cmd_mudinfo() {  write("\n" + do_info() + "\n");  return 1;  }

string do_info() {
   mapping r;
   float cpu;
   string mach, vers, name, up;
    int obs ;
    string memory ;
   
   r = rusage();
   obs = sizeof( objects() );
   mach = arch();
   name = capitalize( mud_name() );
   vers = version();
   cpu = SCALE * (r["utime"] + r["stime"]) / uptime();
   
   memory = (string) CMD_MEM -> parse_mem( memory_info() );
   up = format_time( uptime() );
   
   return ( "" +
	pad( "MUD NAME:         " + name, PAD ) +
      "MUDLIB:   " + MUDLIB_NAME + " (" + MUDLIB_VERSION_NUMBER + ")\n" +
	pad( "ARCHITECTURE:     " + mach, PAD ) +
      "DRIVER:   " + vers + "\n" +
  pad("DRIVER UPTIME:    " + up, PAD ) +
           "CPU USE:  " + cpu + " %\n" +
  pad("CURRENT USERS:    " + sizeof( users() ), PAD ) +
      "MEMORY:   " + memory + "\n" +
  pad("MUD STATUS:       " + STATUS, PAD ) +
	"OBJECTS:  " + obs + " loaded.\n" +
      "" );
}
 
int help() {

   write("Syntax: mudinfo\n\n" +
     "This command displays the current status of the mud and its driver.\n");
 
return 1; }
 
