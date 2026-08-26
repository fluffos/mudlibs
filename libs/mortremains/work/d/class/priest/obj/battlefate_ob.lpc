/*
ilz stole from cyanide's shield_ob.c
Cyanide cleaned up, 11 Jul 2000
*/

#include <p_spells.h>              
#include <magic.h>
#include <mudlib.h>

inherit OBJECT;

int armor_add, offence_add, save_add, dmg_add;
int force_resist = 0;

void create() {
    seteuid(getuid());
    set("id", ({ "#BATTLEFATE_SPELL#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

int begin_spell(object caster, object target) {
    int attbonus, defbonus, savebonus, dmgbonus, num;

    set("level", caster->query_level());

    num = (caster->query_level("priest")/3) + 1;
    if (num>5) num = 5;

    set("enchantment", DIM);
    set("schools", ({ "enchantment" }) );

    switch(random(6)+1){
    case 1 : defbonus = num;break;
    case 2 : savebonus = num;break;
    case 3 : attbonus = num;break;
    case 4 : dmgbonus = num;break;
    case 5 : attbonus = num; dmgbonus = num;break;
    default : break;
    }

    if ((int)caster->query("magical_defense")<num) {
	armor_add = defbonus - (int)caster->query("magical_defense");
	caster->add("magical_defense", armor_add);
    }

    if ((int)caster->query("magical_offence")<num) {
	offence_add = attbonus - (int)caster->query("magical_offence");
	caster->add("magical_offence", offence_add);
    }
    if ((int)caster->query("save_bonus")<num) {
	save_add = savebonus - (int)caster->query("save_bonus");
	caster->add("save_bonus", save_add);
    }

    if ((int)caster->query("dmg_bonus")<num) {
	dmg_add = dmgbonus - (int)caster->query("dmg_bonus");
	caster->add("dmg_bonus", dmg_add);
    }

    call_out("remove", caster->query_level() * 40 );
    return 1;
}

int remove() {
    object caster = environment(this_object());

    if ((caster) && living(caster)) {
	tell_object(caster, "Your battlefate spell ends.\n");
	caster->add("magical_offence", -1*offence_add);
	caster->add("magical_defense", -1*armor_add);
	caster->add("save_bonus", -1*save_add);
	caster->add("dmg_bonus", -1*dmg_add);
    }
    return ::remove();
}                                                  

/* EOF */
