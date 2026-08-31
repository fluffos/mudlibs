#include <std.h>
inherit WEAPON;
int weapon_hit(object ob);    
create() {
::create();
    set_id(({"knife","assassians knife"}));
    set_name("Assassian's knife");
    set_short("Assassian's knife");
    set_long( "A long black blade.");
    set_mass(10);
    set_value(400+random(40));
    set_wc(1);           
    set_ac(1);
    set_type("knife");
    set_hands(1);
    set_hit((: weapon_hit :)); 
}
 
int weapon_hit(object ob)
{
 if ( ob->query_name() == "current attacker" )
   {
    message("info",
      "The sword flames in hatred of syphon.\n", environment(ob));
    return 500;
   }
 return 1;
}              
