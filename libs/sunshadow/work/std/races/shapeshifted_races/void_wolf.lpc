#include <std.h>
#include <daemons.h>

inherit SHAPESHIFT;

void create()
{
    ::create();

    set_attack_limbs(({ "maw" }));
    set_new_damage_type("piercing");
    set_limbs(({ "mouth", "head", "torso", "right foreleg", "right forepaw", "left foreleg", "left forepaw", "right rear leg", "right rear paw", "left rear leg", "left rear paw", "tail" }));
    set_attack_functions(([ "maw" : (: TO, "shape_attack" :) ]));
    set_ac_bonus(2);
    set_base_attack_num(6);
    set_castable(0);
    set_can_talk(0);
    set_shape_race("wolf");
    set_shape_profile("void_wolf_999");
    set_shape_bonus("stealth", 10);
    set_shape_bonus("cold resistance percent", 33);
    set_shape_bonus("void resistance percent", 33);
    set_shape_bonus("radiant resistance percent", -33);
    set_shape_bonus("silver resistance percent", -33);   
    set_shape_bonus("sight bonus", 5);
    set_shape_bonus("damage bonus", 3);
    set_shape_bonus("attack bonus", 3);
    set_shape_bonus("strength", 2);
    set_shape_bonus("dexterity", 2);
    set_shape_bonus("constitution", 2);
    set_shape_height(50 + random(12));
    set_shape_weight(200 + random(50));
    set_shape_mastery_feat("knockdown");
}

int default_descriptions(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }

    obj->set_description("is covered from snout to tail in smooth black fur. A maw of razor sharp teeth and keen eyes shows that the wolf is a natural predator in its own environment. Every step it takes reveals lean muscles under the heavy coat of fur.");

    obj->setDescriptivePhrase("lean $R with shadowy fur");

    obj->set("speech string", "growl");
    obj->set("describe string", "angrily");

    obj->force_me("message in trots in quickly");
    obj->force_me("message out darts quickly to the $D");

    return 1;
}

// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }
    tell_object(obj, "%^RESET%^%^BLUE%^%^BOLD%^You turn your mind out to the void as you focus on the core of your spirit.");
    tell_object(obj, "%^RESET%^%^BLUE%^You can feel your body take on the essence of shadow!");
    tell_object(obj, "%^RESET%^%^BLUE%^%^BOLD%^Your senses heighten, you can feel the pulse of the night, smell countless scents, you can taste the very air. You are one with the darkness. You are VOID WOLF!");

    tell_room(environment(obj), "%^RESET%^%^BOLD%^" + obj->QCN + " grows very still and appears to concentrate deeply.", obj);
    tell_room(environment(obj), "%^RESET%^%^YELLOW%^" + obj->QCN + " begins to change in front of your very eyes!", obj);
    tell_room(environment(obj), "%^BOLD%^%^BLUE%^Where " + obj->QCN + " once stood, is now a large shadowy wolf!", obj);

    return 1;
}

// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }

    tell_object(obj, "%^RESET%^%^RED%^You relax your focus on the void.");
    tell_object(obj, "%^RESET%^%^RED%^You can feel the sharpness of your senses beginning to fade and the strength returning.");
    tell_object(obj, "%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your body once again.");

    tell_room(environment(obj), "%^RESET%^%^BOLD%^" + obj->QCN + "'s muscles slacken and " + obj->QS + " gets a far-away look in " + obj->QP + " eyes.", obj);
    tell_room(environment(obj), "%^RESET%^%^BLUE%^" + obj->QCN + "'s body begins to change shape, elongating and curving!", obj);
    tell_room(environment(obj), "%^RESET%^%^GREEN%^Where " + obj->QCN + " once stood, now stands a " + obj->query_race() + "!", obj);

    return 1;
}

int can_cast()
{
    if(!objectp(query_owner())) { return 0; }
    if(FEATS_D->usable_feat(query_owner(),"wild spellcraft")) { return 1; }
    return can_cast_spells;
}

// custom unarmed attack functions go here, functions can be added just like hit functions for weapons
int shape_attack(object tp, object targ)
{
    object room;
    string t_name, my_name;
    int dice;
    
    if(!objectp(tp) || !objectp(targ))
        return 0;
    
    if(random(3))
        return 0;
    
    room = environment(tp);
    
    if(room != environment(targ))
        return 0;
    
    t_name = targ->query_cap_name();
    my_name = tp->query_cap_name();
    dice = 1 + tp->query_level() / 5;
    
    switch(random(10))
    {
        case 0..3:
        tell_object(tp, "You phase into the darkness, attacking " + t_name + " from all angles!");
        tell_object(targ, my_name + " seems to phase into the darkness, and attacks you from all angles!");
        tell_room(room, my_name + " seems to phase into the darkness, and attacks " + t_name + " from all angles!", ({ tp, targ }));
        set_new_damage_type("void");
        tp->execute_attack();
        set_new_damage_type("piercing");
        break;
        
        case 4..7:
        tell_object(tp, "You spew a miasma of blinding darkness into " + t_name + "'s eyes!");
        tell_object(targ, my_name + " spews a miasma of blinding darkness into your eyes!");
        tell_room(room, my_name + " spews a miasma of blinding darkness into " + t_name + "'s eyes!", ({ tp, targ }));
        if(!targ->reflex_save(10 + tp->query_level() / 2))
            targ->set_temporary_blinded(1);
        break;
        
        default:
        tell_object(tp, "You shear into " + t_name + " with a blur of shadowy claws!");
        tell_object(targ, my_name + " shears into you with a blur of shadowy claws!");
        tell_room(room, my_name + " shears into " + t_name + " with a blur of shadowy claws!", ({ tp, targ }));
        targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(dice, 6), "void");
        break;
    }
    
    return roll_dice(2, dice);
}
