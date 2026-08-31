#include <std.h>
inherit OBJECT;

int fuel;

string query_short() {
   if (!fuel) return "can of fuel (empty)";
   else return ::query_short();
}

string query_long(string str) {
   if (!fuel) return "The can is used to hold fuel to refill lanterns, though "
     "it is empty at the moment.";
   else return ::query_long(str);
}

void create() {
 ::create();
   set_name("fuel");
   set_short("can of fuel");
   set_long("The can of fuel can be used to put more fuel into "
     "lanterns, so they can be reused. Simply <fill lantern>.");
   set_id(({ "fuel", "can", "can of fuel" }));
   set_weight(2);
    set_curr_value("gold", 15);
   fuel = 1900;
}

int fill(string str) {
   object ob;
   int i, max, now;

   if (!str) return 0;
   if (!(ob = present(str, this_player()))) return
     notify_fail("You do not have that.\n");
   if (!ob->is_light() || !ob->query_fill()) return notify_fail(
     "You cannot fill that up.\n");
   if (ob->query_fuel() >= ob->query_max_fuel()) return notify_fail(
     "It is already filled up.\n");
   max = ob->query_max_fuel();
   now = ob->query_fuel();
   i   = max - now;
   if (i >= fuel) { i = fuel; write("You pour the last of the fuel in the "
     "can into the "+ob->query_short()+"."); } else
     write("You fill the "+ob->query_short()+" with fuel.");
   fuel -= i;
   ob->add_fuel(i);
   say(this_player()->query_cap_name()+" pours fuel from a can into "
     +ob->query_short()+".", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("fill", "fill");
}
