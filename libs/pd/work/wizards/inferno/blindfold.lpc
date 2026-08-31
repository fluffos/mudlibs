#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("blindfold");
   set_short("a white blindfold");
   set_long("A blindfold that lets you see better. Just like the glasses that "
     "blind you..");
   set_ac(1);
   set_type("hat");
   set_id(({ "fold", "blindfold" }));
   set_limbs(({ "head" }));
}

void init() {
 ::init();
   add_action("check_look", "look");
}

int query_auto_load() { return 1; }

int check_look(string str) {
   object loc, *all;
   string tmp;
   int i;
   if (str && str != "") return 0;
   if (!this_object()->query_worn()) return 0;
   loc = environment(this_player());
   if ((tmp = loc->query_long()))
    write(tmp);
   if ((tmp = loc->query_smell("default")))
    write("%^RESET%^%^ORANGE%^"+tmp);
   if ((tmp = loc->query_listen("default")))
    write("%^RESET%^%^CYAN%^"+tmp);
   tmp = "%^GREEN%^"+loc->query_long_exits()+"%^RESET%^";
    write("\n"+tmp+"\n");
   if ((tmp = loc->describe_living_contents(({this_player()}))) != "")
    write(tmp);
   all = all_inventory(loc);
   i = sizeof(all);
   while(i--) {
     if (all[i] == this_player()) continue;
     if (all[i]->query_invis())
     write("%^BOLD%^%^BLACK%^("+capitalize(all[i]->query_name())+")%^RESET%^");
   }
   if ((tmp = loc->describe_item_contents(({}))) != "")
    write("\n"+tmp);
   return 1;
   return 1;
}
