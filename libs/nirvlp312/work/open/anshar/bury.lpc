#include "/players/anshar/closed/ansi.h"
#include "/players/anshar/closed/mydef.h"

bury(str) {
   int X;
   int Y;
   object who;
   who=this_player()->query_name();
   if(!str || str != "corpse") {
     write("Bury what?\n");
     return 1; }
   if(!present("corpse", ENV(TP))) {
     write("There is no corpse here to bury.\n");
     return 1; }
   X = (present("corpse", ENV(TP))->heal_value());
   if(!X) {
     notify_fail("There is no sustenance to be had from that corpse.\n");
     return 1; }
   Y = (this_player()->query_attrib("wil"));
   if((random(20))< Y) {
     X = (X*Y/20);
     this_player()->heal_self(X);
     write("You bury the corpse, sucking the life eneries from it.\n");
     say(who+" sucks the life energies from the corpse and buries it.\n");
     destruct(present("corpse", ENV(TP)));
     return 1; }
}
