#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", -1);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set_property("no teleport", 1);
    set_short( "A chamber underneath the Daroq Mountains");
    set_long(
        "You are in a very dark chamber, illuminated only by your "
        "light source.");
    set_smell_string("default", "The stench of decay is all around.");
    set_items(
        (["light" : "What light?",
	  "tunnel" : "It is very dark.",
	  "chamber" : "You cannot see it very well."]) );
    set_exits( (["west" : "/domains/Praxis/mountains/tunnel2"]) );
}

void reset() {
    object arm, mon;

    ::reset();
    if(!present("goblin")) {
        mon = new(MONSTER);
        mon->set_name("goblin");
        mon->set_id( ({ "colonel", "goblin", "goblin colonel" }) );
        mon->set_short( "Goblin colonel");
        mon->set_long( "An ugly monster who has likely never seen "
		 "the light of day.");
        mon->set_level(4);
        mon->set_race( "goblin");
        mon->set_aggressive( 10);
        mon->set_alignment(-180);
        mon->set_hp(275);
        mon->set_gender("female");
        mon->set_body_type("human");
        mon->move(this_object());

        arm = new(ARMOUR);
        arm->set_name("visor");
        arm->set_id( ({ "visor", "goblin visor" }) );
        arm->set_short( "Goblin visor");
        arm->set_long( "A metallic visor with opening just "
		 "large enough to see through.");
        arm->set_type("visor");
        arm->set_limbs( ({ "head" }) );
        arm->set_ac(1);
        arm->set_mass(100);
        arm->set_value(100);
        arm->move(mon);
        mon->force_me("wear visor");
    }
}

