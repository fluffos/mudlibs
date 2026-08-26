#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

string * GIBBERISH = ({
            "Bye!",
            "Do you respect me?!",
            "Great pillows!",
            "I am the king! Kneel!",
            "I am the queen! Kneel!",
            "I like heat in a certain way!",
            "I love you!",
            "I really don't!",
            "I reject your accusations!",
            "I stink!",
            "It's a rough situation over here!",
            "Join me, I have cookies!",
            "Let me join you!",
            "Look! Over there!",
            "No collusion!",
            "Nobody knows what who knows!",
            "Our country is the best!",
            "The moon is fluffy today!",
            "Together we will make the world great again!",
            "We all are fighting battles!",
            "What's happening is a disgrace!",
            "Who knows, you know?!",
            "You know what you know you know?!",
            "You stink!",
            "You're mean! Bye!",
            "Your shoes are untied!",
            "Your mother was a hamster!",
            "You father smelt of elderberries!",
            "I fart in your general direction!",
            "Klaatu barada nikto",
            "Are you threatening me?",
                });

create()
{
    ::create();
    set_spell_name("word of chaos");
    set_spell_level(([ "cleric" : 7, "inquisitor" : 6 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS word of chaos on TARGET");
    set_damage_desc("Death, paralyzed and/or confused depending on level difference");
    set_description("You shout some gibberish. All non-chaotic targets in the immediate area must make an immediate save or suffer from confusion for 2d4 rounds (1 round if save succeeds). Targets 5 levels below the caster will also be stunned for 1d4 rounds (1 round on successful save). Finally, any targets 10 levels below the caster must also make a combat death save or immediately die.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
    splash_spell(2);
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^You can feel a chaotic presence building inside as you chant the words of chaos.");
    tell_room(place,"%^BOLD%^"+caster->QCN+" chants some gibberish.",caster);
    return "display";
}

int preSpell()
{
    string align;
    
    align = target->query_true_align();
    
    if(align == 7 || align == 8 || align == 8)
    {
        tell_object(caster, "Word of Chaos only affects non-chaotic targets!");
        return 0;
    }
    
    return 1;
}

void spell_effect()
{
    int ldiff;
    object *targs;
    
    caster->force_me("yell %^WHITE%^%^BOLD%^"+GIBBERISH[random(sizeof(GIBBERISH))]);
    
    targs = target_selector();
    targs = filter_array(targs, (: ($1->query_true_align() != 7 && $1->query_true_align() != 8 && $1->query_true_align() != 9) :));
    
    foreach(object ob in targs)
    {

        ldiff = (clevel - ob->query_level());
        
        if (ldiff > 9 && !combat_death_save(ob, 0))
        {
            tell_room(place,"%^BOLD%^Upon hearing the words "+ob->QCN+" simply explodes!",ob);
            tell_object(ob,"%^BOLD%^WHAT "+caster->QS+" DID JUST SAY");
            damage_targ(ob,ob->return_target_limb(),ob->query_max_hp()*2,"mental");
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

        if(!PLAYER_D->immunity_check(ob, "confusion"))
        {
            if (!do_save(ob, 0))
                "/std/effect/status/confused"->apply_effect(ob, roll_dice(2, 4));
            else
                "/std/effect/status/confused"->apply_effect(ob, 1);
        }
    }

    dest_effect();
    return;
}