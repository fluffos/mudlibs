#include <std.h>
inherit WEAPON;

void create(){
    ::create();
    set_name("dagger");
    set_short("%^BOLD%^%^BLUE%^Sapphire %^WHITE%^Dagger%^RESET%^");
    set_wc(12);
    set_weight(10);
    set_value(10000);
    set_id( ({"blade", "sapphire dagger", "sapphire", "dagger"}) );
    set_long("%^BLUE%^This slender dagger is deadly. Its hilt is wrapped in leather, yet its blade is made of the sapphire gemstone. It glimmers in the light.");
    set_type("knife");
    set_hit((: this_object(), "weapon_hit" :));
}

int weapon_hit() {
    object ob;
    string *limbs, lib;
    ob=this_player()->query_current_attacker();
    if(random(75)<10){
        limbs=ob->query_limbs();
        lib = limbs[0];
        message("info", "%^CYAN%^You slice through "+ob->query_possessive()+" "+lib+" with your dagger!", this_player()); 
        message("info", "%^CYAN%^"+this_player()->query_cap_name()+" slices through "+ob->query_possessive()+" "+lib+"!", environment(this_player()), ({this_player(), ob}));
        message("info", "%^CYAN%^"+this_player()->query_cap_name()+" slices through your "+lib+"!", ob);
        ob->heal_limb(lib, -(random(20)+random(this_player()->query_level())+20));
        return 1;
    }
}

int query_auto_load() { if (this_player()->query_level() > 30) return 1; }
