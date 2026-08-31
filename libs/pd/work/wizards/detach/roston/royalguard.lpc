#include <std.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("Guard");
    set_short("Prince's Royal Guard");
    set_long("The prince's Royal guard is here to protect "
             "the prince from anyone who trys to kill him.");
    set_id(({"guard", "royal guard"}));
    set_level(35);
    new("/wizards/detach/roston/battleaxe")->move(this_object());
    new("/wizards/detach/roston/battleaxe")->move(this_object());
    set_race("dwarf");
    set_body_type("human");
    set_swarm("Prince");
    set_gender("male");
    set_heart_beat(1);
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
    this_object()->force_me("wield axe");
    this_object()->force_me("wield axe 2");
    wielded_sword = 1;
   }
}
