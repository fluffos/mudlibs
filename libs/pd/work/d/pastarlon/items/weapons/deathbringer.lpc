#include <std.h>
#include <pastarlon.h>
#include <damage_types.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {::create();;
     set_name("deathbringer");;
     set_short("%^BOLD%^%^BLACK%^de%^RESET%^a%^BOLD%^t%^BLACK%^h%^RESET%^b%^BLACK%^%^BOLD%^ri%^RESET%^n%^BOLD%^g%^BLACK%^er%^RESET%^");;
     set_long("This morning star is made of a simple black handle, connected to a spiked ball by a long chain.  Although it doesn't look too special, it has a presence to it.");;
     set_id( ({"deathbringer", "morning star", "star", "flail"}) );;
     set_hands(1);;
     set_wc(10);;
     set("skill level", 200);
     set_curr_value("gold", 250+random(35));;
     set_type("flail");;
     set_hit((:weapon_hit:));;
     set_damage_type( DAMAGE_PHYSICAL | DAMAGE_IMPACT | DAMAGE_PIERCE );
     set_damage_flags( 0 );
     set_weight(20);
}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 17) {
     write("Your %^BOLD%^%^BLACK%^de%^RESET%^a%^BOLD%^t%^BLACK%^h%^RESET%^b%^BLACK%^%^BOLD%^ri%^RESET%^n%^BOLD%^g%^BLACK%^er%^RESET%^ glows brightly.");;
     say((string)""+this_player()->query_cap_name()+"'s %^BOLD%^%^BLACK%^de%^RESET%^a%^BOLD%^t%^BLACK%^h%^RESET%^b%^BLACK%^%^BOLD%^ri%^RESET%^n%^BOLD%^g%^BLACK%^er%^RESET%^ glows brightly.");;
result=(random(30))+((this_player()->query_level())*2);;
this_player()->add_sp(result);;
return result;;
}
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 29);
}

