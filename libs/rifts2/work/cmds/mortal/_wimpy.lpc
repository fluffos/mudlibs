//      /bin/user/_wimpy.c
//      from the Nightmare mudlib
//      for wimping out, easy to change to set specific percents
//      but I do not believe in that, so this just toggles on or off
//      created by Descartes of Borg 10 may 1993

#include <std.h>

inherit DAEMON;

int cmd_wimpy(string str) {
       int amt;
     if(!str) {
      write("Wimpy is at "+this_player()->query_wimpy() +" %\n");
       return 1;
        }
       sscanf(str, "%d", amt);	
       if((amt > 50) || (amt < 0)) {
         notify_fail("Syntax: wimpy 0-50\n");
         return 0;	
         }
       this_player()->set_wimpy(amt);
       write("You wimpy is set to "+amt+" percent.\n");
       return 1;
}

void help() {
    write("Syntax: wimpy <amt>\n\n"
        "Wimpy works by a variable percentage of your total hit points.\n"
        "When you get below that percentage you flee out of the room.\n"
        "You can set the percentage from 0-50% and also set the direction\n"
        "you flee.\n"
        "See also: wimpydir, kill\n"
    );
}
