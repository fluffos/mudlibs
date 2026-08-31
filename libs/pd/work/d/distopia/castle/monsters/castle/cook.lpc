#include <std.h>
#include <discastle.h>
inherit MONSTER;
void create() {
::create();
    set_name("cook");
    set_short("A stout cook");
    set_long("The cook is big and heavy.  He looks good at what he does");
    set_id(({"human", "cook", "monster"}));
    set_race("human");
    set_gender("male");
    set_body_type("human");
    set_skill("axe", 400);
    add_money("silver", random(100) );
    set_class("fighter");
    set_gender("male");
    set_subclass("warrior");
    set_spells( ({"hack"}));
    set_spell_chance(50);
    set_level(45);
    new(WEAP"cleaver")->move(this_object());
    command("wield cleaver");
    new(WEAP"cleaver")->move(this_object());
   	command("wield axe");
    
    set_emotes(20,     // He will emote this line once every 10 heart beats
	({"The cook pokes at the chicken while whistling",
	  "The cook adds another layer of glaze",
	  "The cook farts, loudly."
	}),
	0);
}
