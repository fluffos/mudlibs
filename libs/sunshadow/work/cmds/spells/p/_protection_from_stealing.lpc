// Protection from Scrying
// Protects from any scrying attempts on the
// target of the spell for a period dependant on
// the spell level of the caster
// Thorn@ShadowGate
// 4 January 2001
// Updated by ~Circe~ with slightly different block power
// to match the scry power added to scrying spells 6/20/08

#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

object blocker;

void create() {
    ::create();
    set_spell_name("protection from stealing");
    //set_spell_level(([ "cleric" : 4, "paladin" : 3 ]));
    set_spell_level(([ "classless" : 4 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS prevent stealing [on TARGET]");
    set_description("This spell prevents stealing in the room where the caster has cast the spell for an amount of time "
"dependent on the level of the caster.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_peace_needed(1);
    set_helpful_spell(1);
}

int preSpell() {
    if (!query_arg()) {
        target = caster;
        return 1;
    }
    else
    {
        target = present(query_arg(), query_place());
    }
    return 1;
}


string query_cast_string() {
    if(target == caster && query_arg())
        return "%^BOLD%^CYAN%^"+caster->QCN+" holds their "+
            "hands into the air and chants, the air shimmering around "+
            caster->QP+" head!";
    else if(target == (object)PLACE)
        return "%^BOLD%^CYAN%^"+caster->QCN+" holds their hands "+
            "into the air and chants, the air shimmering above them!";
    else
        return "%^BOLD%^CYAN%^"+caster->QCN+" holds their hands "+
            "into the air and chants, the air shimmering above them!";
}

void spell_effect(int prof) {
    int num, wis_bonus,power;
    int duration;
	object temp;

    ::spell_effect();

    if(!objectp(target)) {
        tell_room(place,"%^BOLD%^RED%^"+caster->QCN+" abruptly "
            "stops casting and gets a confused look.",caster);

        tell_object(caster,"%^BOLD%^RED%^The target of your spell is not here!");
        TO->remove();
        return;
    }
	if(temp = target->query_property("protect_steal")) {
		if(!objectp(temp)) {
			target->remove_property("protect_steal");
		} else {
	        tell_object(caster,"%^BOLD%^RED%^There is already blocking "
    	    	"magic working for that target!");
        	TO->remove();
        	return;
        }
    }
    if(target == place)
        tell_room(place,"%^BOLD%^CYAN%^For a brief moment, the air around "+
            "you shimmers with motes of magical energy.");
    else
        tell_room(place,"%^BOLD%^CYAN%^For a brief moment, the air around "+
            target->query_short()+" shimmers with motes of magical energy.");

    target->set_property("spelled",({TO}));
    blocker =   target->set_property("protect_steal",({TO}));


    wis_bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
    power = CLEVEL + wis_bonus + random(6);
    blocker->set_block_power(power);

    duration = 6 * (int)CLEVEL * ROUND_LENGTH;
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

void dest_effect() {
    if(objectp(target)) target->remove_property_value("spelled", ({TO}) );
    if(objectp(blocker)) blocker->self_destruct();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
