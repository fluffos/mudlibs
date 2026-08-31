#include <std.h>

inherit PERIODIC_ROOM;

void create() {
    ::create();
    set_period(8);
}

int periodic() {
    object to = this_object();
    object *all = filter(all_inventory(to), (: $1->is_living() :) );

    if (!sizeof(all)) return 0;

    if (random(100) < 45) {
	foreach (object who in all) {
	    if (random(100) < 45) {
		message("info", "%^BOLD%^%^BLACK%^A %^YELLOW%^rogue %^RESET%^%^MAGENTA%^li%^BOLD%^%^WHITE%^gh%^YELLOW%^tn%^BLACK%^in%^RESET%^%^RED%^g b%^BOLD%^%^RED%^ol%^BLACK%^t strikes from under the %^WHITE%^clouds%^BLACK%^, hitting your body so %^RED%^hard %^BLACK%^you begin to sm%^WHITE%^o%^BLACK%^ke.%^RESET%^", who);
		message("info", "%^BOLD%^%^BLACK%^A rogue %^RESET%^%^MAGENTA%^li%^BOLD%^%^WHITE%^gh%^YELLOW%^tn%^BLACK%^in%^RESET%^%^RED%^g b%^BOLD%^%^RED%^ol%^BLACK%^t strikes%^RED%^ "+who->query_cap_name()+"%^BLACK%^!%^RESET%^", to, who);
		who->add_hp(-(50+random(50)));
		who->add_sp(-50);
		who->add_mp(-50);
		who->show_status_line();
	    }
	}
    }
    else if (random(100) < 20) {
	message("info", "%^BOLD%^%^BLACK%^A %^RED%^LOUD %^BLACK%^crack of thunder shakes the area, causing everything to shake with %^RED%^fear%^BLACK%^.%^RESET%^", to);
	foreach (object who in all) {
	    if (random(100) < 35) {
		message("info", "%^BOLD%^%^BLACK%^You are paralyzed with %^RED%^fear%^BLACK%^!%^RESET%^", who);
		who->set_paralyzed(5, "You are too frightened to move.");
		who->add_hp(-(25+random(25)));
		who->add_sp(-25);
		who->add_mp(-25);
		who->show_status_line();
	    }
	}
    }

    return (sizeof(filter(all, (: ($1 && $1->is_player()) :) )) ? 1 : 0);
}
