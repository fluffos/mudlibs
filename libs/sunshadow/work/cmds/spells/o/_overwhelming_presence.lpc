#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int wisdamage;
object *targets, *recovered;

void create() {
    ::create();
    set_spell_name("overwhelming presence");
    set_spell_level(([ "cleric" : 9, "bard" : 6, "mage" : 9, "inquisitor" : 6, "oracle" : 9, "psion" : 9 ]));
    set_spell_sphere("enchantment_charm");
    set_mystery("dragon");
    set_discipline("telepath");
    set_syntax("cast CLASS overwhelming presence");
    set_damage_desc("AOE paralysis");
    set_description("Your presence inspires incredible awe in your enemies. Those who fail to make a will save are struck with awe and fall to their knees, paralyzed, in worship. Each round, they attempt another will save. If they succeed the will save and end the paralysis early, they are staggered for 1d4 rounds and take 1d6 wisdom damage until the overwhelming presence ends. If a target succeeds the initial save they are only staggered for one round. Targets with immunity to charm effects will not be affected by this spell.");
    mental_spell();
    splash_spell(3);
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
}

string query_cast_string()
{
    return "%^YELLOW%^"+caster->QCN+" proclaims an inspiring spell.";
}

void spell_effect(int prof)
{
    string c_name;
    int count;
    
    targets = target_selector();
    targets -= ({ caster });
    c_name = caster->query_cap_name();
    recovered = ({  });
    
    tell_room(place, "%^BOLD%^" + c_name + " lets loose a wave of unspeakable splendor!", caster);
    tell_object(caster, "%^BOLD%^You let loose a wave of unspeakable splendor on your foes.");
    
    if(!sizeof(targets))
    {
        tell_object(caster, "There are no enemies here.");
        dest_effect();
        return;
    }
    
    ::spell_effect();
    
    count = 1 + clevel / 6;
    
    foreach(object ob in targets)
    {
        if(ob->query_property("overwhelming presence"))
            continue;
        
        if(!do_save(ob) && !PLAYER_D->immunity_check("charm") && !mind_immunity_check(ob))
        {
            ob->set_paralyzed(count * ROUND_LENGTH, "%^YELLOW%^You are completely stunned with awe!%^RESET%^");
            tell_object(ob, "%^YELLOW%^You are struck with unspeakable awe and drop your knees to worship " + c_name + "!%^RESET%^");
            tell_room(place, "%^BOLD%^" + ob->query_cap_name() + " falls to " + ob->query_possessive() + " knees in worship!", ob);
            ob->set_property("overwhelming presence", 1);
        }
        else
        {
            tell_object(ob, "%^MAGENTA%^You manage to shrug off the feeling of overwhelming awe!%^RESET%^");
            tell_room(place, "%^MAGENTA%^" + ob->query_cap_name() + " manages to shrug off the feeling of overwhelming awe!%^RESET%^", ob);
            "/std/effect/status/staggered"->apply_effect(ob, 1, caster);
            targets -= ({ ob });
        }
    }
    
    wisdamage = roll_dice(1, 6);
    
    if(sizeof(targets))
        call_out("check_awe", ROUND_LENGTH, count);
    else
        dest_effect();
}

void check_awe(int count)
{   
    foreach(object ob in targets)
    {
        if(!objectp(ob))
        {
            targets -= ({ ob });
            continue;
        }
        
        if(do_save(ob, 0) || !(ob->query_paralyzed())) //removing the paralyzation is "recovered"
        {
            ob->set_paralyzed(0);
            tell_object(ob, "%^MAGENTA%^You collect yourself and begin to stand.%^RESET%^");
            tell_room(place, "%^MAGENTA%^" + ob->query_cap_name() + " collects themselves and begins to stand.%^RESET%^", ob);
            "/std/effect/status/staggered"->apply_effect(ob, roll_dice(1, 4), caster);
            ob->add_stat_bonus("wisdom", -wisdamage);
            recovered += ({ ob }); //If they recover before spell wears off
            targets -= ({ ob });
        }
        else
        {
            tell_object(ob, "%^CYAN%^You push yourself lower to the ground in worship of " + caster->query_cap_name() + ".%^RESET%^");
            tell_room(place, "%^CYAN%^" + ob->query_cap_name() + " bows lower in worship.%^RESET%^", ob);
        }
    }
    
    if(!sizeof(targets))
    {
        dest_effect();
        return;
    }
    
    count--;
    
    if(count < 1)
    {
        dest_effect();
        return;
    }
    
    call_out("check_awe", ROUND_LENGTH, count);
}

dest_effect()
{
    foreach(object ob in recovered)
    {
        if(!objectp(ob))
            continue;
        
        ob->add_stat_bonus("wisdom", wisdamage);
    }
    
    foreach(object ob in targets)
    {
        if(!objectp(ob))
            continue;
        
        ob->remove_property("overwhelming presence");
    }
    
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
