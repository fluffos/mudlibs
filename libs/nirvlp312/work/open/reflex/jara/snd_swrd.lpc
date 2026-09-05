#include "/players/reflex/lib/lib.h"
#include "/players/reflex/lib/include/ansi.h"
inherit WEAPON;

void create() {
    ::create();

    set_name("sword");
    set_ids(({ "sand sword", }));
    set_short(BOLD+"Sword of Sand"+NORM);
    set_long(
	"This sand sword looks like it`s made of many particles of\n"+
	"sand.  Upon further examination, you see that at certain\n"+
	"times the particles seem to arrange themselves into five\n"+
	"separate swords.\n"
        );
    set_value(3250);
    set_weight(4);
    set_type("sharp");
    set_class(16);
    set_durability(1000);
    set_fragility(3);
    set_reparable(3);
    set_hit_func(this_object());
    set_hands(2);
    set_message_hit(({
        "devestated",
        " with a viscious "+RED+"slash"+NORM+" across the body, severly"+
	" mangling it",
        "pierced",
        " through the body",
        "slashed",
        " deeply across the stomach",
        "sliced",
        " across the chest",
        "jabbed",
        " in the stomach",
        "cut",
        " in the side",
        "nicked",
        " slightly",
        }));
}

mixed weapon_hit(object victim) {
    object master;
    
    master = query_wielded_by();
    if ((string) victim->query_race() == "water") {
        tell_object(master, "Your blade disperses as it strikes your"+
			     "target...\n");
        return "miss";
    }

    if (random(100) < 33) {
        tell_object(master, 
	"The Sword of Sand scatters into five of itself and\n"+
	"plunges "+RED+"deeply"+NORM+" into your opponents heart!!\n"+
	"Dark "+RED+"BLOOD"+NORM+" spurts all over you...\n"
        );
        tell_object(victim,
	"The Sword of Sand suddenly becomes five of itself and\n"+
	"plunges "+RED+"deeply"+NORM+" into your heart!!\n"+
	"Dark "+RED+"BLOOD"+NORM+" spurts all over you...\n",
        );
        say(master->query_name() + 
        "'s Sword of Sand scatters into five blades!\n"+
        "The blades plunge "+RED+"deeply"+NORM+" into the heart of their"+
	"\nopponent...\n"+
	"Dark "+RED+"BLOOD"+NORM+" spurts out in a thick stream...\n",
            victim);
        return 2;
    }
}
