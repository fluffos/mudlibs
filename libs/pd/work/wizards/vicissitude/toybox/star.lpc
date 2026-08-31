


#include <std.h>
#include <defs.h>

inherit OBJECT;

void create() {
   ::create();
   set_id( ({"star","shuriken"}) );
   set_name("shuriken");
   set_short("platinum shuriken");
   set_long(
     "A beautifully crafted platinum shuriken "
     "engraved with a sextet spiral trailing out to each point. "
   );
   set_weight(3);
   set_value(300);
}

void init() {
   ::init();
   add_action("throw","throw");
}

int throw(string str) {
   object ob;
   if(str != "shuriken")
   return notify_fail("Throw what?\n");
   if(TP->query_sp() < 30)
   return notify_fail("You don't have the strength to throw a shuriken.\n");
   write("You send the shuriken flying at your target.");
   say(TN+" throws a shuriken");
   TP->query_sp(-10);
   TO->remove();
return 1;
}








