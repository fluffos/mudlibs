#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("platemail");
   set_short("%^BOLD%^%^BLACK%^Bla%^WHITE%^ck %^RESET%^%^WHITE%^Plat%^BOLD%^em%^BLACK%^ail%^RESET%^");
   set_long("This Shining Mail was Tarnished by the Fire of Hell.");
   set_weight(20);
   set_ac(14);
   set_value(0);
   set_limbs(({ "torso", "right arm", "left arm" }));
   set_id(({"platemail", "mail", "plate"}));
   set_type("armor");
}

int query_auto_load() { return 1; }

void make_death(object tp) {
   if (tp != environment(this_object())) return 0;
   write("%^RED%^The evil in your soul explodes, and your body can't handle it..");
   tp->die();
   this_object()->remove();
}

int check_anti(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_al_title() == "demonic") return 0;
   write("%^BOLD%^%^BLACK%^Evil grips your soul.");
   call_out("make_death", 10, this_player());
   return 1;
}

void init() {
 ::init();
   add_action("check_anti", "wear");
}
