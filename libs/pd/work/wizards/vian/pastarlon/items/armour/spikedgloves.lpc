#include <std.h>
#include <damage_types.h>
#include <damage.h>
#include <pastarlon.h>
inherit ARMOUR;

void create() {
    :: create();

    set_name("gloves");
    set_short("%^BOLD%^%^BLACK%^spi%^RESET%^k%^BOLD%^e%^BLACK%^d glo%^RESET%^v%^BOLD%^e%^BLACK%^s%^RESET%^");
    set_long("These gloves have not been adequately described.");
    set_id(({"gloves", "spiked gloves"}));
    set_ac(4);
    set_mass(20);
    set_curr_value("gold",100+random(50));
    set_type("gloves");
    set_limbs(({"left hand", "right hand"}));
    set_heart_beat(1);

}

int query_auto_load() { 
    if(this_player()->query_level() < 30) return 0;
    return 1;
}

void heart_beat() {
    object tp, enemy, env;
    tp = this_object()->query_worn();
    if (!tp || !(env = environment(tp)) || sizeof(tp->query_wielded()) || tp->query_rest_type() || tp->query_paralyzed())
        return;
    if (tp->query_class() == "mage") return;
    if (tp->query_subclass() == "cleric") return;
    if (tp->query_subclass() == "kataan") return;
    if (tp->query_level() < 30) return;
    enemy = tp->query_current_attacker();
    if (random(100) > 65 && enemy) {
        int dmg = 50+random(50);
        if (env->query_property("no attack") || env != environment(enemy))
            return;
        message("combat", "The spikes on your %^BOLD%^%^BLACK%^spi%^RESET%^k%^BOLD%^e%^BLACK%^d glo%^RESET%^v%^BOLD%^e%^BLACK%^s%^RESET%^ pierce "+enemy->query_cap_name()+"'s skin!", tp);
        message("combat", tp->query_cap_name()+" thrusts their %^BOLD%^%^BLACK%^spi%^RESET%^k%^BOLD%^e%^BLACK%^d glo%^RESET%^v%^BOLD%^e%^BLACK%^s%^RESET%^ into you!", enemy);
        message("combat", tp->query_cap_name()+" thrusts the spikes on their %^BOLD%^%^BLACK%^spi%^RESET%^k%^BOLD%^e%^BLACK%^d glo%^RESET%^v%^BOLD%^e%^BLACK%^s%^RESET%^ into "+enemy->query_cap_name()+"!", env, ({ tp, enemy }) );
        enemy->do_damage("target", dmg, DAMAGE_PHYSICAL | DAMAGE_UNARMED | DAMAGE_IMPACT, DAMAGE_NO_SEVER | DAMAGE_BYPASS_ARMOUR, tp);
    }
}
