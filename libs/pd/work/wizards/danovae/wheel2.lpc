
#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("broken wheel");
   set_id( ({ "wheel","broken wheel" }) );
   set_short("Wheel of Fortune (Broken)");
   set_long(
     "A wheel with many pictures carved into it. It appears to be jammed and will not spin. "
   );
   set_mass(1000);
   set_value(0);
   set_prevent_get("The wheel is far too large to lift.");
}

void init() {
   ::init();
   add_action("spin","spin");
}

int spin(string str) {
   if(str != "wheel")
   { return notify_fail("Spin what?\n"); }
   write("The wheel is jammed and will not spin.\n");
   return 1;
}



