#include <std.h>
inherit MONSTER;

int wielded_sword=0; 
void create() {
::create();
    set_name("Pam");
    set_short("%^BOLD%^%^MAGENTA%^Pam the Dancer");
    set_long("Pam is the kinda chick all guys dream about. She "
             "has hooters like you only see on t.v, her legs "
             "are long and look better then candy. Shes got so many "
             "curves you go dizzy.");
    set_id(({"dancer","pam"}));
    set_level(1);
    set_race("human");
    set_body_type("human");
    set_gender("female");
    set_emotes(10,
        ({"Pam dances all around the room butt nekked",
        }),
        0); 
    
    set_heart_beat(1);
    new("/wizards/detach/roston/n_ring")->move(this_object());
    new("/wizards/detach/roston/n_ring2")->move(this_object());
    new("/wizards/detach/roston/bra")->move(this_object());
    new("/wizards/detach/roston/thong")->move(this_object());
    
}

void heart_beat()
{
 ::heart_beat();
 if (!wielded_sword)
   {
    this_object()->force_me("wear ring");
    this_object()->force_me("wear ring 2");
    this_object()->force_me("wear pink bra");
    this_object()->force_me("wear thong");
    wielded_sword = 1;
   }

}     

