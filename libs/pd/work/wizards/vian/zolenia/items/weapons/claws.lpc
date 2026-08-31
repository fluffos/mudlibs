#include <std.h>
#include <zolenia.h>
inherit WEAPON;

void create() {
::create();
    set_name("claws");
    set_short("%^RESET%^%^BOLD%^crystalline%^RESET%^ claws");
    set_long("These claws are pure crystal, and very sharp looking.  They are long and thin, a great blade.");
    set_id(({"claws", "crystalline claws"}));
    set_weight(2);
    set_type("blade");
    set_wc(12);
    set_ac(1);
    set_curr_value("gold", 80);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
