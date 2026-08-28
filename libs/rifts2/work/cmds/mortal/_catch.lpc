//      /cmds/mortal/_catch.c
//      Catch cmd so players don't die to stealin thieves
//       ++Drizzt 4/14/96

#include <std.h>

inherit DAEMON;

int cmd_catch(string str) {

       if(!str) {
       write("Your catch is "+(string)this_player()->query_catch() +"\n");
       return 1;
        }
       if(str == "on" || str == "off") { 
          this_player()->set_catch(str);    
          write("Your catch is now "+str+".\n");
         return 1;	
        }
}

void help() {
    write("Syntax: catch <on or off>\n\n"
       "If you turn your catch on you will attack a thief if you catch\n"
    "em stealing from you.  If it is off... you will not attack the thief.\n"
    "catch with no args will tell you if it is on or off.\n");
}
