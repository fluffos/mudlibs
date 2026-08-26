//ilz

#include <m_spells.h>              
#include <magic.h>
#include <mudlib.h>

inherit OBJECT;
int armor_add = 0;
int offence_add = 0;
int force_resist = 0;
int hp_add = 0;



void create() {
    seteuid(getuid());
    set("id", ({ "#HEARTSTONE_SPELL#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

int begin_spell(object target) {
    set("level", target->query_level());

    set("enchantment", OVERWHELMING);
    set("schools", ({ "necromancy" }) );

    target->add("prevent_heal", 1);
    target->resistance("slashing", 1);
    target->resistance("piercing", 1);
    target->resistance("bludgeoning", 1);

    call_out("remove", target->query_level() * 20 );
    return 1;
}

int reflex(int dmg, string type, object ob, int weap) {
    switch(type) {
    case "bludgeoning" : dmg /= 2; break;
    case "slashing" :
    case "piercing" : dmg = 1 + random(3); break;
    }

    return dmg;
}

int remove() {
    object target = environment(this_object());

    if ((target) && living(target)) {
	tell_object(target, "Your heart of stone spell ends.\n");
	target->resistance("slashing", 10000);
	target->resistance("piercing", 10000);
	target->resistance("bludgeoning", 10000);
	target->add("prevent_heal", -1);
    }
    ::remove();
    return 1;
}                                                  

/* EOF */
