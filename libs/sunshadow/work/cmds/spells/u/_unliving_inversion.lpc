#include <magic.h>

inherit SPELL;


void create()
{
    ::create();
    set_spell_name("unliving inversion");
    set_spell_level(([ "mage" : 4, "cleric" : 4]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS unliving inversion");
    set_description("With this spell a living being can temporarily invert their energy, taking on the negative energy affinity of an unliving creature.");
    set_save("will");
    set_verbal_comp();
    set_somatic_comp();
}

int preSpell()
{
    if (caster->query_property("negative energy affinity")) {
        tell_object(caster, "%^RESET%^%^C071%^You already have an affinity to %^RESET%^%^C240%^n%^C241%^e%^C242%^g%^C243%^a%^C242%^t%^C241%^i%^C240%^v%^C241%^e %^RESET%^%^C242%^e%^C243%^n%^C242%^e%^C241%^r%^C240%^g%^C241%^y%^RESET%^%^C071%^.%^CRST%^");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    return "%^RESET%^%^C051%^W%^C087%^a%^C123%^v%^C159%^e%^C195%^r%^C159%^i%^C123%^n%^C087%^g%^C051%^l%^C087%^y " + caster->QCN + " %^RESET%^%^C071%^murmurs in %^RESET%^%^C248%^d%^C249%^o%^C250%^l%^C251%^e%^C249%^n%^C248%^t %^RESET%^%^C249%^t%^C250%^o%^C251%^n%^C249%^e%^C248%^s%^RESET%^%^C071%^.%^CRST%^";
}

void spell_effect()
{
    tell_object(caster, "%^RESET%^%^C071%^The currents of %^RESET%^%^C051%^l%^C050%^i%^C086%^f%^C051%^e %^RESET%^%^C071%^and %^RESET%^%^C250%^d%^C251%^e%^C252%^a%^C251%^t%^C250%^h %^RESET%^%^C071%^invert within you.%^CRST%^");
    tell_room(place, "%^RESET%^%^C071%^" + caster->QCN + "%^RESET%^%^C071%^'s skin briefly takes on a %^RESET%^%^C250%^g%^C251%^h%^C252%^o%^C253%^s%^C252%^t%^C251%^l%^C250%^y %^RESET%^%^C250%^p%^C251%^a%^C252%^l%^C253%^l%^C251%^o%^C250%^r%^RESET%^%^C071%^.%^CRST%^", caster);
    caster->set_property("negative energy affinity", 1);
    addSpellToCaster();
    spell_successful();
}

void dest_effect()
{
    if (objectp(caster)) {
        caster->remove_property("negative energy affinity", 1);
        tell_object(caster, "%^RESET%^%^C071%^Your %^RESET%^%^C048%^e%^C049%^n%^C050%^e%^C051%^r%^C050%^g%^C049%^i%^C048%^e%^C047%^s %^RESET%^%^C071%^revert to normal.");
    }
    ::dest_effect();
}
