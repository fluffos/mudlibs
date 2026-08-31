#include <std.h>
inherit WEAPON;
create() {
::create();
    set_id(({"dagger","dark souls dagger","darksouls dagger"}));
set_curr_value("gold", 200);
    set_name("dark souls dagger");
    set_short("%^BOLD%^%^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k %^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s %^WHITE%^D%^BLACK%^a%^WHITE%^g%^BLACK%^g%^WHITE%^e%^BLACK%^r%^RESET%^");
    set_long( "%^BOLD%^%^WHITE%^This Knife was formed from the %^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l of a Ancient warrior.%^RESET%^");
    set_mass(15);
    set_curr_value("gold",90);
    set_wc(11);
    set_type("knife");
    set_hands(1);    
    set_hit((:this_object(),"weapon_hit":));
    set_wield("%^BOLD%^%^BLACK%^The Power of past souls fills you.%^RESET%^");
    set_unwield("%^BOLD%^%^WHITE%^You feel the power of the souls leave you.%^RESET%^");
}
int weapon_hit()
{
int result;
object ob;
ob=this_player()->query_current_attacker();
if(random(100) > 87) {
message("info", "%^BOLD%^%^BLACK%^You call on the Darksouls that have gone before!",this_player()); 
        message("info", "%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" stabs deeply into "+ob->query_possessive()+"!", environment(this_player()),({this_player(), ob}));
        message("info", "%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" stabs deeply into your body!", ob);
result=(random(50))+((this_player()->query_level())*2/3);
if(random(100) > 74) {
message("info", "%^BOLD%^%^BLACK%^You call on the Darksouls that have gone before!", this_player()); 
        message("info", "%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" summons the souls of the past to shock "+ob->query_possessive()+"!", environment(this_player()), ({this_player(), ob}));
        message("info", "%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" summons the souls of the past to shock you!", ob);
ob->set_paralyzed(random(3));
return result;
}
}
}
int query_auto_load() {
if(this_player()->query_guild() != "darksoul") return 0;
if(this_player()->query_level() < 40) return 0;

 return 1; 
}

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_guild() == "darksoul") return 0;
   write("%^BOLD%^%^RED%^YOU ARE NOT A DARKSOUL!!!!!!!!!!");
   say(this_player()->query_cap_name()+" prances around like a little girly person.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
