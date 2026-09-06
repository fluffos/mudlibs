/* Right fist of the Great Golem */
#include <npc.h>

void
create_monster()
{
    set_name("right fist");
    set_id(({ "golem", "fist", "right" }));
    set_short("The Right Fist of the Great Golem");
    set_long(
      "You gasp in amazement because this monster is so BIG that it doesn't fit \
into a single room! It is hard to realize how big it actually must be if \
this house-sized thing is just one of its fists!");
    set_gender(0);
    set_level(20);
    set_ep(1100000);
    set_hp(550);
    set_chance(30);
    set_spell_mess1("The Right Fist sweeps across the room!");
    set_spell_mess2("The Right Fist strikes you with a terrible force!");
    set_spell_dam(45);

    load_chat(5, ({"The Right Fist snaps its fingers.\n",
	"The Right Fist twiddles its thumb patiently.\n"}));
    set_ac(15);
    set_wc(22); /* Slightly stronger than the left fist */
    add_block( "northeast","all", 0, 0,
      "You cannot get past the Right Fist.",
      ":%<him.name%> tries to pass the Right Fist, but cannot.", 0,0 );

}
