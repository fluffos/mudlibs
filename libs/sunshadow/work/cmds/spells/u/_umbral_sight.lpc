#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

int modifier;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("umbral sight");
    set_spell_level(([ "innate" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS umbral sight");
    set_description("This spell will imbue the caster's vision with the stuff of darkness, allowing them to see easily "
"even in deep shadow. It will similarly protect their vision from extremes of light.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^RESET%^%^C244%^P%^C243%^a%^C242%^s%^C241%^s%^C242%^i%^C243%^n%^RESET%^%^C244%^g a hand %^RESET%^%^C241%^over %^RESET%^%^C244%^your eyes, you draw upon the %^RESET%^%^C240%^s%^C241%^h%^C242%^a%^C243%^d%^C244%^o%^C243%^w %^RESET%^%^C242%^w%^C241%^e%^C240%^a%^C241%^v%^C242%^e %^RESET%^%^C244%^to %^RESET%^%^C240%^s%^C241%^h%^C242%^r%^C243%^o%^C241%^u%^C240%^d %^RESET%^%^C244%^your %^RESET%^%^C087%^v%^C123%^i%^C159%^s%^C195%^i%^C123%^o%^C087%^n%^RESET%^%^C244%^.%^CRST%^");
    tell_room(place,"%^RESET%^%^C244%^"+caster->QCN+" %^RESET%^%^C244%^p%^C243%^a%^C242%^s%^C241%^s%^C243%^e%^RESET%^%^C244%^s a hand %^RESET%^%^C241%^over %^RESET%^%^C244%^"+caster->QP+" %^RESET%^%^C244%^eyes and %^RESET%^%^C087%^f%^C123%^o%^C159%^c%^C195%^u%^C159%^s%^C123%^e%^C087%^s %^RESET%^%^C244%^intently.%^CRST%^",caster);
    return "display";
}

int preSpell() {
    if(caster->query_property("darkvision")) {
        tell_object(caster,"Your senses are already heightened.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    int duration;
    duration = (ROUND_LENGTH * 20) * (clevel + roll_dice(1, 20));

    if(member_array((string)caster->query_race(),PLAYER_D->night_races()) != -1) modifier = -10;
    else modifier = 8;
    tell_room(place,"%^RESET%^%^C244%^"+caster->QCN+"%^RESET%^%^C244%^'s %^RESET%^%^C241%^pupils %^RESET%^%^C244%^dilate, their %^RESET%^%^C240%^blackness %^RESET%^%^C251%^o%^C250%^v%^C249%^e%^C248%^r%^C247%^w%^C246%^h%^C245%^e%^C244%^l%^C243%^m%^C242%^i%^C241%^n%^C240%^g %^RESET%^%^C244%^all %^RESET%^%^C196%^c%^C208%^o%^C226%^l%^C118%^o%^C051%^r %^RESET%^%^C244%^in the irises.%^CRST%^",caster);
    tell_object(caster,"%^RESET%^%^C244%^The %^RESET%^%^C038%^w%^C037%^o%^C036%^r%^C035%^l%^C034%^d %^RESET%^%^C244%^around you %^RESET%^%^C245%^d%^C244%^r%^C243%^a%^C242%^i%^C241%^n%^C240%^s %^RESET%^%^C244%^of %^RESET%^%^C196%^c%^C208%^o%^C226%^l%^C118%^o%^C051%^r %^RESET%^%^C244%^and snaps into %^RESET%^%^C051%^c%^C087%^r%^C123%^y%^C159%^s%^C195%^t%^C159%^a%^C123%^l%^C087%^l%^C051%^i%^C087%^n%^C123%^e %^RESET%^%^C159%^c%^C195%^l%^C159%^a%^C123%^r%^C087%^i%^C051%^t%^C087%^y%^RESET%^%^C244%^.%^RESET%^");
    addSpellToCaster();
    spell_successful();
    caster->add_sight_bonus(modifier);
    caster->set_property("spelled",({TO}));
    caster->set_property("darkvision",1);
}

void dest_effect() {
    if(objectp(caster)) {
        tell_object(caster,"%^RESET%^%^C244%^You %^RESET%^%^C251%^b%^C252%^l%^C253%^i%^C252%^n%^C251%^k%^RESET%^%^C244%^ and the %^RESET%^%^C196%^c%^C208%^o%^C226%^l%^C118%^o%^C051%^r %^RESET%^%^C244%^floods back into your vision as it loses its %^RESET%^%^C087%^c%^C123%^l%^C159%^a%^C195%^r%^C159%^i%^C123%^t%^C087%^y%^RESET%^%^C244%^.");
        tell_room(environment(caster),"%^RESET%^%^C244%^"+caster->QCN+" %^RESET%^%^C251%^b%^C252%^l%^C253%^i%^C252%^n%^C251%^k%^RESET%^%^C252%^s %^RESET%^%^C244%^and suddenly, %^RESET%^%^C244%^"+caster->QP+" %^RESET%^%^C244%^eyes look normal again.%^CRST%^",caster);
        caster->add_sight_bonus(-1*modifier);
        caster->remove_property("darkvision");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
