#include <std.h>
#include <move.h>
inherit ARMOUR;
inherit CONTAINER;

int get_it(string str);
int conceal(string str);
string query_long();

string query_long() {
   string str;
   object *all;
   int i;
   str = "The long blue trenchcoat is laced with iron strips. "
     "It is large enough that you could conceal something in it.\n";
   all = all_inventory(this_object());
   i = sizeof(all);
   if (!i) return str+"It has nothing concealed in it.";
   str += "Concealed within the coat is:\n";
   while (i--) {
     str += all[i]->query_short()+"\n";
   }
   return str;
}

void create() {
 armour::create();
 container::create();
   set_name("coat");
   set_property("no steal", 1);
    set_short("%^BLUE%^a%^BOLD%^ b%^WHITE%^l%^BLUE%^u%^RESET%^%^BLUE%^e %^BOLD%^t%^WHITE%^r%^BLUE%^e%^RESET%^%^BLUE%^n%^BOLD%^c%^WHITE%^h %^BLUE%^c%^RESET%^%^BLUE%^o%^BOLD%^a%^WHITE%^t");

   set_long("The long white coat is laced with iron strips. "
       "It is large enough that you could conceal something in it.");
   set_weight(1);
   set_id(({ "trench", "coat", "blue trenchcoat", "trenchcoat" }));
   set_type("coat");
   set_limbs(({"head", "torso", "left arm", "right arm", "left leg",
       "right leg" }));
   set_ac(9);
   set_max_internal_encumbrance(1000000);
   set_possible_to_close(0);
}

int query_auto_load() { return 1; }

int conceal(string str) {
   string obj;
   int i;
   object ob, *all;
   if (!str) return 0;
   if (!sscanf(str, "%s", obj))
      return notify_fail("Syntax: <conceal [object]>\n");
   ob = present(obj, this_player());
   if (!ob)
      return notify_fail("You are not holding that.\n");
   all = all_inventory(this_object());
   i = sizeof(all);
   if (i)
     return notify_fail("You may only conceal one item at a time.\n");
   ob->move(this_object());
   write("You conceal the "+ob->query_name()+" in the coat.");
   return 1;
}

int get_it(string str) {
   string obj;
   object ob;
   if (!str)
      return notify_fail("Syntax: <get [object] from coat>\n");
   if (!sscanf(str, "%s from coat", obj))
      return notify_fail("Syntax: <get [object] from coat>\n");
   ob = present(obj, this_object());
   if (!ob)
      return notify_fail("That has not been concealed.\n");
   ob->move(this_player());
   write("You take "+ob->query_name()+" from the coat.");
   return 1;
}
void init() {
 ::init();
   add_action("conceal", "conceal");
   add_action("get_it", "get");
}
