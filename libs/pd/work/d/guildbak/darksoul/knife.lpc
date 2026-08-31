#include <std.h>
inherit WEAPON;
create() {
::create();
    set_id(({"knife","dark souls knife","darksouls knife"}));
    set_name("dark souls knife");
    set_short("%^BOLD%^%^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k "
              "%^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s "
               "%^WHITE%^K%^BLACK%^n%^WHITE%^i%^BLACK%^f%^WHITE%^e"
                "%^RESET%^");
    set_long( "%^BOLD%^%^WHITE%^This Knife was formed from the "
              "Soul of a %^BLACK%^Ancient%^WHITE%^ warrior.");
    set_mass(9);
    set_curr_value("gold",random(40));
    set_wc(9);
    set_type("knife");
    set_hands(1);    
    set_hit((:this_object(),"weapon_hit":));
    set_wield("%^BOLD%^%^BLACK%^The Power of past souls fills you.");
    set_unwield("%^BOLD%^%^WHITE%^You feel the power of the souls leave "
                "you.");
}
int weapon_hit() {
    object ob;
    string *limbs, lib;
    ob=this_player()->query_current_attacker();
    if(random(75)<10){
        limbs=ob->query_limbs();
        lib = limbs[0];
        message("info", "%^BOLD%^%^BLACK%^You call on the Darksouls that have gone before!", this_player()); 
        message("info", "%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" stabs deeply into "+ob->query_possessive()+" "+lib+"!", environment(this_player()), ({this_player(), ob}));
        message("info", "%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" stabs deeply into your "+lib+"!", ob);
        ob->heal_limb(lib, -(random(20)+random(this_player()->query_level())+10));
        return 1;
    }
}
int query_auto_load() { if (this_player()->query_level() > 30) return 1; }
