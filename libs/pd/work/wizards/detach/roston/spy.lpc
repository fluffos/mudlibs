#include <std.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("Bum");
    set_short("An old bum");
    set_long("The old bum, really dosent look like he lives on "
             "the street. His robes are golden, and his hands "
             "and finger are well cleaned, he has rings on his "
             "his finger's. This guy looks very buff and well " 
             "tranied, i wouldnt mess with him.");
set_id(({"bum", "old bum", "spy"}));
    set_level(55);
    set_exp(200000);
    new("/wizards/detach/roston/robes")->move(this_object());
    new("/wizards/detach/roston/s_dagger")->move(this_object());
    set_race("drow");
    set_body_type("human");
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
    this_object()->force_me("wear robes");
    this_object()->force_me("wield dagger");
    wielded_sword = 1;
   }
}                            
                       
