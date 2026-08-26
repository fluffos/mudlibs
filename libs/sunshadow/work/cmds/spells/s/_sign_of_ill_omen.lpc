// midlevel necromancy school specialty spell. Nienne, 08/09.
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
#include <skills.h>
inherit SPELL;

//Warlocky descriptions

int bonus,i;

int is_curse()
{
    return 1;
}

void create() {
    ::create();
    set_spell_name("sign of ill omen");
    set_spell_level(([ "warlock" : 3 ]));
    set_heritage("astral");
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS sign of ill omen on TARGET");
    set_damage_desc("clevel / 8 to all skills, attack and damage bonus, caster level");
    set_description("Calling upon the power of their patron, the warlock places a fell mark upon his enemy that saps at their strength and leaves them weakened. The mark slowly fades away over time, and is not otherwise dispellable.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string() {
    return "%^RESET%^%^CRST%^%^C103%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C103%^ raises two fingers, their tips blackened by %^C243%^sh%^C245%^ad%^C247%^ow%^C249%^y t%^C247%^en%^C245%^dr%^C243%^il%^C245%^s %^RESET%^%^C103%^as they trace a %^C118%^s%^C112%^ym%^C106%^b%^C118%^o%^C112%^l %^RESET%^%^C103%^in the air.%^CRST%^";
}

void spell_effect(int prof) {
    int duration;
    if(target == caster) {
        tell_object(caster, "%^RESET%^%^CRST%^%^C103%^You realize your error in cursing yourself, and let your spell fade away.%^CRST%^");
        tell_room(place,"%^RESET%^%^CRST%^%^C103%^The %^C243%^a%^C245%^u%^C247%^r%^C249%^a %^RESET%^%^C103%^around "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C103%^'s fingers weakens and then %^C249%^f%^C247%^a%^C245%^d%^C243%^e%^C059%^s %^RESET%^%^C103%^away.%^CRST%^",caster);
        TO->remove();
        return;
    }
    if(target->query_property("cursed")) {
        tell_object(caster,"%^RESET%^%^CRST%^%^C103%^Your %^C118%^m%^C112%^ar%^C106%^k %^RESET%^%^C103%^fails to take hold on "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C103%^, as similar energies are already present!%^CRST%^");
        tell_room(place,"%^RESET%^%^CRST%^%^C103%^The %^C243%^a%^C245%^u%^C247%^r%^C249%^a %^RESET%^%^C103%^around "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C103%^'s fingers weakens and then %^C249%^f%^C247%^a%^C245%^d%^C243%^e%^C059%^s %^RESET%^%^C103%^away.%^CRST%^",caster);
        TO->remove();
        return;
    }
    if(do_save(target, 0)){
        tell_object(target,"%^RESET%^%^CRST%^%^C103%^You manage to resist some %^C118%^f%^C112%^ou%^C106%^l %^C118%^s%^C112%^pe%^C106%^l%^C118%^l%^RESET%^%^C103%^, feeling only a momentary weakness.%^CRST%^");
        tell_room(place,"%^RESET%^%^CRST%^%^C103%^The outline of a %^C118%^s%^C112%^ig%^C106%^i%^C118%^l %^RESET%^%^C103%^begins to form on "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C103%^, but quickly %^C249%^f%^C247%^a%^C245%^d%^C243%^e%^C059%^s %^RESET%^%^C103%^away.%^CRST%^",target);
        TO->remove();
        return;
    }
    bonus = clevel / 8;
    duration = (ROUND_LENGTH * 4 + roll_dice(1, 20)) * clevel;

    tell_object(target,"%^RESET%^%^CRST%^%^C103%^A %^C118%^f%^C112%^el%^C106%^l %^C118%^m%^C112%^ar%^C106%^k %^RESET%^%^C103%^materializes on you, and immediately you feel a measure of your vitality %^C059%^stripped %^C103%^away from you.%^CRST%^");
    tell_room(place,"%^RESET%^%^CRST%^%^C103%^A %^C118%^f%^C112%^el%^C106%^l %^C118%^m%^C112%^ar%^C106%^k %^RESET%^%^C103%^materializes on "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C103%^, and they seem to look %^C059%^faint %^C103%^and %^C059%^weary%^RESET%^%^C103%^.%^CRST%^",target);
    target->add_damage_bonus((-1) * bonus);
    target->add_attack_bonus((-1) * bonus);
    target->set_property("empowered", (-1) * bonus);
    for (i = 0; i < sizeof(CORE_SKILLS); i++) {
        target->add_skill_bonus(CORE_SKILLS[i], (-1) * bonus);
    }
    target->add_saving_bonus("all", (-1) * bonus);
    target->set_property("spelled", ({ TO }));
    target->set_property("cursed", 1);
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}

void dest_effect() {
    if(objectp(target)) {
        tell_object(target,"%^RESET%^%^CRST%^%^C103%^The %^C118%^f%^C112%^el%^C106%^l %^C118%^m%^C112%^ar%^C106%^k %^RESET%^%^C103%^finally %^C249%^f%^C247%^a%^C245%^d%^C243%^e%^C059%^s %^RESET%^%^C103%^away and your strength returns to your body.%^CRST%^");
        tell_room(environment(target),"%^RESET%^%^CRST%^%^C103%^The %^C118%^f%^C112%^el%^C106%^l %^C118%^m%^C112%^ar%^C106%^k %^RESET%^%^C103%^finally %^C249%^f%^C247%^a%^C245%^d%^C243%^e%^C059%^s %^RESET%^%^C103%^away from "+target->QCN+"%^RESET%^%^CRST%^%^C103%^'s body.%^CRST%^",target);
        target->add_damage_bonus(bonus);
        target->add_attack_bonus(bonus);
        target->set_property("empowered",bonus);
        target->remove_property_value("spelled", ({TO}) );
        for(i=0;i<sizeof(CORE_SKILLS);i++) target->add_skill_bonus(CORE_SKILLS[i],bonus);
        target->add_saving_bonus("all",bonus);
        target->remove_property("cursed");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

