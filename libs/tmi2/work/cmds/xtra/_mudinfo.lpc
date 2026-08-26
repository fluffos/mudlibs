//      File    :  /cmds/xtra/_mudinfo.c
//      Creator :  Inspiral@Tabor  (5/93)
//
//      Integrated into the TMI-2 mudlib by Watcher@TMI-2 (5/93)
//
//      This file displays the current status of the mud and its driver.
//      Drizzt@Team-Aye made it so this uses the I3 Mudlist for 
//              Listing other muds 'infos'
 
#include <config.h>
#include <mudlib.h>
#include <commands.h>
#include <daemons.h>
 
inherit DAEMON;
 
#define PAD             48
#define STATUS          "Mudlib Development"
#define SCALE           (1.0/10.0)
#define pad(x,y)        sprintf("%-" + y + "s", x)
 
string do_info(string args);
 
int cmd_mudinfo(string args) {  
    write("\n" + do_info(args) + "\n");  
    return 1;  
}
 
string do_info(string args) {
   mapping r;
   float cpu;
   string mach, vers, name, up, memory, listing;
   int obs, i;
   mixed *info, *services;
   
   if(args && args != ""){
       args = I3_D->query_network_name(args);
       if(!args){
           return("Could not obtain information about that MUD\n");
       }                
       info = I3_D->query_mud(args);
       services = keys(info[10]);
       listing = "";
       for(i=0;i<sizeof(services);i++)
           listing += services[i]+", ";
       listing += "\n";
       return ( "" +
           pad( "MUD NAME:         " + args, PAD ) +
           "MUDLIB:   " + info[5] + "\n" +
           pad( "ADDRESS:          " + info[1] + " " + info[2], PAD ) +
           "DRIVER:   " + info[7] + "\n" +
           pad("MUD TYPE:         " + info[8], PAD ) +
           "CPU USE:  " + "Unknown" + " %\n" +
           pad("CURRENT USERS:    " + "Unknown", PAD ) +
           "MEMORY:   " + "Unknown" + "\n" +
           pad("MUD STATUS:       " + info[9], PAD ) +
           "OBJECTS:  " + "Unknown\n" +
           pad("SERVICES:         " + listing, PAD) +
       "" );
    }               
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
   write("Syntax: mudinfo [mud]\n\n" +
     "This command displays the current status of the mud and its driver.\n"+
     "When passed with a MUD argument, it contains the statistics for that MUD\n");
   return 1; 
}
