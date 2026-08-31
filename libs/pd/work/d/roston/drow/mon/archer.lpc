#include <std.h>
#include <roston.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("Archer");
    set_short("Drow Archer");
    set_long("This archer is a member of the Drow army, he is "
            "a very strong archer, and will protect his lands "
            "with his life.");
    set_id(({"archer", "drow archer"}));
    set_race("drow");
    set("aggressive", 35);
    set_class("fighter");
    set_subclass("ranger");
    set_spell_chance(40);
    set_spells(({"rush"}));
    set_level(62);

    set_body_type("human");
    set_gender("male");
    set_alignment(-500);
    new(DROWOBJ"chain")->move(this_object());
    new(DROWOBJ"boots")->move(this_object());
    new(DROWOBJ"bow")->move(this_object()); 


    set_heart_beat(1);
}                                             
void init()   
{
 ::init();
}

void heart_beat()
{
 ::heart_beat();
 if (!this_object()) return;
 if (!wielded_sword)
   {
    this_object()->force_me("wear chainmail");
    this_object()->force_me("wield bow");
    this_object()->force_me("wear boots");
    wielded_sword = 1;
   }
}
