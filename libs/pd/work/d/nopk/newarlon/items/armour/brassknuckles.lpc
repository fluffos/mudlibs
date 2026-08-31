#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit ARMOUR;

void create() {
    :: create();

    set_name("brass knuckles");
    set_short("%^ORANGE%^brass knuckles%^RESET%^");
    set_long("These brass knuckles are a sort of gloves, they look like they can cause some damage.");
    set_id(({"knuckles", "gloves", "brass knuckles"}));
    set_ac(2);
    set_mass(10);
    set_type("gloves");
    set_limbs(({"left hand", "right hand"}));
    set_heart_beat(1);

}

int query_auto_load() { 
    if(this_player()->query_level() < 4) return 0;
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
    if (tp->query_level() < 4) return;
    enemy = tp->query_current_attacker();
    if (random(100) > 50 && enemy) {
        int dmg = 35+random(15);
        if (env->query_property("no attack") || env != environment(enemy))
            return;
        message("combat", "You swing your %^ORANGE%^brass knuckles%^RESET%^ into "+enemy->query_cap_name()+"'s head!", tp);
        message("combat", tp->query_cap_name()+" swings their %^ORANGE%^brass knuckles%^RESET%^ into your head!", enemy);
        message("combat", tp->query_cap_name()+" swings their %^ORANGE%^brass knuckles%^RESET%^ into "+enemy->query_cap_name()+"!", env, ({ tp, enemy }) );
        enemy->do_damage("target", dmg, DAMAGE_PHYSICAL | DAMAGE_UNARMED | DAMAGE_IMPACT, DAMAGE_NO_SEVER | DAMAGE_BYPASS_ARMOUR, tp);
    }
}
