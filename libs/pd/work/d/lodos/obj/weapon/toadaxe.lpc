#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
    ::create();
    set_id(({"axe","toadaxe","toad"}));
    set_name("toadaxe");
    set_short("Toadaxe");
    set_long("The lower section axe consists of a dark shaft of blackened cedar wood, the lower quarter of which is wrapped in heavy leather to aid grip upon the weapon. The head of the axe consists of two curved blades, one on each side, each protruding perpendicular from the tip of the weapon and curving down to be parallel. The inside of each blade is heavily serrated, the points coming out to sharp tips. This weapon's origins are unknown, although it has been heavily enchanted to provide unusual effects during combat. Each axehead bears the engraved image of a toad.");
    set_value(500);
    set_weight(34);
    set_wc(8);
    set_hands(2);
    set_type("axe");
    set_hit( (: weapon_hit :) );
}

int weapon_hit(object atk) {
    int result;

    if(random(100) > 90) {
	write("You swing your axe in a wide arc, cleaving into "+atk->query_cap_name()+"'s side!");
	message("info",(string)this_player()->query_cap_name()+" swings his toadaxe in a wide arc, cleaving into your side!",atk);
	message("info",(string)this_player()->query_cap_name()+" swings his toadaxe in a wide arc, cleaving into "+atk->query_cap_name()+"'s side!",environment(this_player()),({atk, this_player()}));
	result = this_player()->query_mp()/15;
	result = (random(result))*((this_player()->query_level()/50)+2);
	result=random(result)+1;
	return result;
    }
    return 0;
}
int query_auto_load() { if (this_player()->query_level() >= 65) return 1; }
