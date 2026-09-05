#include "/players/llew/closed/ansi.h"

short() { return "The Obituary Notice"; }
long() { 
   write("A large stone rests firmly in the ground, listing the most\n"+
         "recent deaths.  Perhaps you should read it.\n");
}

id(str) {
   return str == "notice" || str == "obituary notice" || str == "obituary";
}

init() {
   add_action("read","read");
}

read(str) {
   if(!str || !id(str)) {
      notify_fail("Read what?\n");
      return 0;
   }
   call_other("/players/llew/Other/misc/deathlog","deathlog",0);
   write(pad("",22)+BOLD+"Obituary Notice"+NORM+"\n\n");
   write("     Player        Time                     Killed by\n");
   write("\n");
   tail("/players/llew/Other/misc/deathlog");
   write("\n");
   write("Level scale:  "+GRN+"Low "+HIY+"Mid "+NORM+RED+"High "+BOLD+"Great\n"+NORM);
   write(BOLD + "*" + NORM + " - Killed by Sparring.\n");
   say(this_player()->query_name()+" reads the obituary notice.\n");
   return 1;
}

