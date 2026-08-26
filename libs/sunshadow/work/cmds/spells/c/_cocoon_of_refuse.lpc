// Reskin of Web

#include <spell.h>
#include <magic.h>

inherit SPELL;

object oldenv, web, mass;
int waittime;

void dest_effect();
void waiter(int num);

create() {
    ::create();
    set_spell_name("cocoon of refuse");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS cocoon of refuse on TARGET");
    set_damage_desc("tripped for 1d8 rounds");
    set_description("With this spell, the caster causes all loose material in the area to cling to the target, hampering their movement greatly and causing them to trip.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
}

string query_cast_string() {
    return "%^RESET%^%^CRST%^%^C058%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^ places "+caster->query_possessive()+" hands together, gathering %^C144%^e%^C138%^ld%^C132%^r%^C144%^i%^C138%^tc%^C132%^h %^C144%^e%^C138%^ne%^C132%^r%^C144%^g%^C138%^y%^RESET%^%^C058%^.%^CRST%^";
}

spell_effect(int prof) {
    int save, neededroll, power;
    string strength;
    tell_object(caster, "%^RESET%^%^CRST%^%^C058%^You release the %^C144%^e%^C138%^ne%^C132%^r%^C144%^g%^C138%^y %^RESET%^%^C058%^and the %^C100%^loose material %^C058%^around you begins to swirl around "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^!%^CRST%^");
    tell_object(target, "%^RESET%^%^CRST%^%^C058%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^ releases their %^C144%^d%^C138%^ar%^C132%^k %^C144%^e%^C138%^ne%^C132%^r%^C144%^g%^C138%^y %^C058%^and the %^C100%^loose debris %^C058%^in the area begins to swirl around you!%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C058%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^ releases their %^C144%^d%^C138%^ar%^C132%^k %^C144%^e%^C138%^ne%^C132%^r%^C144%^g%^C138%^y %^C058%^and the %^C100%^loose debris %^C058%^in the area begins to spin around "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^!%^CRST%^", ({caster, target}) );
    if ( do_save(target,-2)) {
        tell_object(caster, "%^RESET%^%^CRST%^%^C101%^"+target->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ manages to slip away from your cocoon of refuse!%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^%^C101%^You manage to slip away from the swirling material!%^CRST%^");
        tell_room(environment(caster), "%^RESET%^%^CRST%^%^C101%^"+target->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ manages to slip away from the swirling material!%^CRST%^",({caster, target}) );
        dest_effect();
        return;
    } else {
        strength="heavily encases";
        spell_successful();
        tell_object(caster, "%^RESET%^%^CRST%^%^C058%^Your %^C100%^cocoon of refuse %^C058%^"+strength+" "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^ trapping their body!%^CRST%^");
        tell_object(target, "%^RESET%^%^CRST%^%^C058%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^'s %^C100%^cocoon of refuse %^C058%^"+strength+" you, trapping your body!%^CRST%^");
        tell_room(place, "%^RESET%^%^CRST%^%^C058%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^'s %^C100%^cocoon of refuse %^C058%^"+strength+" "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^ trapping their body!%^CRST%^", ({caster,target}) );
        target->set_tripped(roll_dice(1,8));
    }
}

