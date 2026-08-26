/*
  bitter_failure.c
  
  Sickened and shaken.
  Permanent if failed save. Else clevel rounds.
  Failed save also applies a random spellblight (separate system)
  
  -- Tlaloc --
*/
  
#include <std.h>
#include <daemons.h>

inherit CURSE;

object sicken, shaken;

void create()
{
    ::create();
    set_name("bitter failure");
    set_damage_desc("Shaken and sickened");
    set_description("Your mind and body are wracked with anguish and suffering over every bitter failure you will ever experience, rendering you permanently shaken and sickened. A successful Will save will reduce the duration to one round per power level of the curse (clevel).");
    set_heart_beat(3);
}

void start_curse()
{
    if(!victim->query_property("effect_sickened"))
    {
        sicken = load_object("/std/effect/status/sickened");
        objectp(sicken) && sicken->apply_effect(victim, 100);
    }

    if(!victim->query_property("effect_shaken"))
    {
        shaken = load_object("/std/effect/status/shaken");
        objectp(shaken) && shaken->apply_effect(victim, 100);
    }
    
    if(SAVING_THROW_D->will_save(victim, power + caster->query_property("spell dcs")))
        call_out("end_curse", power * 6);
}

void heart_beat()
{
    if(!living(victim))
        return;
    
    if(!victim->query_property("effect_sickened"))
    {
        sicken = load_object("/std/effect/status/sickened");
        objectp(sicken) && sicken->apply_effect(victim, 100);
    }

    if(!victim->query_property("effect_shaken"))
    {
        shaken = load_object("/std/effect/status/shaken");
        objectp(shaken) && shaken->apply_effect(victim, 100);
    }
}

void end_curse()
{
    object *effects;
    
    if(objectp(victim))
    {
        effects = victim->query_property("status_effects");
        effects = filter_array(effects, (: ($1->query_name() == "effect_shaken" || $1->query_name() == "effect_sickened") :));
        
        foreach(object ob in effects)
            ob->dest_effect(victim);
    }
    
    this_object()->remove();
}

        