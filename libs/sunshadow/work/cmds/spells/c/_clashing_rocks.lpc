#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;


void create()
{
    ::create();
    set_spell_name("clashing rocks");
    set_spell_level(([ "mage" : 9, "druid":9,]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS clashing rocks on TARGET");
    set_damage_desc("bludgeoning");
    set_description("You conjure two colossal rocks and smash them together around your target, rolling a ranged touch attack to cause bludgeoning damage to the target. When the rocks smash together, they cause an avalanche of stone which threatens anyone nearby with splash damage. Each must roll a reflex save to avoid half of the damage. Each victim who fails the save is tripped.");
    set_save("reflex");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
}

string query_cast_string()
{
    return "%^ORANGE%^" + caster->QCN + " closes " + caster->QP + " eyes clenches " + caster->QP + " fists!";
}

void spell_effect(int prof)
{
    int roll;
    object *targets;
    
    ::spell_effect();
    
    spell_kill(target, caster);
    targets = target_selector();
    
    tell_object(caster, "%^BOLD%^You raise your clenched fists and two enormous rocks rise from the ground and smash together around " + target->QCN);
    tell_room(place, "%^BOLD%^Two enormous rocks rise from the ground and smash together around " + target->QCN, caster);
    
    if(BONUS_D->process_hit(caster, target, 1, 0, 0, 1) < 1)
    {
        tell_object(target, "%^ORANGE%^You barely make an escape from the clashing rocks!.");
        tell_room(place, "%^ORANGE%^" + target->QCN + " avoids the clashing rocks!", ({ target }));
    }   
    else
    {
        tell_object(target, "%^ORANGE%^The giant rocks SMASH you between then!");
        tell_room(place, target->query_cap_name() + " is SMASHED between the rocks!", target);
        targets -= ({ target });
        target->cause_typed_damage(target, "torso", sdamage, "bludgeoning");
    }
    
    tell_room(place, "%^ORANGE%^Fragments of the rocks fall, threatening to crush anyone nearby beneath them!");
        
    foreach(object ob in targets)
    {
        if(!objectp(ob))
            continue;
        
        if(do_save(ob, 0))
        {
            tell_room(place, ob->query_cap_name() + " avoids most of the falling rocks.", ob);
            tell_object(ob, "You avoid most of the falling rocks.");
            ob->cause_typed_damage(ob, "torso", sdamage / 4, "bludgeoning");
        }
        else
        {
            tell_room(place, ob->query_cap_name() + " is crushed under the falling rocks!", ob);
            tell_object(ob, "%^ORANGE%^You are crushed under the falling rocks!");
            ob->set_tripped(roll_dice(1, 4) * 6, "You are trapped under the fallen rocks!");
            ob->cause_typed_damage(ob, "torso", sdamage / 2, "bludgeoning");
        }
    }
            
    this_object()->remove();
    
    return 1;
}
