#include <std.h>

inherit WEAPON;

void create() {
::create();
    set_name("Sadistic Pike");
    set_short("%^BOLD%^%^RED%^Sa%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^i%^RESET%^%^WHITE%^st%^BOLD%^%^BLACK%^ic%^RESET%^ %^WHITE%^P%^BOLD%^%^i%^RESET%^%^WHITE%^ke%^RESET%^");
    set_long("This metalic pike, a serpants tail for the tip and a small skull at the handle. The metal seems to absorb all light around consuming the very essence of the sun.");
    set_id(({"pike", "sadistic pike"}));
    set_mass(100);
   set_curr_value("gold", 125);
    set_type("projectile");
   set_wc(1);
    set_hands(1);
    set_wield("%^BOLD%^%^BLACK%^You hear %^BOLD%^%^RED%^sa%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^i%^RESET%^%^WHITE%^st%^BOLD%^%^BLACK%^ic voices...%^RESET%^");
    set_unwield("%^BOLD%^%^BLACK%^The voices fade away...%^RESET%^");
    set_ac(1);
    //set_hit((: this_object(), "weapon_hit" :));
}
    
int weapon_hit() {
    int result;
    object ob;
    ob=(object)this_player()->query_current_attacker();
    if(random(10) == 0) {
result=((this_player()->query_skill("projectile")+this_player()->query_stat("strength"))-((this_player()->query_current_attacker()->query_stat("constitution")+this_player()->query_current_attacker()->query_skill("defense"))*2/3));
       message("info", "%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" %^WHITE%^thrusts%^BOLD%^%^BLACK%^ their pike into "+this_player()->query_current_attacker()->query_cap_name()+"!%^RESET%^\n%^BOLD%^%^RED%^Blood splatters everywhere...%^RESET%^", environment(ob), ({ob, this_player()}));
       write("%^BOLD%^%^BLACK%^You %^WHITE%^thrust%^BOLD%^%^BLACK%^ your pike through "+this_player()->query_current_attacker()->query_cap_name()+" %^WHITE%^mutilating%^BOLD%^%^BLACK%^ them!%^RESET%^", this_player());
       message("info", "%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" %^WHITE%^thrusts%^BOLD%^%^BLACK%^ "+this_player()->query_possessive()+" pike into you%^RESET%^\n%^BOLD%^%^RED%^Blood splatters everywhere...%^RESET%^", ob);
        return (result/3);
    }
}

int query_auto_load() { 
    if(this_player()->query_guild() == "forsaken") return 1;

}
