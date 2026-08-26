#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
#include <skills.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("soul flaying");
    set_spell_level(([ "warlock" : 3 ]));
    set_heritage("infernal");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS soul flaying on TARGET");
    set_damage_desc("negative energy damage, reduced saves, attack, clevel");
    set_description("You intrusively reach into your opponent's soul, poring through it's worthless history and experiences, using their worst fears against them. As you shred their soul, they are met with unbearable terror and despair, and experience unimaginable agony. The target takes negative energy damage and must make a will save or suffer penalties to their attack, damage, caster level and saving throws for a short time.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    mental_spell(1);
    set_save("will");
}

string query_cast_string()
{
    return "%^C166%^" + caster->query_cap_name() + "%^C244%^ utters a dark and forbidding invocation.%^CRST%^";
}

void spell_effect(int prof)
{
    string my_name, your_name, your_poss, my_poss;
    int duration;
    
    my_name = caster->query_cap_name();
    your_name = target->query_cap_name();
    my_poss = caster->query_possessive();
    your_poss = target->query_possessive();
    
    tell_object(caster, "You cast out your invocation that latches onto " + your_name + ", feverishly seeking out " + your_poss + " soul.");
    tell_object(target, "" + my_name + " casts out an invocation that latches onto you, feverishly seeking out your soul!");
    tell_room(place, "" + my_name + " casts out " + caster->query_possessive() + " invocation that latches onto " + your_name + ", feverishly seeking out " + your_poss + " soul.", ({ target, caster }));
    
    if(target == caster)
    {
        tell_object(caster, "%^CYAN%^You cannot target yourself.%^RESET%^");
        tell_room(place,"%^CYAN%^The aura around "+caster->QCN+"'s hands weakens and then fades away.%^RESET%^",caster);
        TO->remove();
        return;
    }
    if(target->query_property("soul flaying"))
    {
        tell_object(caster,"%^CYAN%^You cannot flay their soul any further!%^RESET%^");
        TO->remove();
        return;
    }
    
    damage_targ(target, target->return_target_limb(), sdamage, "negative energy");
    
    if (do_save(target, 0) || mind_immunity_damage(target))
    {
        tell_object(target, "%^YELLOW%^With incredible agony, you manage to fight off the flaying of your soul!%^RESET%^");
        tell_room(place, "%^BOLD%^Seems to resist the flaying of " + target->query_possessive() + " soul!%^RESET%^", target);
        TO->remove();
        return;
    }
    bonus = clevel/8;
    duration = (ROUND_LENGTH) * (clevel / 12 + 1);

    tell_object(target,"%^C244%^A %^C135%^dark%^C244%^ and h%^C246%^o%^C248%^r%^C135%^r%^C141%^i%^C147%^f%^C141%^y%^C135%^i%^C244%^ng presence grasps your %^C147%^soul%^C244%^ tightly in its s%^C246%^i%^C248%^n%^C250%^i%^C248%^s%^C246%^t%^C244%^er grip. Layer by layer, you feel the %^C147%^veneer%^C244%^ of your soul peeled away and your %^C147%^essence%^C244%^ laid bare. You feel an immense w%^C246%^e%^C248%^a%^C141%^k%^C147%^n%^C141%^e%^C135%^s%^C244%^s of %^C135%^body%^C244%^, %^C147%^mind%^C244%^ and %^C153%^spirit%^C244%^ overtake you, leaving you vulnerable.%^CRST%^");
    tell_room(place,"%^C244%^" + your_name + " seems overtaken by the invocation and shudders in pure terror and suffering, leaving " + target->query_objective() + " weakened and vulnerable.%^CRST%^",target);
    target->add_damage_bonus((-1) * bonus);
    target->add_attack_bonus((-1) * bonus);
    target->set_property("empowered", (-1) * bonus);

    caster->add_saving_bonus("all", (-1) * bonus);
    target->set_property("soul flaying", 1);
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}

void dest_effect()
{
    if(objectp(target))
    {
        tell_object(target,"%^BOLD%^You feel your soul recover from being flayed.%^RESET%^");
        tell_room(environment(target),"%^BOLD%^" + target->query_cap_name() + " seems to recover from intense spiritual anguish.%^RESET%^",target);
        target->add_damage_bonus(bonus);
        target->add_attack_bonus(bonus);
        target->set_property("empowered",bonus);
        caster->add_saving_bonus("all",bonus);
        target->remove_property("soul flaying");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
