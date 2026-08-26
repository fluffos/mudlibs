#include <spell.h>
#include <magic.h>
inherit SPELL;

int num;

void create()
{
    ::create();
    set_spell_name("thirsting maw");
    set_spell_level(([ "warlock" : 3 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS thirsting maw on TARGET");
    set_heritage("abyssal");
    set_damage_desc("piercing damage over time plus healing to caster");
    set_description("With a flick of the wrist, you create a phantasmal, eel-like creature from your palm and hurl it at your foe. It latches itself to this unfortunate wretch and and begins to drink his blood, granting you newfound vitality. A fortitude save will reduce the duration by half.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string()
{
    return "%^C059%^You utter a %^C065%^foul invocation%^C059%^, calling upon your %^C072%^abyssal%^C059%^ patron.%^CRST%^";
}

spell_effect(int prof)
{
    int heal_amount;
    
    spell_successful();
    tell_object(caster, "%^C060%^You %^C072%^slice%^C066%^ %^C060%^your palm open and pull forth a wriggling %^C078%^abyssal eel%^C060%^, which you toss at %^C078%^" + target->query_cap_name() + "%^C060%^, allowing it to feed on " + target->query_possessive() + " %^C066%^essence%^C060%^!%^CRST%^");
    tell_room(place,"%^C060%^" + caster->query_cap_name() + " %^C072%^slices%^C066%^ %^C060%^" + caster->query_possessive() + " palm open and pulls forth a wriggling %^C078%^abyssal eel%^C060%^, which " + caster->query_subjective() + " tosses at %^C078%^" + target->query_cap_name() + "%^C060%^, allowing it to feed on " + target->query_possessive() + " %^C066%^essence%^C060%^!%^CRST%^", ({ target, caster }));
    tell_object(target,"%^C060%^" + caster->query_cap_name() + " %^C072%^slices%^C066%^ %^C060%^" + caster->query_possessive() + " palm open and pulls forth a wriggling %^C078%^abyssal eel%^C060%^, which " + caster->query_subjective() + " tosses at %^C078%^you%^C060%^, allowing it to feed on your %^C066%^essence%^C060%^!%^CRST%^",target);
    heal_amount = target->cause_typed_damage(target, target->return_target_limb(), sdamage, "piercing");
    caster->add_hp(heal_amount);
    num = clevel / 8 + 1;
    if(do_save(target,0))
        num/=2;
    call_out("bite_again",ROUND_LENGTH);
}

void bite_again()
{
    int heal_amount;
    
    if(!objectp(target))
    {
        dest_effect();
        return;
    }

    if(target->query_hp()<0)
    {
        dest_effect();
        return;
    }

    define_base_damage(0);
    tell_room(environment(target),"%^C066%^The thirsting maw hungrily feeds on %^C078%^" + target->query_cap_name() + "%^C066%^, stealing " + target->query_possessive() + " %^C078%^very essence%^C066%^!%^CRST%^",target);
    tell_object(target,"%^C066%^The thirsting maw hungrily feeds on %^C078%^you%^C066%^, stealing your %^C078%^very essence%^C066%^!%^CRST%^");
    heal_amount = target->cause_typed_damage(target, target->return_target_limb(), sdamage / 6, "piercing");
    target->add_hp(heal_amount);

    if(num-- < 0)
    {
        dest_effect();
        return;
    }
    else
    {
        call_out("bite_again",ROUND_LENGTH);
    }
}

dest_effect()
{
    if(find_call_out("bite_again") != -1)
        remove_call_out("bite_again");

    if(objectp(target))
        tell_object(target,"The abyssal maw stops feeding on you and disappears.");

    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
