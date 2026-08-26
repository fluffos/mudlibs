/*
  _coat_of_many_stars.c
  
  Heavens mystery innate power.
  
  -- Tlaloc --
*/

#include <spell.h>
#include <daemons.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("coat of many stars");
    set_spell_level(([ "innate" : 1 ]));
    set_spell_sphere("illusion");
    set_mystery("heavens");
    set_syntax("cast CLASS coat of many stars");
    set_bonus_type(({ "armor" }));
    set_damage_desc("clevel / 10 + 1 to AC. clevel / 10 + 1 to influence skill");
    set_description("You conjure a coat of starry radiance, protecting you from physical attacks and increasing your impact on those around you.");
    //set_verbal_comp();
    //set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^YELLOW%^" + caster->query_cap_name() + " begins to call on the heavens.%^RESET%^";
}

void spell_effect(int prof)
{   
    if(!objectp(caster))
        return;
    
    spell_successful();
    
    bonus = clevel / 10 + 1;
    caster->add_ac_bonus(bonus);
    caster->add_skill_bonus("influence", bonus);
    
    tell_object(caster, CRAYON_D->color_string("You draw on the stars in the heavens conjuring a protective coat around you.", "very black"));
    tell_room(place, CRAYON_D->color_string(caster->query_cap_name() + " draws on heavens, protecting  " + caster->query_objective() + " in a coat of stars.", "very black"), caster);
    
    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster, "%^YELLOW%^BOLD%^The coat of stars slips from around you.%^RESET%^");
        caster->add_ac_bonus(-bonus);
        caster->add_skill_bonus("influence", -bonus);
    }
    
    ::dest_effect();
}
    
    
    

    