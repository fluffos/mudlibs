/*
  _hideous_blow.c
  
  Optional feat that does a physical attack but applies all purchased
  blast type effects in addition.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

#define COOLDOWN 40

inherit FEAT;

object *weapons, weapon;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("PactInvocation");
    feat_name("hideous blow");
    feat_syntax("hideous_blow [TARGET]");
    feat_desc("With this feat you strike your opponent with your weapon, causing weapon damage plus a bonus amount of damage based on your purchased blast types. For instance, if you have purchased the lifedrinker, brimstone and vitriolic invocation feats, this feat will deal additional negative energy, fire, and acid damage. This feat requires a melee weapon to be wielded.");
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob))
        return 0;
    
    if (!ob->is_class("warlock"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_hideous_blow(string str)
{
    object feat;
    
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
    return 1;
}

void execute_feat()
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    
    if ((int)caster->query_property("using instant feat"))
    {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if (caster->query_casting())
    {
        tell_object(caster, "%^BOLD%^You are already in the middle of casting a spell.%^RESET%^");
        dest_effect();
        return;
    }
    if(!sizeof(weapons = caster->query_wielded()))
    {
        tell_object(caster, "You need a weapon to use hideous blow.");
        dest_effect();
        return;
    }
    if(caster->cooldown("hideous blow"))
    {
        tell_object(caster, "You aren't ready to use hideous blow yet.");
        dest_effect();
        return;
    }
    
    weapon = weapons[0];
    
    if(weapon->is_lrweapon())
        if(sizeof(weapons) > 1)
            weapon = weapons[1];
        
    if(weapon->is_lrweapon())
    {
        tell_object(caster, "You need a melee weapon to use hideous blow.");
        dest_effect();
        return;
    }
    
    ::execute_feat();
    
    if(!objectp(target))
        target = caster->query_current_attacker();
    if(!objectp(target) || !present(target, place))
    {
        tell_object(caster, "Your target is not here.");
        dest_effect();
        return;
    }
    
    if(target == caster)
    {
        tell_object(caster, "You can't target yourself.");
        dest_effect();
        return;
    }
    
    caster->use_stamina(roll_dice(1, 6));
    caster->set_property("using instant feat", 1);
    spell_kill(target, caster);
    
    tell_object(caster, "%^C244%^You infuse your weapon with chaotic e%^C145%^l%^C151%^d%^C157%^r%^C244%^itch e%^C145%^n%^C151%^e%^C157%^r%^C244%^gy and levy a h%^C145%^i%^C151%^d%^C157%^e%^C244%^ous b%^C145%^l%^C151%^o%^C244%^w at %^C151%^" + target->query_cap_name() + ".%^CRST%^");
    tell_object(target, "%^C244%^" + caster->query_cap_name() + " infuses " + caster->query_possessive() + " weapon with chaotic e%^C145%^l%^C151%^d%^C157%^r%^C244%^itch e%^C145%^n%^C151%^e%^C157%^r%^C244%^gy and levies a h%^C145%^i%^C151%^d%^C157%^e%^C244%^ous b%^C145%^l%^C151%^o%^C244%^w at you!%^CRST%^");
    tell_room(place, "%^C244%^" + caster->query_cap_name() + " infuses " + caster->query_possessive() + " weapon with chaotic e%^C145%^l%^C151%^d%^C157%^r%^C244%^itch e%^C145%^n%^C151%^e%^C157%^r%^C244%^gy and levies a h%^C145%^i%^C151%^d%^C157%^e%^C244%^ous b%^C145%^l%^C151%^o%^C244%^w at %^C151%^" + target->query_cap_name() + ".%^CRST%^", ({ caster, target }));
}

void execute_attack()
{
    int glvl, mod, roll, dmg;
    string my_name, your_name, wepname;
    
    if(!caster || caster->query_unconscious())
    {
        dest_effect();
        return;
    }

    caster->remove_property("using instant feat");
    
    ::execute_attack();
    
    if(!target)
        target = caster->query_current_attacker();
    
    if(!objectp(target) || !present(target, place))
    {
        tell_object(caster, "Your target is no longer here.");
        dest_effect();
        return;
    }
    
    if(!objectp(weapon))
    {
        tell_object(caster, "You have no weapon!");
        dest_effect();
        return;
    }
    
    caster->add_cooldown("hideous blow", COOLDOWN);
    
    roll = (int)BONUS_D->process_hit(caster, target, 1, 0, 0, 0);
    
    if(!roll)
    {
        tell_object(caster, "%^WHITE%^" + target->QCN + " jumps aside and avoids your hideous blow!%^RESET%^");
        tell_object(target, "%^WHITE%^You jump aside and avoid the hideous blow!%^RESET%^");
        tell_room(place, target->QCN + " jumps aside and avoids the hideous blow!", ({ caster, target }));
        return;
    }
    
    glvl = caster->query_guild_level("warlock");
    mod = weapon->query_wc();
    mod += weapon->query_property("enchantment");
    mod += BONUS_D->query_stat_bonus(caster, "charisma") * FEATS_D->has_feat(caster, "agonizing blast");
    wepname = weapon->query_name();
    my_name = caster->query_cap_name();
    your_name = target->query_cap_name();
    
    tell_object(caster, "%^C244%^You strike %^C151%^" + your_name + "%^C244%^ with an incredible blow, channeling your %^C133%^d%^C139%^a%^C145%^r%^C133%^k e%^C139%^n%^C145%^e%^C151%^r%^C145%^g%^C133%^y%^C244%^ through your weapon!%^CRST%^!");
    tell_object(target, "%^C151%^" + my_name + "%^C244%^ strikes you with an incredible blow, channeling %^C133%^dark energy%^C244%^ through " + caster->query_possessive() + " weapon!%^CRST%^");
    tell_room(place, "%^C151%^" + my_name + "%^C244%^ strikes %^C151%^" + your_name + "%^C244%^ with an incredible blow, channeling %^C139%^dark energy%^C244%^ through " + caster->query_possessive() + " weapon!%^CRST%^", ({ caster, target }));
    
    target->cause_typed_damage(target, target->return_target_limb(), 10 + roll_dice(glvl, 4) + mod, weapon->query_damage_type());
    
    if(FEATS_D->has_feat(caster, "lifedrinker blast") && objectp(target))
    {
        target->cause_typed_damage(target, target->query_target_limb(), roll_dice(1, glvl), "negative energy");
        caster->add_hp(glvl);
    }
    if(objectp(target) && FEATS_D->has_feat(caster, "brimstone blast"))
        target->cause_typed_damage(target, target->return_target_limb(), 5 + roll_dice(1, glvl), "fire");
    if(objectp(target) && FEATS_D->has_feat(caster, "glacial blast"))
        target->cause_typed_damage(target, target->return_target_limb(), 5 + roll_dice(1, glvl), "cold");
    if(objectp(target) && FEATS_D->has_feat(caster, "vitriolic blast"))
        target->cause_typed_damage(target, target->return_target_limb(), 5 + roll_dice(1, glvl), "acid");    
    if(objectp(target) && FEATS_D->has_feat(caster, "beshadowed blast"))
        target->cause_typed_damage(target, target->return_target_limb(), 5 + roll_dice(1, glvl), "void");
    if(objectp(target) && FEATS_D->has_feat(caster, "binding blast"))
        target->cause_typed_damage(target, target->return_target_limb(), 5 + roll_dice(1, glvl), "force");
    if(objectp(target) && FEATS_D->has_feat(caster, "utterdark blast"))
        target->cause_typed_damage(target, target->return_target_limb(), 5 + roll_dice(1, glvl), "void");
    if(objectp(target) && FEATS_D->has_feat(caster, "hellfire blast"))
        target->cause_typed_damage(target, target->return_target_limb(), 5 + roll_dice(1, glvl), "divine");
    
    dest_effect();
}
    
    
    