inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_short("%^BOLD%^%^RED%^Bloodied Axe%^RESET%^");
   set_name("%^BOLD%^%^RED%^Bloodied Axe%^RESET%^");
   set_id( ({"axe"}) );
   set_long ("%^BOLD%^%^RED%^Covered with the blood of all those who made attempts at killing a Purgatory Guard, this axe looks to be a formidable weapon.");
   set_weight(90);
   set_curr_value("gold", 121);
   set_wc(9);
   set_ac(2);
   set("skill level", 200);
   set_type("axe");
   //set_hit((: this_object(), "weapon_hit" :));
   set_decay_rate(1500);
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^RED%^Your axe chops down into your opponents body!");
        say("%^BOLD%^%^RED%^"+(string)this_player()->query_cap_name()+"'s axe chops into their opponents body!");
       
result= (random(65)+random(35))+((this_player()->query_level()));
    }
}
int query_auto_load() { if (this_player()->query_level() > 49) return 1; }
