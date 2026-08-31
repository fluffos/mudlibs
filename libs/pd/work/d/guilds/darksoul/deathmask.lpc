#include <std.h>
inherit ARMOUR;

void create() {
    :: create();

    set_name("mask");
   set_property("dragon wear", 1);
    set_short("%^RED%^%^BOLD%^De%^BLACK%^at%^WHITE%^h%^RED%^s %^WHITE%^H%^BLACK%^e%^RED%^a%^WHITE%^d %^RED%^M%^BLACK%^a%^WHITE%^s%^RED%^k%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This bone white and deathly black mask is spattered slightly with the blood of the guilty. As you gaze at its face, you think you see the empty eyeholes glow for an instant.%^RESET%^");
    set_id(({"mask", "death mask"}));
    set_ac(2);
    set_mass(10);
    set_curr_value("gold",50000);
    set_type("mask");
    set_limbs(({"head"}));
    set_heart_beat(1);
}

int query_auto_load() {
    if(this_player()->query_guild() == "darksoul") return 1;
    return 0;
}

void heart_beat() {
    object tp;
    tp = this_object()->query_worn();
    if(!tp) return;
    if(random(100) > 90 && tp->query_current_attacker()) {
        if(environment(tp)->query_property("no attack")) return;
        message("info", "%^BOLD%^%^MAGENTA%^The mask makes "+tp->query_cap_name()+"'s eyes flash as pain is transformed into energy!%^RESET%^",
environment(tp), tp);
        message("info", "%^BOLD%^%^MAGENTA%^Your eyes flash as pain is transformed into energy!%^RESET%^", tp);
        tp->heal(random(tp->query_level())+10);
    }
}
