//removed mention of non-specialized mages ~Circe~ 8/2/19
// midlevel necromancy school specialty spell. Nienne, 08/09.
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

int bonus,i;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("blindness");
    set_spell_level(([ "mage" : 2, "bard" : 2, "paladin" : 3, "inquisitor" : 3, "cleric" : 3 ]));
    set_spell_sphere("necromancy");
    set_domains("darkness");
    set_syntax("cast CLASS blindness on TARGET");
    set_description("By means of this spell, the caster attempts to steal the target's vision. It is "
"not a curse, nor it is dispellable by normal magics, but it will fade after a short while.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string() {
    return "%^RESET%^%^C244%^"+caster->QCN+" %^RESET%^%^C045%^h%^C051%^i%^C087%^s%^C081%^s%^C075%^e%^RESET%^%^C069%^s %^RESET%^%^C244%^the syllables of a spell.%^CRST%^";
}

void spell_effect(int prof) {
    int duration;
    if(target == caster) {
        tell_object(caster, "%^RESET%^%^C244%^You realise the error in directing the spell at yourself, and let it f%^RESET%^%^C246%^a%^C248%^d%^C250%^e%^RESET%^%^C244%^.%^CRST%^");
        tell_room(place,"%^RESET%^%^C244%^"+caster->QCN+"%^RESET%^%^C244%^'s spell %^RESET%^%^C250%^s%^C251%^o%^C252%^f%^C253%^t%^C251%^l%^C250%^y %^RESET%^%^C250%^s%^C251%^n%^C252%^u%^C253%^f%^C251%^f%^RESET%^%^C250%^s %^RESET%^%^C244%^out.%^CRST%^",caster);
        TO->remove();
        return;
    }
    if(target->query_blind() || target->query_temporary_blinded()) {
        tell_object(caster,"%^RESET%^%^C244%^The %^RESET%^%^C045%^s%^C051%^i%^C087%^g%^C051%^h%^RESET%^%^C045%^t %^RESET%^%^C244%^is already gone from "+target->QCN+"%^RESET%^%^C244%^'s eyes!%^CRST%^");
        tell_room(place,"%^RESET%^%^C244%^"+caster->QCN+"%^RESET%^%^C244%^'s spell %^RESET%^%^C250%^s%^C251%^o%^C252%^f%^C253%^t%^C251%^l%^C250%^y %^RESET%^%^C250%^s%^C251%^n%^C252%^u%^C253%^f%^C251%^f%^RESET%^%^C250%^s %^RESET%^%^C244%^out.%^RESET%^",caster);
        TO->remove();
        return;
    }
    if(do_save(target)){
        tell_object(target,"%^RESET%^%^C244%^Your %^RESET%^%^C087%^v%^C123%^i%^C159%^s%^C195%^i%^C123%^o%^RESET%^%^C087%^n %^RESET%^%^C244%^becomes momentarily %^RESET%^%^C241%^h%^C242%^a%^C243%^z%^RESET%^%^C241%^y%^RESET%^%^C244%^, but you manage to %^RESET%^%^C220%^r%^C226%^e%^C227%^-%^C228%^f%^C229%^o%^C227%^c%^C226%^u%^C220%^s%^RESET%^%^C244%^.%^CRST%^");
        tell_room(place,"%^RESET%^%^C244%^"+target->QCN+" %^RESET%^%^C244%^hesitates, but then shakes off the spell.%^CRST%^",target);
        TO->remove();
        return;
    }
    tell_object(target,"%^RESET%^%^C244%^Your %^RESET%^%^C087%^v%^C123%^i%^C159%^s%^C195%^i%^C123%^o%^RESET%^%^C087%^n %^RESET%^%^C244%^becomes %^RESET%^%^C250%^hazy %^RESET%^%^C244%^and the world around you f%^RESET%^%^C243%^a%^C242%^d%^C241%^e%^C240%^s %^RESET%^%^C244%^into %^RESET%^%^C250%^g%^C249%^r%^C249%^a%^C250%^y%^RESET%^%^C244%^.%^CRST%^");
    tell_room(place,"%^RESET%^%^C244%^"+target->QCN+" %^RESET%^%^C087%^b%^C123%^l%^C159%^i%^C195%^n%^C123%^k%^C087%^s%^RESET%^%^C244%^, and then stares around %^RESET%^%^C240%^sightlessly%^RESET%^%^C244%^.%^CRST%^",target);
    target->set_temporary_blinded(roll_dice(2,4));
    spell_successful();
    dest_effect();
}
