#include <std.h>
inherit WEAPON;
create() {
::create();
    set_id(({"knife","dark souls knife","darksouls knife"}));
set_curr_value("gold", 200);
    set_name("dark souls knife");
    set_short("%^BOLD%^%^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k %^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s %^WHITE%^K%^BLACK%^n%^WHITE%^i%^BLACK%^f%^WHITE%^e%^RESET%^");
    set_long( "%^BOLD%^%^WHITE%^This Knife was formed from the %^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l of a Ancient warrior.%^RESET%^");
    set_mass(15);
    set_curr_value("gold",90);
    set_wc(11);
    set_type("knife");
    set_hands(1);    
    set("skill level", 119);
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
ob->set_paralyzed(random(2));
return result;
}
}
}
