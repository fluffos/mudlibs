#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

create()
{
    ::create();
    set_spell_name("dictum");
    set_spell_level(([ "cleric" : 7, "inquisitor" : 6, ]));
    set_spell_sphere("invocation_evocation");
    set_domains("law");
    set_syntax("cast CLASS dictum on TARGET");
    set_damage_desc("Staggered, paralyzed and/or death, depending on level difference.");
    set_description("You proclaim a word of power, and stagger, paralyze or kill your target and any other non-lawful targets in the vicinity. Any target that is 10 levels or more less than the caster must make a combat death save or die immediately. If the target is 5 levels or more lower than the caster, they must also make a will save or are stunned for 1d4 rounds (or 1 round if save succeeds). All targets must make a will save or are staggered for 2d4 rounds (1d4 rounds on successful save). All effects listed are concurrent and cumulative. This spell only affects non-lawful targets.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
    splash_spell(2);
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^You can feel an orderly presence building inside.");
    tell_room(place, "%^BOLD%^" + caster->QCN + " chants in an orderly fashion.", caster);
    return "display";
}

int preSpell()
{
    string align;
    
    align = target->query_true_align();
    
    if(align == 1 || align == 2 || align == 3)
    {
        tell_object(caster, "Dictum only affects non-lawful targets!");
        return 0;
    }
    
    return 1;
}

void spell_effect()
{
    int ldiff;
    object *targs;
    
    caster->force_me("yell %^WHITE%^%^BOLD%^DIE!");
    
    targs = target_selector();
    targs = filter_array(targs, (: ($1->query_true_align() != 1 && $1->query_true_align() != 2 && $1->query_true_align() != 3) :));
    
    foreach(object ob in targs)
    {

        ldiff = (clevel - ob->query_level());
        
        if (ldiff > 9)
        {
            if (!combat_death_save(ob, 0))
            {
                tell_room(place, "%^BOLD%^Upon hearing the words, " + ob->QCN + " simply dies!", ob);
                tell_object(ob, "%^BOLD%^YOU OBEY AND DIE.");
                target->cause_typed_damage(ob, "torso", target->query_max_hp() * 2, "untyped");
                dest_effect();
                return;
            }   
        }

        if (ldiff > 4 && !PLAYER_D->immunity_check(ob, "paralysis"))
        {
            int duration;
            tell_room(place, "%^BOLD%^" + ob->QCN + " stops for a moment with a thoughtful expression.", ob);
            tell_object(ob, "%^BOLD%^%^You are stunned by the command.");
            duration = roll_dice(1, 4) * 6;
            if (do_save(ob, 0))
            {
                duration = 6;
            }
            ob->set_paralyzed(duration, "You are stunned by the command you just heard.");
            dest_effect();
            return;
        }

        tell_room(place, "%^BOLD%^" + ob->QCN + " is blasted to the groud with the power of the voice.", ob);
        tell_object(ob, "%^BOLD%^%^You are blasted to the ground with the power of the voice.");
        //target->set_tripped(roll_dice(1, 4), "%^BOLD%^You are trying to regain your footing.");
        if (!do_save(ob, 0))
            find_object("/std/effect/status/staggered")->apply_effect(ob, roll_dice(2, 4));
        else
            find_object("/std/effect/status/staggered")->apply_effect(ob, roll_dice(1, 4));            
        
    }

    dest_effect();
    return;
}
