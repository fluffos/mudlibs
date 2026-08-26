/*
  _power_leech.c
  
  Rewrite to more closely match source material.
  
  -- Tlaloc --
*/

#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("power leech");
    set_spell_level(([ "psion" : 4 ]));
    set_spell_sphere("telepathy");
    set_syntax("cast CLASS power leech on TARGET");
    set_description("With this power the psion reaches out and taps into their target's latent psychic energy, stealing some of it and adding it to their reserves. This spell will directly damage the target's power point pool and add a portion of that to their own pool. A will save by the target will halve the amount of power points transferred.");
    mental_spell();
    set_save("will");
    set_target_required(1);
}

void spell_effect()
{
    int maxmp, mp;
    
    maxmp = target->query_mp();
    
    if(!maxmp)
    {
        tell_object(caster, "You reach out to your target's mind but find no psychic power there.");
        dest_effect();
        return;
    }
    
    spell_successful();
    
    mp = 4 + roll_dice(clevel / 2, 6);
    mp = min( ({ mp, maxmp }) );
    
    tell_object(caster, "%^CYAN%^BOLD%^You reach into " + target->query_cap_name() + "'s mind, tapping into " + target->query_possessive() + " latent psychic energy, tearing it away and absorbing it as your own.%^RESET%^");
    tell_object(target, "%^CYAN%^BOLD%^" + caster->query_cap_name() + " reaches into your mind, tapping into your latent psychic energy, tearing it away and absorbing it as " + caster->query_possessive() + " own.%^RESET%^");
    
    if(do_save(target, 0))
    {
        tell_object(caster, "%^BOLD%^" + target->query_cap_name() + " resists some of the psychic attack.%^RESET%^");
        tell_object(target, "%^BOLD%^You resist some of the psychic attack.%^RESET%^");
        mp /= 2;
    }
    
    target->add_mp(-mp);
    caster->add_mp(mp / 2);
    dest_effect();
    return;
}