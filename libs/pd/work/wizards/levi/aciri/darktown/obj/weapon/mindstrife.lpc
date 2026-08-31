#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("mindstrife");
   set_short("%^RESET%^%^%^CYAN%^M%^BOLD%^ind%^RESET%^%^CYAN%^S%^BOLD%^trife%^RESET%^");
   set_long("The weapon long used by the Rulers of Aciri, Mindstrife is "
     "a weapon of the mystics. It has been called \"The Mindblade\" by many, "
     "but those with true power in magic nicknamed it MindStrife. Mindstrife "
     "is a half-corporal blade, it's power is drawn from the magical abilities "
     "of it's wielder. Its shape is a ever moving mist of blades.");
   set_weight(25);
   set_id(({ "mindstrife" }));
   set_type("magic attack");
   set_value(735);
   set_hands(2);
}

int query_wc() {
   int x;
   x = environment(this_object())->query_skill("magic attack")/10;
   if (x >= 14) x = 14;
   if (x <= 0) x = 0;
   return 7+x;
}

int query_auto_load() { if (this_player()->query_level() >= 24) return 3; }

