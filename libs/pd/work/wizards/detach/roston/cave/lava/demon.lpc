#include <std.h>
inherit MONSTER;
  
int wielded_sword=0;
void create() {
::create();
    set_name("Fire Demon");
    set_short("%^RESET%^%^RED%^F%^ORANGE%^i%^RED%^r%^ORANGE%^e "
              "%^RED%^D%^ORANGE%^e%^RED%^m%^ORANGE%^o%^RED%^n");
    set_long("This is one of the great demons of the fireary "
             "deeps, his skin is a deep %^RED%^red%^RESET%^.");

    set_id(({"demon","fire demon"}));
    set_level(40);
    set_race("Demon");
    add_exp(150000);
    set_body_type("human");
    set_gender("male");
    set_heart_beat(1);             

new("/wizards/detach/roston/cave/lava/f_sword")->move(this_object());

}

void heart_beat()
{
 ::heart_beat();
 if (!wielded_sword)
   {
    this_object()->force_me("wield sword");
    wielded_sword = 1;       
   }

}
