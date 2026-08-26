#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("hypnotic pattern");
    set_spell_level((["mage":2,"oracle":2]));
    set_mystery("heavens");
    set_spell_sphere("illusion");
    set_damage_desc("clevel / 8 to perception");
    set_syntax("cast CLASS hypnotic pattern on TARGET");
    set_description("This spell creates a hypnotic pattern in the air, causing the target creature to be fascinated and distracting them from reacting properly. Strong willed creatures may shrug off the pattern.");
    set_save("will");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    mental_spell(1);
}

string query_cast_string()
{
    return "%^MAGENTA%^Hypnotic %^MAGENTA%^s%^BOLD%^%^BLACK%^p%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^s%^WHITE%^ spring into being around "+caster->QCN+".%^RESET%^";
}

int preSpell()
{
    if(target->query_property("fascinated"))
    {
        tell_object(caster,"The target is already fascinated!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int heavens;
    int duration = clevel / 12 + 1;
    
    if(!objectp(caster) || !objectp(target))
        return;
    
    if(caster->query_mystery() == "heavens" && caster->query_class_level("oracle") > 20)
        heavens = BONUS_D->query_stat_bonus(caster, "charisma");

    tell_object(caster,"%^MAGENTA%^You wave your hand and send hypnotic patterns to dance in front of "+target->QCN+"'s eyes");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" waves "+caster->QP+" hand and sends hypnotic pattern to dance in front of "+target->QCN+"'s eyes",caster);
    if(do_save(target,heavens))
    {
        tell_object(target,"%^MAGENTA%^You manage to avert your gaze of the hypnotic pattern.");
        tell_room(place,"%^MAGENTA%^"+target->QCN+" averts their gaze of the hypnotic pattern.",target);
        TO->remove();
        return;
    }
    else
    {
        tell_object(target,"%^BOLD%^%^MAGENTA%^You can not shrug of distracting patterns.");
        tell_room(place,"%^BOLD%^%^MAGENTA%^"+target->QCN+" seems to be fascinated by the pattern.",target);
        target->set_property("fascinated",1);
        bonus = clevel/8+1;
        bonus += heavens;
        target->add_skill_bonus("perception",-bonus);
        spell_duration = duration * ROUND_LENGTH;
        //set_end_time();
        call_out("dest_effect",spell_duration);
    }
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(target))
    {
        tell_object(target,"%^MAGENTA%^Fascinating patterns fade away");
        tell_room(ENV(target),"%^MAGENTA%^Patterns were dancing in front of "+target->QCN+"'s eyes fade away.",target);
        target->remove_property("fascinated");
        target->add_skill_bonus("perception",bonus);
    }
    if(objectp(TO))
        TO->remove();
}
