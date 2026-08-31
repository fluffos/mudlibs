#include <std.h>
inherit MONSTER;
int wielded_sword=0; 

void create() {
::create();
    set_name("Bear");
    set_short("A Giant Bear");
    set_long("This giant bear has been put here to make "
             "sure no one enters this Cave. He is the bigest "
             "bear you have ever seen in your life. He stands "
             "10 feet tall and has a giant white spot on his "
             "dark brown coat of fur.");
    set_id(({"bear","giant bear"}));
    set_level(40);
    set_race("Bear");
    set_body_type("human");
    set_gender("male");
    set_spell_chance(35);
    set_spells( ({ "slash", }) );
    set_heart_beat(1);
    new("/wizards/detach/roston/g_claw")->move(this_object());  
             

::init();

}


void heart_beat()
{
 ::heart_beat();
  if (!this_object()) return;
 if (!wielded_sword)
   {
    this_object()->force_me("wield claw");
    wielded_sword = 1;
   }
}      
