#define pad(x,y)  (sprintf( "%-" + y + "s", x ))

#include <mudlib.h>
inherit DAEMON;

int cmd_exits() {
   int loop;
   mapping exits;
   string short;
   
   exits = (mapping) environment(previous_object()) -> query("exits");
   
   if (!exits || !mapp(exits)) {
      notify_fail("There are no exits here, from what you can tell.\n");
      return 0;
   }
   
   write("Exits for " + bold(environment(previous_object()) -> 
         query("short")) + ":\n");
   
   for( loop = 0; loop < sizeof(keys(exits)); loop++ ) {
      if( catch(values(exits)[loop] -> XXX())) {
         if (wizardp(previous_object()))
            write("Unloadable room : " + identify(keys(exits)[loop]) +
            "\t-> " + identify(values(exits)[loop]) + "\n");
         continue;
       }
      write("  " + pad(capitalize(keys(exits)[loop]), 13) + ":   " +
         (string) values(exits)[loop] -> query("short") + "\n");
   }
   return 1;
}

string help() {
   string tmp = (
      "Syntax: exits\n\n"
      "This commands allows you to find the short description of the\n"
      "rooms adjacent to your current position.\n");
   if( wizardp( this_player() ) )
      tmp += "\nWizards will be notified by this command of rooms that\n"+
	"cannot be loaded through the use of this command.\n";
   tmp += "\nSee also: go, look, brief\n";
   return tmp;
}
