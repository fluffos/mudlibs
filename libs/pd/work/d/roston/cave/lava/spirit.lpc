#include <std.h>
#include <roston.h>
inherit MONSTER;
  
int wielded_sword=0;
void create() {
::create();
    set_name("Lava Spirit");
    set_short("%^RESET%^%^RED%^L%^ORANGE%^a%^RED%^v%^ORANGE%^a%^RED%^ S"
              "%^ORANGE%^p%^RED%^i%^ORANGE%^r%^RED%^i%^ORANGE%^t");
    set_long("This is one of the great demons who wonder around "
             "the firey deeps. He has beat %^RED%^red%^RESET%^"
             " eyes");

    set_id(({"spirit","lava spirit"}));
    set_level(40);
    set_race("Spirit");
    set_body_type("human");
    set_gender("male");
    set_heart_beat(1);             
      new(ROSTON"cave/lava/f_axe")->move(this_object());
}

void heart_beat()
{
 ::heart_beat();
 if (!wielded_sword)
   {
    this_object()->force_me("wield axe"); 
    wielded_sword = 1;       
   }

}
