#include <std.h>

inherit ARMOUR;

int change_race();

void create() {
  ::create();
  set_name("bloodied gauntlets of Asmodeus");
  set_id(({"gauntlets","bloodied gauntlets","gauntlets of asmodeus","bloodied gauntlets of asmodeus"}));
  set_short("%^RED%^bloodied%^RESET%^ gauntlets of %^BOLD%^%^BLACK%^Asmodeus%^RESET%^");
  set_long("These spiked gauntlets are caked with dried blood from many bloodlettings. "
           "They're made of a very light and strong metal, and molded to perfectly fit "
           "the hands of the wearer. The symbol of Asmodeus, the ram's skull within a "
           "pentagram, is engraved upon the back of the hands.");
  set_ac(0);
  set_type("gloves");
  set_limbs(({"left hand","right hand"}));
  set_weight(3);
  set_curr_value("gold",0);
}

int query_auto_load() {
  if (living(environment()) && environment()->query_guild() == "unholy")
    return 1;
}
