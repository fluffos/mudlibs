#include <std.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("Hunter");
    set_short("Elder Hunter");
    set_long("This is a great elder hunter from the town of "
             "Roston. He is a very old and powerfull man, he "
             "in the great cave in Roston.");

    set_id(({"hunter","elder hunter"}));
    set_level(39);
    set_race("dwarf");
    set_body_type("human");
    set_gender("male");
    set_spell_chance(35);
    set_spells( ({ "whirl", }) );
    set_heart_beat(1); 
    new("/wizards/detach/roston/h_shield")->move(this_object());
    new("/wizards/detach/roston/armour")->move(this_object());
      new("/wizards/detach/roston/battleaxe")->move(this_object());

}

void heart_beat()
{
 ::heart_beat();
 if (!wielded_sword)     
       {
    this_object()->force_me("wield axe");
    this_object()->force_me("wear shield");
    this_object()->force_me("wear armour");
    wielded_sword = 1;
   }

}         
