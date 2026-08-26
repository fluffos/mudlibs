#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

int bonus, duration;

void create()
{
    ::create();
    set_spell_name("path of shadow");
    set_spell_level(([ "warlock" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS path of shadow");
    set_damage_desc("Fast Healing 2 on caster");
    set_description("The Shadows, bringer of death, but also the embrace of a dark mother. Feed upon the shadows and find yourself nourished.\
\
%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
	set_helpful_spell(1);
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
}

string query_casting_string()
{
    return "%^RESET%^%^CRST%^%^C110%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C110%^ places their hands together, gathering %^C059%^e%^C243%^ld%^C249%^r%^C059%^i%^C243%^tc%^C249%^h %^C059%^e%^C243%^ne%^C249%^r%^C059%^g%^C243%^y %^RESET%^%^C110%^.%^CRST%^";
}

int preSpell()
{
    if(!target)
        target = caster;
    if(target->query_property("fast_healing_spell"))
    {
        tell_object(caster,"%^RESET%^%^CRST%^%^C059%^You feel your spell repelled...%^CRST%^");
        return 0;
    }
    return 1;
}

void spell_effect()
{

    if(!objectp(caster))
    {
        TO->remove();
        return;
    }

    tell_room(place, "%^RESET%^%^CRST%^%^C110%^The surrounding %^C059%^s%^C243%^ha%^C249%^d%^C059%^o%^C243%^ws %^RESET%^%^C110%^feed "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C110%^'s body.%^CRST%^", caster);

    duration = clevel * ROUND_LENGTH * 10;
    tell_object(caster, "%^RESET%^%^CRST%^%^C110%^You feel emboldened by the %^C059%^s%^C243%^ha%^C249%^d%^C059%^o%^C243%^ws %^RESET%^%^C110%^around you.%^CRST%^");
    caster->set_property("spelled",({TO}));
    caster->set_property("fast healing",2);
    caster->set_property("fast_healing_spell",1);
    spell_successful();
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster, "%^RESET%^%^CRST%^%^C110%^The elation you felt begins to ebb as the %^C059%^s%^C243%^ha%^C249%^d%^C059%^o%^C243%^ws %^RESET%^%^C110%^around you %^C243%^d%^C244%^i%^C245%^s%^C246%^s%^C247%^i%^C248%^p%^C249%^a%^C250%^t%^C251%^e%^RESET%^%^C110%^.%^CRST%^");
        caster->remove_property_value("spelled", ({TO}) );
        caster->set_property("fast healing",-2);
        caster->remove_property("fast_healing_spell");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}

