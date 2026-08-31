#include <std.h>
inherit ROOM;
inherit "std/oi";

object thunder;   // This is a pointer to the thunder daemon
void create() {
 ::create();
   set_no_clean(1); // This makes sure the room variables aren't cleaned out
//   if (!thunder) {
//      thunder = (object)"/std/thunder";
//      thunder->enable_commands();
//      thunder->command("update /std/thunder",thunder);
//      thunder->disable_commands();
//   }
//    thunder->do_thunder();
   set_properties(([ "light" : 2, "indoors" : 1 ]));
   set_property("thunder", 1);
   set_short("Thunder room");
   set_long("Sit back and watch the storm!");
   set_exits(([ "out" : "/wizards/inferno/workroom" ]));
   set_items(([ "storm" : "Watch it! =]" ]));
}

