# include <std.h>
inherit WEAPON;

void create() {
::create();
  
    set_name("blade");
    
set_short("%^BOLD%^%^BLACK%^Bl%^RESET%^%^BOLD%^ad%^RESET%^e of "
         "D%^BOLD%^ea%^BLACK%^th%^RESET%^");
    set_long("The blade of death is a tarnished silver colour, it's hilt a dark ruby colour with an old bony hand reaching about it as protection. ");
    set_id(({"blade"}));
    set_wc(20);            
    set_type("blade");   
    set_hit((:this_object(),"weapon_hit":));

}

int weapon_hit()
{
 int result;
 object atk;
 atk = (object)this_player()->query_current_attacker();
 if(random(102) > 85) {
 write("The hand on your blade grasps your enemy as you thrust it through, draining stamina!");
 say((string)this_player()->query_cap_name()+
 " thrusts the blade of death into "
 +this_player()->query_possessive()+"'s chest!");
 result=(random(55+random(50)-random(50))*((this_player()->query_level()/20)+1));
 result=random(result)+1;
 this_player()->add_sp(result);
  return result;
 }



int bury() { this_player()->do_damage("head", 1000000);
this_player()->check_on_limb("head"); 

}

int query_auto_load() { if (this_player()->query_level() >=50) return 1; }

