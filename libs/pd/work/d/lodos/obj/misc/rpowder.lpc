#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("powder");
   set_id(({ "powder", "red powder" }));
   set_short("%^RESET%^%^RED%^re%^BOLD%^d pow%^RESET%^%^RED%^der%^RESET%^");
   set_long("The coarse red powder can be inhaled or smoked. Though you cannot "
     "distinguish what it was made from simply by looking at it, you can't help "
     "but wonder if it is the red powder or the small ammount of black dust in "
     "the powder that is the source of the powder's effect.");
   set_weight(1);
   set_value(0);
}

void smoke_me(object o) {
   if (!o) return;
   message("smoke", "Smoke fills your lungs, you coughs violently.", o);
   say("smoking", o->query_cap_name()+" takes a hit of red powder and coughs "
     "violently.", o);
   o->add_hp(random(33));
}

int can_smoke() { return 1; }
