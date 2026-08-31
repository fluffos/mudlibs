#include <std.h>
#include <roston.h>

inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("knight");
    set_short("Prince's loyal Knight");
    set_long("The prince's loyal knight is here to protect "
             "the prince from any harm that may come to him.");
    set_id(({"knight", "loyalknight"}));
    set_level(38);
    new(WEP"battleaxe")->move(this_object());
    new(WEP"battleaxe")->move(this_object());
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
                                  
