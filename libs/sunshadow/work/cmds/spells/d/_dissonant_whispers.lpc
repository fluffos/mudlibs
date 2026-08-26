#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("dissonant whispers");
    set_spell_level(([ "bard" : 1 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS dissonant whispers on TARGET");
    set_description("You strike up a discordant, whispering melody that assaults your targets mind. On a failed save, the target takes mental damage. A successful save reduces this mental damage by half.");
    set_verbal_comp();
    mental_spell();
    set_save("will");
    set_target_required(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^"+caster->QCN+" whispers a song.%^RESET%^";
}

spell_effect(int prof)
{    
    string my_name, your_name;
    spell_successful();
    
    my_name = caster->query_cap_name();
    your_name = target->query_cap_name();
    
    tell_room(place, "%^MAGENTA%^BOLD%^" + my_name + " strikes up a discordant whispering melody, assaulting " + your_name + "'s mind!", ({ caster, target }));
    tell_object(caster, "%^MAGENTA%^BOLD%^You strike up a discordant whispering melody, assaulting " + your_name + "'s mind!");
    tell_object(target, "%^MAGENTA%^BOLD%^" + my_name + " strikes up a discordant whispering melody, assaulting your mind!");
    
    if(!do_save(target))
    {
        tell_room(place, "%^RED%^BOLD%^" + your_name + " screams and grabs " + target->query_possessive() + " ears in pain!", target);
        tell_object(target, "%^RED%^BOLD%^You scream and grab your ears in pain!");
        target->cause_typed_damage(target, target->return_target_limb(), sdamage, "mental");
    }
    else
    {
        tell_room(place, "%^MAGENTA%^" + your_name + " seems to shrug off the melody through gritted teeth.", target);
        tell_object(target, "%^MAGENTA%^You shrug off the melody with gritted teeth.");
        target->cause_typed_damage(target, target->query_target_limb(), sdamage / 2, "mental");
    }
    
    TO->dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

