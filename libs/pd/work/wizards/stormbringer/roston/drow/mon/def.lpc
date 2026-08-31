#include <std.h>
#include <roston.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
    ::create();
    set_name("Defender");
    set_short("Defender");
    set_long("This Defender will give his life for the general "
      "or his soul, he lives for protecting the general.");
    set_id(({"defender", "defender"}));
    set_race("drow");
    set_class("fighter");
    set("aggressive", 35);
    set_subclass("soldier");
    set_spell_chance(35);
    set_spells( ({"rush"}) );
    set_skill("riding", 900);
    set_swarm("general");
    set_level(70);

    set_body_type("human");
    set_gender("male");
    add_alignment(-500);
    new(DROWOBJ"drag")->move(this_object());
    new(DROWOBJ"staff")->move(this_object());



    set_heart_beat(1);
   set_exp(230000);
}                                             
void init()   
{
    ::init();
}

void heart_beat()
{
    ::heart_beat();
    if (!wielded_sword)
    {
	this_object()->force_me("wear armour");

	this_object()->force_me("wield staff");
	wielded_sword = 1;
    }
}


