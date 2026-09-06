/* Left fist of the Great Golem */
#include <npc.h>

void
create_monster()
{
    set_name("Left fist");
    set_id(({ "golem", "fist", "left" }));
    set_short("The Left Fist of the Great Golem");
    set_long(
      "You gasp in amazement because this monster is so BIG that it doesn't fit \
into a single room! It is hard to realize how big it actually must be if \
this house-sized thing is just one of its fists!");
    set_gender(0);
    set_level(20);
    set_ep(1050000);
    set_hp(520);
    set_chance(30);
    set_spell_mess1("The Left Fist sweeps across the room!");
    set_spell_mess2("The Left Fist strikes you with a terrible force!");
    set_spell_dam(40);

    load_chat(5, ({"The Left Fist snaps its fingers.\n",
	"The Left Fist twiddles its thumb patiently.\n"}));

    set_ac(15);
    set_wc(20); /* Slightly weaker than the right fist */
    add_block( "northwest","all", 0, 0,
      "You cannot get past the Left Fist.",
      ":%<him.name%> tries to pass the Left Fist, but cannot.", 0,0 );

}
