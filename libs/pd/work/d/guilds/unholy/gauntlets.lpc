#include <std.h>

inherit ARMOUR;

void fix_limbs(string race);
int move(mixed dest);
void create() {
    ::create();
    set_name("Bloodied Gauntlets of Asmodeus");
    set_id(({"gauntlets","bloodied gauntlets","gauntlets of asmodeus","bloodied gauntlets of asmodeus"}));
    set_short("%^RED%^Bloodied%^RESET%^ Gauntlets of %^BOLD%^%^BLACK%^Asmodeus%^RESET%^");
    set_long("These spiked gauntlets are caked with dried blood from many bloodlettings. "
      "They're made of a very light and strong metal, and molded to perfectly fit "
      "the hands of the wearer. The symbol of Asmodeus, the ram's skull within a "
      "pentagram, is engraved upon the back of the hands.");
    set_ac(0);
    set_type("gloves");
    set_limbs(({"left hand","right hand"}));
    set_weight(3);
    set_curr_value("gold",100);
}

int query_auto_load() {

    if (living(environment()) && environment()->query_guild() == "unholy")
	return 1;
}

void fix_limbs(string race) {
    switch (race) {
    case "raknid":
	set_limbs(({"first hand","second hand","third hand","fourth hand"}));
	break;
    case "bastet":
	set_limbs(({"left paw","right paw"}));
	break;
    default:
	set_limbs(({"left hand","right hand"}));
    }
}

int move(mixed dest) {
    int r=::move(dest);
    if (!r && objectp(dest) && living(dest))
	fix_limbs(dest->query_race());
    return r;
}
