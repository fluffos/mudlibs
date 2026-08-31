#include <std.h>
inherit WEAPON;
int weapon_hit;

create() {
::create();
        set_name("spear");
        set_short("Ancient Trident");
        set_long("Rumored to be the trident wielded by the god of the sea,"
                "the ancient trident seems to let off an odd glow. The aura "
                "around the trident may be dim, but its presence signifies "
                "that it may be deadlier than it seems.");
        set_id(({"ancient trident", "trident", "spear", "glowing trident"}));
        set_weight(20 + random(10));
        set_wc(13);
        set_value(100 + random(25));
        set_hands(2);
        set_type("projectile");
        set_hit( (: this_object(), "weapon_hit" :) );
 
}

int query_auto_load(){ 
    if (this_player()->query_level() > 35) 
        return 1; 
    
    return 0; 
}

int weapon_hit() {
    int x;
    object tp, victim;
    
    tp = this_player();
    victim = (object)this_player()->query_current_attacker();
    
    x = random(100);
    
    if( x >= 95) {
        message("player", "You thrust your trident into your opponents gut!", tp);
        message("victim", "Your opponent thrusts a trident into your gut, and you keel over!", victim);
        message("room", tp->query_cap_name()+" thrusts a trident into "
            +victim->query_cap_name()+"'s gut!", environment(tp), ({tp, victim}));
        return (25+random(50));
    }
    if(x >= 85) {

        message("player", "You smash your trident's shaft into your opponents head!", tp);
        message("victim", "Your opponent smashes the trident's shaft into your head!", victim);
        message("room", tp->query_cap_name()+" smashes a trident's shaft onto "
            +victim->query_cap_name()+"'s head!", environment(tp), ({tp, victim}));
        return (15 + random(25));
    }
    return 0;
}
