#include <std.h>
#include <daemons.h>
#include <spell.h>
inherit SPELL;

int bonus;

void create() {
    ::create();
    set_spell_name("fiendish vigor");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("necromancy");
    set_heritage("abyssal");
    set_syntax("cast CLASS fiendish vigor [on TARGET]");
    set_damage_desc("clevel hitpoints bonus");
    set_description("The warlock carves several glyphs into their body, strengthening their bond to their patron to increase their own vigor. This spell does not stack with similar effects.");
    set_components(([
      "mage" : ([ "drop of blood":1, "crane's feather":1, ]),
    ]));
	set_helpful_spell(1);
    set_arg_needed(1);
}

int query_fl_power()
{
    return 1;
}

string query_casting_string()
{
    return "%^RESET%^%^CRST%^%^C097%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C097%^ digs into their flesh, carving several %^C196%^b%^C124%^lo%^C196%^od%^C124%^y %^C196%^s%^C124%^i%^C196%^gi%^C124%^l%^C196%^s%^RESET%^%^C097%^.%^CRST%^";
}

int preSpell()
{
    if(!target)
        target = caster;
    if(target->query_property("spell_bonus_hp"))
    {
        tell_object(caster,"%^RESET%^%^CRST%^%^C059%^The spell is repelled by similar magic.%^CRST%^");
        TO->remove();
        return 0;
    }
    return 1;
}

void spell_effect()
{
    if(!target)
        target = caster;

    if(!objectp(target))
    {
        TO->remove();
        return;
    }
    if(!objectp(caster))
    {
        TO->remove();
        return;
    }

    if (caster == target) {
        tell_object(caster,"%^RESET%^%^CRST%^%^C097%^The %^C196%^b%^C124%^lo%^C196%^od%^C124%^y %^C196%^g%^C124%^l%^C196%^yp%^C124%^h%^C196%^s %^RESET%^%^C097%^flare brightly for a moment, searing pain that slowly subsides and is replaced by a renewed %^C091%^vigor%^C097%^.%^CRST%^");
        tell_room(environment(caster),"%^RESET%^%^CRST%^%^C097%^The %^C196%^b%^C124%^lo%^C196%^od%^C124%^y %^C196%^g%^C124%^l%^C196%^yp%^C124%^h%^C196%^s %^RESET%^%^C097%^flare brightly on "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C097%^'s body.%^CRST%^",({caster}));
    } else {
        tell_object(caster,"%^RESET%^%^CRST%^%^C097%^The %^C196%^b%^C124%^lo%^C196%^od%^C124%^y %^C196%^g%^C124%^l%^C196%^yp%^C124%^h%^C196%^s %^RESET%^%^C097%^flare brightly for a moment, and you direct those energies towards "+target->QCN+".%^CRST%^");
        tell_object(target,"%^RESET%^%^CRST%^%^C097%^You feel a strange, alien power flowing from "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C097%^ into you and a renewed sense of %^C091%^vigor%^C097%^.%^CRST%^");
        tell_room(environment(caster),"%^RESET%^%^CRST%^%^C097%^The %^C196%^b%^C124%^lo%^C196%^od%^C124%^y %^C196%^g%^C124%^l%^C196%^yp%^C124%^h%^C196%^s %^RESET%^%^C097%^flare brightly on "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C097%^'s body.%^CRST%^",({target}));
    }
    bonus = query_fl_power()*clevel;
    target->add_max_hp_bonus(bonus);
    target->set_property("spelled",({TO}));
    target->set_property("spell_bonus_hp",1);
    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(target))
    {
       target->add_max_hp_bonus(-bonus);
       target->remove_property_value("spelled", ({TO}) );
       target->remove_property("spell_bonus_hp");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
