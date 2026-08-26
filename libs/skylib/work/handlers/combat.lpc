/**
 * This is the combat handler.
 * Rewritten from the old combat effect/shadow.
 * @author Sandoz, 2003.
 */

#define __ATTACK_DATA_CLASS__
#define __SPECIAL_ATTACK_DATA__
#include <combat.h>
#include <player.h>
#include <tasks.h>

// #define TIMING_INFORM
// #define ATTACK_INFORM
// #define DODGE_INFORM
// #define PARRY_INFORM
#define TM_INFORM
// #define AC_INFORM
// #define DAMAGE_INFORM

/**
 * This defines the percentual penalty to different actions when being hurt.
 */
#define HP_MOD                   10

/**
 * This defines the percentual bonus to dodging that being
 * unburdened gives you.
 */
#define DODGE_WEIGHT             30

/**
 * This defines the crossover weight for weapons being dodged.
 * Weapons lighter than this are harder to dodge, heavier than this easier.
 */
#define DODGE_WEAPON_WEIGHT      40

/**
 * This defines the percentual bonus to parrying that being
 * unburdened gives you.
 */
#define PARRY_WEIGHT             10

/**
 * This defines the crossover weight for weapons being parried.
 * Weapons heavier than this are harder to parry, lighter than this easier.
 */
#define PARRY_WEAPON_WEIGHT      40

/**
 * This defines the percentual bonus blocking with a shield should give.
 * Twice this bonus is given when the shield is covering the area that
 * is being attacked.
 */
#define SHIELD_BLOCK_BONUS       5

/**
 * This defines the percentual bonus to defending against an attack
 * aimed at a specific bodypart.
 */
#define FOCUS_DEFENSE_BONUS      5

/**
 * This defines the percentual bonus a level of attitude gives to one's
 * defense.
 */
#define DEF_MANOEUVRE_ATT_BONUS  10

/**
 * This defines the percentual bonus a level of attitude gives to one's
 * attack.
 */
#define OFF_MANOEUVRE_ATT_BONUS  5

/**
 * This defines the time taken to perform an action eg. attack, parry or dodge.
 */
#define ACTION_TIME              (ROUND_TIME / 2)

/** @ignore yes */
#define PARRY_SKILL              "fighting.combat.parry.melee"
/** @ignore yes */
#define DODGING_SKILL            "fighting.combat.dodging.melee"
/** @ignore yes */
#define UNARMED_SKILL            "fighting.combat.special.unarmed"

private int extra_id;
private class attack_data *extra_attacks;

private void stop_hunting();
private void flush_extra_attacks();
void attack_round( object attacker, int extra,
                   class attack_data attack,
                   class special_attack_data sp );

private void do_inform( object who, string fmt, mixed *args ... ) {
    event( filter( INV(ENV(who)), (: $1->query_creator() :) ), "inform",
         ( sizeof(args) ? sprintf( fmt, args ... ) : fmt ), "combat");
} /* log_file() */

protected void create() {
    extra_attacks = ({ });
    call_out( (: stop_hunting :), 120 );
} /* create() */

/** @ignore yes */
private void stop_hunting() {
    call_out( (: stop_hunting :), 120 );

    foreach( object ob in named_livings() )
        catch( ob->stop_hunting() );

} /* stop_hunting() */

/**
 * This method returns a nice description of the creature's attack.
 * @param attacker the creature attacking
 * @param target the creature being attacker
 * @param weapon the weapon used
 * @param skill the melee skill used
 * @param type the type of the attack
 * @param name the name of the attack used
 * @param the body area being attacked
 */
class message_data query_attack_desc( object attacker, object target,
                                      mixed weapon, string skill, string type,
                                      string name, string area ) {
    class message_data ret;
    int hilt;

    ret = new( class message_data );

    ret->attacker = "You";
    ret->others = attacker->one_short();

    // Assume it is an unarmed attack.
    if( weapon == attacker )
        skill = type;

    switch( skill ) {
      case "blunt" :
        switch( name ) {
          case "hoof" :
            ret->attacker += " kick at ";
            ret->others += " kicks at ";
            weapon = "hooves";
          break;
          case "hands" :
            ret->attacker += " punch at ";
            ret->others += " punches at ";
          break;
          case "feet" :
            ret->attacker += " kick at ";
            ret->others += " kicks at ";
          break;
          default :
            ret->attacker += " swing at ";
            ret->others += " swings at ";
        }
      break;
      case "pierce" :
        switch( name ) {
          case "bite" :
            ret->attacker += " attempt to bite ";
            ret->others += " attempts to bite ";
          break;
          case "beak" :
            ret->attacker += " thrust at ";
            ret->others += " thrusts at ";
            weapon = "beak";
          break;
          case "horns" :
            ret->attacker += " thrust at ";
            ret->others += " thrusts at ";
            weapon = "horns";
          break;
          default :
            ret->attacker += " thrust at ";
            ret->others += " thrusts at ";
        }
      break;
      case "sharp" :
        switch( name ) {
          case "slash" :
            ret->attacker += " slash at ";
            ret->others += " slashes at ";
          break;
          case "slice" :
            ret->attacker += " slice at ";
            ret->others += " slices at ";
          break;
          case "chop" :
            ret->attacker += " chop at ";
            ret->others += " chops at ";
          break;
          case "claws" :
            ret->attacker += " hack at ";
            ret->others += " hacks at ";
            weapon = "claws";
          break;
          case "chew" :
            ret->attacker += " attempt to bite ";
            ret->others += " attempts to bite ";
          break;
          default :
            ret->attacker += " hack at ";
            ret->others += " hacks at ";
        }
      break;
      case "unarmed" :
        switch( name ) {
          case "hands" :
            ret->attacker += " punch at ";
            ret->others += " punches at ";
          break;
          case "feet" :
            ret->attacker += " kick at ";
            ret->others += " kicks at ";
          break;
          case "bash" :
            ret->attacker += " swing at ";
            ret->others += " swings at ";
            weapon = " with the "+
                weapon->query_hilt()+" of "+weapon->poss_short();
            hilt = 1;
          break;
          default :
            ret->attacker += " swing at ";
            ret->others += " swings at ";
        }
      break;
      default :
        ret->attacker += " BROKEN MESSAGE ";
        ret->others += " BROKEN MESSAGE ";
    }

    ret->attacker += target->poss_short()+" "+area;
    ret->others += target->poss_short()+" "+area;

    if( hilt ) {
        ret->attacker += weapon;
        ret->others += weapon;
    } else if( stringp(weapon) ) {
        ret->attacker += " with your "+weapon;
        ret->others += " with "+attacker->HIS+" "+weapon;
    } else if( weapon != attacker ) {
        ret->attacker += " with "+weapon->poss_short();
        ret->others += " with "+weapon->poss_short();
    }

    ret->defender = ret->others;

    return ret;

} /* query_attack_desc() */

/** @ignore yes */
void write_messages( int blocked, mixed stopped_by, class attack_data att ) {
    object off, def, wep;
    int pverbose, tverbose, damage, actual;
    class message_data messages;

    off = att->attacker;
    def = att->target;
    wep = att->weapon;
    messages = att->messages;
    damage = att->final_damage;

    pverbose = interactive(off) && off->query_verbose("combat");
    tverbose = interactive(def) && def->query_verbose("combat");

    // These are the messages for missing.
    if( !damage && !blocked && def->query_visible(off) ) {
        if( !messages )
            messages = query_attack_desc( off, def, wep, att->skill, att->type,
                                          att->name, att->area );

        if( pverbose )
            tell_object( off, messages->attacker+", but miss "+
                def->HIM+" completely.\n");

        if( tverbose )
            tell_object( def, messages->defender+", but $V$0=misses,miss$V$ "
                "you completely.\n");

        def->event_missed_me(off);

        event( ENV(off), "see", messages->others+", but misses "+
            def->HIM+" completely.\n", off, ({ off, def }) );
        return;
    }

    // We were dodged, parried or magically blocked.
    if( !att->success ) {
        if( pverbose )
            tell_object( off, messages->attacker );
        if( tverbose )
            tell_object( def, messages->defender );
        event( ENV(off), "see", messages->others, off, ({ off, def }) );
        return;
    }

    // Actual damage done.
    if( damage > blocked )
        actual = damage - blocked;
    else
        actual = 0;

    // These are the messages for damage being done.
    if( actual ) {
        class message_data tmp;

        tmp = ATTACK_MESS_H->query_message( actual * COMBAT_DAMAGE,
            att->type, def, off, att->name, wep, att->area );

        if( messages ) {
            messages->attacker += ".  $C$"+tmp->attacker;
            messages->defender += ".  $C$"+tmp->defender;
            messages->others += ".  $C$"+tmp->others;
        } else {
            messages = tmp;
        }
    }

    // These are the messages for armour absorbing 1/3 or more of the blow.
    if( blocked && ( blocked > damage / 3 ) ) {
        string mess, bit;

        if( !messages )
            messages = query_attack_desc( off, def, wep, att->skill, att->type,
                                          att->name, att->area );

        if( !actual ) {
            mess = ( ( objectp(stopped_by) && query_group(stopped_by) ) ||
                       stopped_by == "scales" ? " absorb " : " absorbs ");
            mess += "all";
            bit = ", but ";
        } else {
            mess = " absorbing ";
            mess += ( blocked > damage * 2 / 3 ? "most" : "some");
            bit = " despite ";
        }

        mess += " of ";

        if( def->query_visible(off) ) {
            if( pverbose || ( blocked < damage * 2 / 3 ) )
                tell_object( off, messages->attacker + bit +
                    ( objectp(stopped_by) ? stopped_by->poss_short() :
                    def->HIS+" "+stopped_by ) + mess + "your blow.\n");
        } else {
            tell_object( off, messages->attacker+".\n");
        }

        if( tverbose || ( blocked < damage * 2 / 3 ) )
            tell_object( def, messages->defender + bit +
                ( objectp(stopped_by) ? stopped_by->poss_short() :
                "your "+stopped_by ) + mess + "the blow.\n");

        event( ENV(off), "see", messages->others + bit +
            ( objectp(stopped_by) ? stopped_by->poss_short() :
            def->HIS+" "+stopped_by ) + mess + "the blow.\n",
            off, ({ off, def }) );
        return;
    }

    tell_object( off, messages->attacker+".\n");
    tell_object( def, messages->defender+".\n");
    event( ENV(off), "see", messages->others+".\n", off, ({ off, def }) );

} /* write_messages() */

/**
 * @ignore yes
 * Whether someone gets to parry or dodge is dependant on the value of
 * special manoevure. This function determines whether to reset that value
 * ie. prevent them parrying/dodging again this round.
 * We return a percentual value here.
 * The more defensive our attitude is, the more negative the return value.
 * @param thing the creature to reset the manoeuvre for
 * @param skill the defensive skill used
 */
int do_reset_manoeuvre( object thing, string skill ) {
    int repeat_chance, skill_bonus, bonus, i, time;

    // Chance is 0-800 dependant on skill.
    repeat_chance = skill_bonus = thing->query_skill_bonus(skill);
    i = thing->query_raw_combat_attitude();

    // Now modify that based on what their attitude is.
    // A 10% bonus/penalty per attitude level.
    bonus = i * DEF_MANOEUVRE_ATT_BONUS;
    repeat_chance -= i * 200;

    // Make sure they always have a chance of running out.
    if( repeat_chance > 750 )
        repeat_chance = 750;

    // See if they'll get to defend again.
    if( repeat_chance < random(800) )
        thing->reset_special_manoeuvre();

    // Let's give a bonus to time taken based on attitude as well.
    skill_bonus -= i * 50;

    if( skill_bonus ) {
        time = ACTION_TIME / 2 - ( skill_bonus / 50 );
        if( time < 2 )
            time = 2;
    } else {
        time = ACTION_TIME / 2;
    }

    thing->adjust_time_left( -time );

#ifdef TIMING_INFORM
    do_inform( thing, "TIMING: %s - adjusting time by: %i",
        thing->query_name(), ACTION_TIME / 2 );
#endif

    return bonus;

} /* do_reset_manoeuvre() */

/**
 * This method checks to see if the player has time to perform the action.
 * @param ob the object to check for time
 * @param off this is an offensive move
 * @return 1 if they do, 0 if they do not
 */
int check_time_left( object ob, int off ) {
    int time_left, action_time;

    // If a player has a special prepared and is trying to defend they don't.
    if( !ob->query_special_manoeuvre() && !off )
        return 0;

    // NPCs don't have time.
    if( !interactive(ob) )
        return 1;

    if( ob->queue_commands() )
        return 0;

    time_left = ob->query_time_left();
    action_time = ACTION_TIME;

    // If they have some time left.
    if( time_left >= action_time )
        return 1;

    switch( ob->query_raw_combat_attitude() ) {
      case 1..2 :
        // If they're in offensive mode and its an offensive command and
        // they're not more than 1 round overdrawn then ok.
        if( off && time_left > -action_time )
            return 1;
      break;
      case -2..-1 :
        if( !off && time_left > -action_time )
            return 1;
      break;
    }

    return 0;

} /* check_time_left() */

/** @ignore yes */
private void melee_tm( object attacker, object weapon ) {
    tell_object( attacker, "%^YELLOW%^"+ replace( ({
        "You feel that your skill with $weapon$ has increased.",
        "You feel more able to use $weapon$.",
        "You seem to be a step closer to mastering $weapon$.",
        })[ random( 3 ) ], "$weapon$", ( weapon == attacker ?
        "unarmed combat" : weapon->the_short() ) )+"%^RESET%^\n");
} /* melee_tm() */

/** @ignore yes */
class task_class_result compare_skills( object offob, string offskill,
                                        object defob, string defskill,
                                        int modifier ) {
    int offbonus, defbonus, difficulty, percent, defdeg;
    class task_class_result result;

    offbonus = offob->query_skill_bonus(offskill);
    defbonus = defob->query_skill_bonus(defskill);

    difficulty = offbonus + modifier * offbonus / 100;

    TASKER->set_control( ({ defob, defskill }) );

    // Args: difficulty, bonus, upper, half, use_class.
    // Let's have a slightly lower tm chance for defensive tms,
    // since they are done each time.
    result = TASKER->attempt_task_e( difficulty, defbonus, 15, 100, 1 );

#ifdef TM_INFORM
    do_inform( offob,
        "Combat TM: %s (%s: %i) attacking %s (%s: %i)",
        offob->query_cap_name(), explode( offskill, ".")[<1], offbonus,
        defob->query_cap_name(), explode( defskill, ".")[<2], defbonus );
    do_inform( offob, "Combat TM: Modifier: %i, Defense difficulty : %i",
        modifier, difficulty );
#endif

    defdeg = result->degree;

    switch( result->result ) {
      case AWARD :
        if( !TASKER->is_valid_tm( defob, defskill ) ||
            !defob->add_skill_level( defskill, 1, TO ) ) {
            result->result = DEFWIN;
            return result;
        }
        result->result = DEFAWARD;
#ifdef TM_INFORM
        do_inform( offob, "Combat TM: DEFWIN");
#endif
        return result;
      case SUCCEED :
        result->result = DEFWIN;
#ifdef TM_INFORM
        do_inform( offob, "Combat TM: DEFWIN");
#endif
        return result;
      default :
    }

    difficulty = defbonus - modifier * defbonus / 100;

    TASKER->set_control( ({ offob, offskill }) );

    // Args: difficulty, bonus, upper, half, use_class.
    result = TASKER->attempt_task_e( difficulty, offbonus, 18, 100, 1 );

#ifdef TM_INFORM
    do_inform( offob, "Combat TM: Modifier: %i, Attack difficulty : %i",
        modifier, difficulty );
#endif

    switch( result->result ) {
      case AWARD :
        if( !TASKER->is_valid_tm( offob, offskill ) ||
            !offob->add_skill_level( offskill, 1, TO ) ) {
            result->result = OFFWIN;
            return result;
        }
        result->result = OFFAWARD;
#ifdef TM_INFORM
        do_inform( offob, "Combat TM: OFFWIN");
#endif
        return result;
      case SUCCEED :
        result->result = OFFWIN;
#ifdef TM_INFORM
        do_inform( offob, "Combat TM: OFFWIN");
#endif
        return result;
      default :
    }

    // If both lose the skill checks, we throw dice, basically.
    if( !offbonus && !defbonus )
        percent = 50;
    else
        percent = ( offbonus * 100 ) / ( offbonus + defbonus );

    percent += modifier;

    // Add a small modifier from the taskmaster result degrees as well.
    percent += ( result->degree - defdeg ) / 4;

    if( random(100) < percent ) {
        result->result = OFFWIN;
#ifdef TM_INFORM
        do_inform( offob, "Combat TM: DRAW-OFFWIN, Percent: %i, Degree: %i",
            percent, result->degree );
#endif
    } else {
        result->result = DEFWIN;
        result->degree = defdeg;
#ifdef TM_INFORM
        do_inform( offob, "Combat TM: DRAW-DEFWIN, Percent: %i, Degree: %i",
            percent, result->degree );
#endif
    }

    return result;

} /* compare_skills() */

/** @ignore yes */
string success_degree( int degree, string input ) {
    switch( degree ) {
      case -100..-76 :
        return input + " with pure luck";
      case -75..-51 :
        return "clumsily " + input;
      case -50..-26 :
        return "barely " + input;
      case -25..25 :
        return input;
      case 26..50 :
        return "skillfully " + input;
      case 51..75 :
        return "expertly " + input;
      case 76..100 :
        return input + " with no effort at all";
      default :
        return input + " in an act of buggy goodness";
    }
} /* success_degree() */

/**
 * This method checks to see if we dodge an attack.
 * @param attack the attack to dodge
 * @return the modified attack data class
 */
class attack_data dodge_attack( class attack_data att ) {
    int pverbose, tverbose, mod, burden;
    class task_class_result result;
    class message_data mess;
    object off, def, wep;
    string str;

    off = att->attacker;
    def = att->target;
    wep = att->weapon;
    mod = att->attack_bonus;

    if( !check_time_left( def, 0 ) || !off->query_visible(def) ) {
#ifdef DODGE_INFORM
        do_inform( off, "DODGE: %s not dodging this attack, Special: %i Time "
            "left: %i Queue: %i Visible: %i", def->query_name(),
            !def->query_special_manoeuvre(), def->query_time_left(),
            def->queue_commands(), !off->query_visible(def) );
#endif
        att->success = 1;
        return att;
    }

    pverbose = interactive(off) && off->query_verbose("combat");
    tverbose = interactive(def) && def->query_verbose("combat");

    mod += do_reset_manoeuvre( def, DODGING_SKILL );
    mod += off->query_raw_combat_attitude() * OFF_MANOEUVRE_ATT_BONUS;

    burden = def->query_burden();

    // A possible bonus ranging from -DODGE_WEIGHT/2 to DODGE_WEIGHT/2
    mod += DODGE_WEIGHT * burden / 100 - DODGE_WEIGHT / 2;

    // A bonus to dodging large weapons, and penalty for lighter ones.
    if( wep != off )
        mod += ( DODGE_WEAPON_WEIGHT - wep->query_weight() ) / 4;

#ifdef DODGE_INFORM
        do_inform( off, "DODGE: %s (att: %s, bonus: %i, burden: %i)\n"
            "    VS: %s (att: %s, bonus: %i, weapon weight: %i)\n"
            "    Attack bonus: %i, final modifier: %i",
            def->query_name(), def->query_combat_attitude(),
            def->query_skill_bonus(DODGING_SKILL), burden, off->query_name(),
            off->query_combat_attitude(),
            off->query_skill_bonus(MELEE+att->skill), wep->query_weight(),
            att->attack_bonus, mod );
#endif

    result = compare_skills( off, MELEE+att->skill, def, DODGING_SKILL, mod );

    switch( result->result ) {
      case OFFAWARD :
        melee_tm( off, wep );
      case OFFWIN :
        // If you fail your dodge you have a 66% chance of not being able
        // to dodge again this round.
        if( random( 3 ) )
            def->reset_special_manoeuvre();
        att->success = 1;
        return att;
      case DEFAWARD :
        tell_object( def, "%^YELLOW%^"+replace( ({"You move more "
            "nimbly than you thought you could in dodging $attacker$",
            "You managed to predict $attacker$'s attack, letting you "
            "dodge it more easily", "You feel better at dodging as you "
            "avoid $attacker$'s attack" })[ random( 3 ) ], "$attacker$",
            off->the_short() ) +".%^RESET%^\n" );
      case DEFWIN :
        if( !mess = att->messages )
            mess = query_attack_desc( off, def, wep, att->skill, att->type,
                                      att->name, att->area );

        str = success_degree( result->degree, "dodge out of the way");
        mess->defender += ", but you "+str+".\n";
        str = success_degree( result->degree, "dodges out of the way");
        mess->attacker += ", but "+def->HE+" "+str+".\n";
        mess->others += ", but "+def->HE+" "+str+".\n";

        att->messages = mess;
        att->success = 0;

        return att;
    }

} /* dodge_attack() */

/**
 * This method checks to see if they can parry with their bare hands.
 * @param attack the attack to dodge
 * @return the modified attack data class
 */
protected class attack_data unarmed_parry( class attack_data att ) {
    int pverbose, tverbose, mod;
    class task_class_result result;
    class message_data mess;
    object off, def, wep;
    mapping areas;
    string str;

    off = att->attacker;
    def = att->target;
    wep = att->weapon;
    mod = att->attack_bonus;

    pverbose = interactive(off) && off->query_verbose("combat");
    tverbose = interactive(def) && def->query_verbose("combat");

    mod += do_reset_manoeuvre( def, UNARMED_SKILL );
    mod += off->query_raw_combat_attitude() * OFF_MANOEUVRE_ATT_BONUS;

    // A small bonus to parrying small weapons, and penalty for heavier ones.
    if( wep != off )
        mod -= ( PARRY_WEAPON_WEIGHT - wep->query_weight() ) / 4;

    // A possible bonus ranging from -PARRY_WEIGHT/2 to PARRY_WEIGHT/2
    mod += PARRY_WEIGHT * def->query_burden() / 100 - PARRY_WEIGHT / 2;

#ifdef PARRY_INFORM
    do_inform( off, "UNARMED PARRY: %s (att: %s, bonus: %i)\n"
        "     VS: %s (att: %s, bonus: %i, weapon: %s, weight: %i)\n"
        "     Attack bonus: %i, final modifier: %i", def->query_name(),
        def->query_combat_attitude(), def->query_skill_bonus(UNARMED_SKILL),
        off->query_name(), off->query_combat_attitude(),
        off->query_skill_bonus(MELEE+att->skill), wep->short(),
        wep->query_weight(), att->attack_bonus, mod );
#endif

    if( !mess = att->messages )
        mess = query_attack_desc( off, def, wep, att->skill, att->type,
                                  att->name, att->area );

    areas = def->query_attackable_areas();

    result = compare_skills( off, MELEE+att->skill, def, UNARMED_SKILL, mod );

    switch( result->result ) {
      case OFFAWARD :
        melee_tm( off, wep );
      case OFFWIN :
        // If you fail your parry you have a 66% chance of not being able
        // to defend again this round.
        if( random( 3 ) )
            def->reset_special_manoeuvre();

        att->success = 1;
        att->area = 0;

        if( att->focus == "arms" || ( random( 4 ) && att->focus != "hands") )
            att->focus = "hands";
        else
            att->focus = "arms";

        att->area = choice( areas["arms"] );

        tell_object( off, mess->attacker+", but "+def->the_short()+" moves "
            "in "+def->HIS+" "+att->area+" to attempt to deflect the "
            "attack.\n");
        tell_object( def, mess->defender+", but you move in your "+
            att->area+" to attempt to deflect the attack.\n");
        event( ENV(off), "see", mess->others+", but "+
            def->the_short()+" moves in "+def->HIS+" "+att->area+" to "
            "attempt to deflect the attack.\n", off, ({ off, def }) );

        att->messages = 0;

        return att;

      case DEFAWARD :
        tell_object( def, "%^YELLOW%^"+replace( ({"You move more "
            "accurately than you thought you could in deflecting "
            "$attacker$'s attack", "You just manage to deflect "
            "$attacker$'s attack, but you'll know better next time",
            "You feel better at parrying unarmed as you deflect "
            "$attacker$'s attack"})[random( 3 )], "$attacker$",
            off->the_short() ) +".%^RESET%^\n");
      case DEFWIN :
        str = success_degree( result->degree, "deflect the blow");
        mess->defender += ", but you "+str;
        str = success_degree( result->degree, "deflects the blow");
        mess->attacker += ", but "+def->HE+" "+str;
        mess->others += ", but "+def->HE+" "+str;

        if( att->focus != "hands") {
            string part = choice( areas["hands"] );
            mess->attacker += " with "+def->HIS+" "+part;
            mess->defender += " with your "+part;
            mess->others += " with "+def->HIS+" "+part;
        }

        mess->attacker += ".\n";
        mess->defender += ".\n";
        mess->others += ".\n";

        att->messages = mess;
        att->success = 0;

        return att;
    }

} /* unarmed_parry() */

/**
 * This method checks to see if they can parry with their weapon.
 * @param attack the attack to dodge
 * @return the modified attack data class
 */
class attack_data parry_attack( class attack_data att ) {
    int i, pverbose, tverbose, mod;
    string parrying, *hands, *verb, str;
    object *things, with, off, def, wep;
    class task_class_result result;
    class message_data mess;

    off = att->attacker;
    def = att->target;

    if( !check_time_left( def, 0 ) || !off->query_visible(def) ) {
#ifdef PARRY_INFORM
        do_inform( off, "PARRY: %s not parrying this attack, Special: %i "
            "Time left: %i Queue: %i Visible: %i", def->query_name(),
            !def->query_special_manoeuvre(), def->query_time_left(),
            def->queue_commands(), !off->query_visible(def) );
#endif
        att->success = 1;
        return att;
    }

    things = def->query_holding();

    switch( str = def->query_combat_parry() ) {
      case "all" :
      case "both" :
      break;
      default :
        i = sizeof( hands = def->query_limbs() );
        while( i-- ) {
            if( hands[ i ] != str+" hand") {
                hands = delete( hands, i, 1 );
                things = delete( things, i, 1 );
            }
        }
    }

    if( !sizeof( things -= ({ 0 }) ) ) {
        if( def->query_unarmed_parry() ) {
            return unarmed_parry( att );
        } else {
            att->success = 1;
            return att;
        }
    }

    wep = att->weapon;
    mod = att->attack_bonus;

    pverbose = interactive(off) && off->query_verbose("combat");
    tverbose = interactive(def) && def->query_verbose("combat");

    mod += do_reset_manoeuvre( def, PARRY_SKILL );
    mod += off->query_raw_combat_attitude() * OFF_MANOEUVRE_ATT_BONUS;

    // A possible bonus ranging from -PARRY_WEIGHT/2 to PARRY_WEIGHT/2
    mod += PARRY_WEIGHT * def->query_burden() / 100 - PARRY_WEIGHT / 2;

    with = choice( things );

    // Let us check for a shield.
    if( with->query_shield() ) {
        mod += with->query_weight() / ( def->query_str() + 1 );

        // A bonus for blocking with a shield.
        mod -= SHIELD_BLOCK_BONUS;

        // If the shield is covering the area being attacked,
        // it should be very easy to block.
        if( member_array( att->focus, CLOTHING_H->query_zone_names(
            with->query_type() ) ) != -1 )
            mod -= SHIELD_BLOCK_BONUS;
    } else {
        things = def->query_holding();
        // Get the number of hands used.
        i = sizeof(things) - sizeof( things - ({ with }) );
        mod += 2 * with->query_weight() / ( i * def->query_str() + 1 );
    }

    // Take the relative weights of the two weapons into account as well.
    if( wep != off )
        mod += ( wep->query_weight() - with->query_weight() ) / 4;

#ifdef PARRY_INFORM
    do_inform( off,
        "PARRY: %s (att: %s, bonus: %i, using: %s, weight: %i)\n"
        "    VS: %s (att: %s, bonus: %i, weapon: %s, weight: %i)\n"
        "    Attack bonus: %i, final modifier: %i", def->query_name(),
        def->query_combat_attitude(), def->query_skill_bonus(PARRY_SKILL),
        with->short(), with->query_weight(), off->query_name(),
        off->query_combat_attitude(),
        off->query_skill_bonus(MELEE+att->skill), wep->short(),
        wep->query_weight(), att->attack_bonus, mod );
#endif

    verb = ( with->query_weapon() ?
           ({"parry", "parries", "parrying"}) :
           ({"block", "blocks", "blocking"}) );

    result = compare_skills( off, MELEE+att->skill, def, PARRY_SKILL, mod );

    switch( result->result ) {
      case OFFAWARD :
        melee_tm( off, wep );
      case OFFWIN :
        // If you fail your parry you have a 66% chance of not being able
        // to defend again this round.
        if( random( 3 ) )
            def->reset_special_manoeuvre();
        att->success = 1;
        return att;
      case DEFAWARD :
        tell_object( def, "%^YELLOW%^"+replace( ({"You move more "
            "surely than you thought you could in $verbing$ $attacker$'s "
            "attack", "You just manage to $verb$ $attacker$'s attack, "
            "but you'll know better next time", "You feel better at "
            "$verbing$ as you deflect $attacker$'s attack"})[random( 3 )],
            ({"$verb$", verb[ 0 ], "$verbing$", verb[ 2 ], "$attacker$",
            off->the_short() }) )+".%^RESET%^\n");
      case DEFWIN :
        if( with->query_weapon() )
            with->hit_weapon( att->final_damage, att->type );
        else
            with->do_damage( att->type, att->final_damage );

        wep->hit_weapon( att->final_damage, att->type );

        if( !mess = att->messages )
            mess = query_attack_desc( off, def, wep, att->skill, att->type,
                                      att->name, att->area );

        parrying = with->poss_short();

        str = success_degree( result->degree,
            verb[ 0 ]+" the blow with "+parrying );
        mess->defender += ", but you "+str+".\n";
        str = success_degree( result->degree,
            verb[ 1 ]+" the blow with "+parrying );
        mess->attacker += ", but "+def->HE+" "+str+".\n";
        mess->others += ", but "+def->HE+" "+str+".\n";

        att->messages = mess;
        att->success = 0;

        // Here we have a hook to a function in weapons/shields.
        // This function should return the (possibly) modified attack
        // data class.  If not, we just return the original class.
        return with->parry_attack(att) || att;
    }

} /* parry_attack() */

/** @ignore yes */
void clear_protection( object attacker, object victim ) {
    if( member_array( victim, attacker->query_protectors() ) != -1 ) {
        tell_object( victim, "You stop protecting "+
            attacker->the_short()+" as "+attacker->HE+" moves to "
            "attack you!\n");
        tell_object( attacker, "You move to attack "+
            victim->the_short()+", forfeiting "+victim->HIS+" protection.\n");
        tell_room( ENV(attacker), "In return for being attacked, "+
            victim->the_short()+" stops protecting "+
            attacker->the_short()+".\n", ({ attacker, victim }) );
        attacker->remove_protector( victim );
    }
} /* clear_protection() */

/** @ignore yes */
void combat_actions( object player, object target ) {
    int i, chance;
    object thing, *things;
    mixed actions;

    if( !player || !target )
        return;

    thing = ENV(player);

    if( thing != ENV( target ) )
        return;

    things = filter( INV(thing), (: living($1) == !userp($1) :) );

    foreach( thing in things ) {
        actions = thing->query_combat_actions();
        if( sizeof( actions ) < 2 )
            continue;

        chance = random( actions[ 0 ] );
        i = 1;

        while( chance > -1 ) {
            if( chance < actions[ i ] )
                call_out("combat_action", 1, player, target, thing,
                    actions[ i + 2 ] );
            chance -= actions[ i ];
            i += 3;
        }
    }

} /* combat_actions() */

/** @ignore yes */
void combat_action( object player, object target, object thing, mixed action ) {
    object place;

    if( !target || !thing )
        return;

    if( !place = ENV(player) )
        return;

    if( place != ENV(target) || place != ENV(thing) )
        return;

    if( stringp(action) ) {
        thing->do_command( action );
        return;
    }

    if( functionp(action) )
        evaluate( action, player, target );

    if( pointerp(action) && sizeof(action) == 1 && stringp( action[ 0 ] ) ) {
        call_other( thing, action[ 0 ], player, target );
        return;
    }

    if( pointerp(action) && sizeof(action) == 2 )
        call_other( action[ 0 ], action[ 1 ], thing, player, target );

} /* combat_action() */

/**
 * This method checks whether someone jumps in an protects us.
 * @param thing the thing to check for protectors
 * @param attacker the attacker
 * @return the thing that protects us, or ourself
 */
object check_protection( object thing, object attacker ) {
    object *protectors;

    if( !sizeof( protectors = thing->query_protectors() ) )
        return thing;

    protectors = shuffle( filter( protectors, (:
        !$1->query_property("dead") && !$1->query_property(PASSED_OUT) &&
        ( $1->query_time_left() >= 0 ) && !$1->queue_commands() &&
        ( !userp($1) || interactive($1) ) && !$1->query_sanctuary() &&
        ( ENV($1) == ENV($2) ) && $2->query_visible($1) :), thing ) );

    foreach( object ob in protectors ) {
        if( !random( 5 ) || ob == attacker || pk_check( ob, attacker ) )
            continue;

        ob->remove_hide_invis("hiding");

        tell_object( ob, "You bravely throw yourself in front of "+
            thing->the_short()+" to protect "+thing->HIM+" from "+
            attacker->poss_short()+" attack.\n");

        tell_object( thing, ob->one_short()+" bravely throws "+
            ob->HIM+"self in front of "+thing->one_short()+" to protect you "
            "from "+attacker->poss_short()+" attack.\n");

        tell_room( ENV(thing), ob->one_short()+" bravely throws "+
            ob->HIM+"self in front of "+thing->one_short()+" to protect "+
            thing->HIM+" from "+attacker->poss_short()+" attack.\n",
            ({ ob, thing }) );

        ob->attack_by(attacker);
        attacker->set_target(ob);

        return ob;
    }

    return thing;

} /* check_protection() */

/** @ignore yes */
int level_out( int number ) {
   int i, levelled;

   while( number && i++ < 10 ) {
      if( number < 100 ) {
          levelled += ( number * ( 11 - i ) ) / 10;
          number = 0;
      } else {
          levelled += 10 * ( 11 - i );
          number -= 100;
      }
   }

   return levelled;

} /* level_out() */

/**
 * This method returns the percentual penalty to actions performed
 * by the specified creature when hurt.  This value should be
 * negative or 0.
 * @param ob the creature to get the penalty for
 * @return the percentual penalty to actions due to being hurt
 */
int hp_modifier( object ob ) {
    return HP_MOD * ob->query_hp() / ( ob->query_max_hp() + 1 ) - HP_MOD;
} /* hp_modifier() */

/**
 * @ignore yes
 * Flag means to ignore attitude and darkness etc.
 */
int calc_attack_percentage( object attacker, object *weapons,
                            object *holding, int flag ) {
    int perc, weight, dex, str, burden, limbs;

    if( !ENV(attacker) )
        return 0;

    dex = attacker->query_dex();
    str = attacker->query_str();

    perc = 90;

    // Start out at up to 100 on the most aggressive attitude.
    if( !flag )
        perc += attacker->query_raw_combat_attitude() * 5;

    // The fatter you are, the less you attack.
    // This should be a penalty of about 25-40.
    perc -= attacker->query_weight() / 2 / ( str + dex );

    if( !flag )
        perc += hp_modifier( attacker );

    burden = attacker->query_burden();

    // Unarmed percentage.
    if( !sizeof(weapons) ) {
        if( sizeof( attacker->query_limbs() ) )
            limbs = attacker->query_free_limbs();
        else
            limbs = 1;

        // A bonus of about 10-20.
        perc += ( str + dex ) * ( 1 + limbs ) / 5;

        // A (extra) bonus of up to +/- 10 for being unburdened.
        perc += 10 - 20 * burden / 100;
    } else {
        // Calculate the total weight of weapons.
        foreach( object thing in weapons )
            weight += thing->query_weight();

        // A penalty or bonus based on the weight of weapons used
        // and our strength.
        perc += str - ( weight * 5 ) / str;

        if( !flag ) {
            // Extra bonus based on strength for two-handed weapons.
            if( sizeof(weapons) == 1 && weapons[0]->query_no_limbs() > 1 )
                perc += str / 2;

            // A penalty based on dexterity for using multiple weapons.
            // A penalty of 40 with 3 dex, 11 with 21 dex, etc.
            if( sizeof(weapons) > 1 )
                perc -= 40 - ( dex * dex ) / 15;

            // A little bonus for fighting with one one-handed weapon only.
            if( sizeof(weapons) == 1 && sizeof(holding) == 1 &&
                attacker->query_free_limbs() )
                perc += ( str + dex ) / 4;
        }
    }

    // A bonus of up to +/- 10 for being unburdened.
    perc += 10 - 20 * burden / 100;

    if( perc < 1 )
        return 0;

    if( flag )
        return perc;

    switch( attacker->check_dark( ENV(attacker)->query_light() ) ) {
      case -2 :
      case 2 :
        return perc / 4;
      case -1 :
      case 1 :
        return perc / 2;
      default :
        return perc;
    }

} /* calc_attack_percentage() */

/** @ignore yes */
private void flush_extra_attacks() {
    class attack_data att, *attacks;
    object off, wep;

    extra_id = 0;

    // Store it in a local variable so that the global variable
    // would always be an empty array when we finish, even if we error.
    attacks = shuffle( extra_attacks );
    extra_attacks = ({ });

    foreach( att in attacks ) {
        if( ( off = att->attacker ) && att->target && ( wep = att->weapon ) &&
            ( ( wep == off && !sizeof( off->query_weapons() ) ) ||
            wep->query_wielded() == off ) )
            attack_round( off, 1, att, 0 );
    }

} /* flush_extra_attacks() */

/** @ignore yes */
private void register_extra_attack( class attack_data attack ) {
    if( !extra_id )
        extra_id = call_out( (: flush_extra_attacks :), 0 );

    extra_attacks += ({ attack });

} /* register_extra_attack() */

/** @ignore yes */
private void finish_attack( object attacker, object target, int extra ) {
    if( !extra ) {
        // Check for point monitoring.
        if( attacker->query_monitor() )
            HEALTH_H->register_monitor( attacker, 0 );
        // Check for combat actions for the next round.
        if( !userp( attacker ) )
            combat_actions( attacker, target );
    }
} /* finish_attack() */

/** @ignore yes */
void attack_round( object attacker, int extra, class attack_data attack,
                   class special_attack_data sp ) {
    object thing, weapon, *things, *holding, *weapons;
    class attack_data extra_attack;
    int back, bonus, riding, perc;
    mixed tmp;

    // Player cannot fight while passed out,
    // queuing commands, without environment, net-dead or just plain dead.
    if( attacker->query_property(PASSED_OUT) || attacker->dont_attack_me() ||
        !check_time_left( attacker, 1 ) || !ENV(attacker) ||
        ( userp(attacker) && !interactive(attacker) ) ||
        attacker->query_hp() < 0 ) {
#ifdef TIMING_INFORM
        do_inform( attacker, "TIMING: %s skipping round - time left: %i",
            attacker->query_name(), attacker->query_time_left() );
#endif
        return;
    }

    if( !extra )
        attacker->set_special_manoeuvre();

#ifdef TIMING_INFORM
    do_inform( attacker, "TIMING: %s - time left in the start of the "
        "attack round%s: %i", attacker->query_name(), extra ? " (EXTRA)" :
        "", attacker->query_time_left() );
#endif

    if( attack ) {
        thing = attack->target;
        weapon = attack->weapon;
    }

    // Choose a target to attack for this round.
    if( thing ) {
        if( ENV(thing) != ENV(attacker) || thing->query_property("dead") ||
            !thing->query_visible(attacker) ) {
            return;
        }
    } else if( sizeof( things = attacker->query_attackables() ) ) {
        if( !( thing = attacker->query_concentrating() ) ||
            member_array( thing, things ) == -1 )
            thing = choice( things );
    } else {
        // Maybe the last attacker is here, but invisible.
        if( !( thing = attacker->query_attacker() ) ||
            ENV(thing) != ENV(attacker) )
            return;

        attacker->set_attacker( 0 );

        if( thing->query_visible( attacker ) )
            return;

        if( random(100) < attacker->query_wimpy() ) {
            attacker->run_away();
            return;
        }

        tell_object( attacker, "You swing wildly, attempting to hit your "+
            "invisible opponent.\n" );
        event( ENV(attacker), "see", attacker->one_short()+" $V$0=swings,"
            "swing$V$ wildly.\n", attacker, attacker );
        return;
    }

    attacker->remove_hide_invis("hiding");

    if( thing->query_visible(attacker) )
        thing->remove_hide_invis("hiding");

    // Cancel protection if the player attacks a protector.
    clear_protection( attacker, thing );

    // If attack fails, assume a message is given already.
    if( !thing->attack_by( attacker ) )
        return;

    // Pass out the relevant information about the attack.
    if( !extra )
        attacker->fight_in_progress( thing );

    attacker->set_target( thing );

    if( !attack ) {
        // Give 1 xp for an attack round.
        // This would only benefit utter newbies.
        if( PO == attacker )
            attacker->adjust_xp( 1 );

        attack = new( class attack_data );
        attack->attacker = attacker;
        attack->target = thing;

        // See if we have a tactical special queued.
        if( sp = attacker->special_attack( SP_TACTICAL, attack ) ) {
            call_other( sp->ob, sp->fun, attacker, thing, sp->data,
                PREPARE_ATTACK );
            return;
        }

        holding = attacker->query_holding() - ({ 0 });
        weapons = shuffle( attacker->query_weapons() );

        // Whip through everything being held that is not a weapon and do
        // a little damage to them.  Non-weapon things should have fairly
        // low conditions.
        foreach( object ob in holding ) {
            if( !ob->query_weapon() ) {
                ob->do_damage("crush", 10 + random(50) );
                holding -= ({ ob });
            }
        }

        perc = calc_attack_percentage( attacker, weapons, holding, 0 );

        if( sizeof( weapons ) ) {
            weapon = weapons[0];
            weapons = weapons[1..1];
        } else {
            weapon = attacker;
            if( sizeof( attacker->query_attack_names() ) > 1 )
                weapons = ({ attacker });
        }

        if( sizeof( weapons ) ) {
            // Register an extra attack with 50% of our current
            // attack percentage.
            tmp = weapons[0]->weapon_attacks( perc / 2, thing );
            if( sizeof(tmp) ) {
                extra_attack = new( class attack_data );
                extra_attack->attacker = attacker;
                extra_attack->target = thing;
                extra_attack->weapon = weapons[0];
                extra_attack->damage = tmp[0];
                extra_attack->skill  = tmp[1];
                extra_attack->type = tmp[2];
                extra_attack->name = tmp[3];
                extra_attack->final_damage = tmp[0];
                extra_attack->attack_bonus = -5;
            }
        }

        if( !sizeof( tmp = weapon->weapon_attacks( perc, thing ) ) ) {
            if( extra_attack )
                register_extra_attack( extra_attack );
            return finish_attack( attacker, thing, extra );
        }

        attack->weapon = weapon;
        attack->damage = tmp[0];
        attack->skill  = tmp[1];
        attack->type = tmp[2];
        attack->name = tmp[3];
        attack->final_damage = tmp[0];

    }

    // See if we have a special queued.
    if( !sp && classp( sp = attacker->special_attack( SP_MELEE, attack ) ) ) {
        attack->data = sp->data;
        attack->flags = sp->flags;

        // This could be a tactical as well, in this case it should
        // return 0, if we want to return after executing the
        // special attack.
        if( attack->flags & PREPARE_ATTACK )
            attack = call_other( sp->ob, sp->fun, attack, PREPARE_ATTACK );

        if( !attack ) {
            if( extra_attack )
                register_extra_attack( extra_attack );
            return finish_attack( attacker, thing, extra );
        }
    }

    // Figure out any +s/-s from them being mounted.
    if( ENV(attacker)->query_transport() && ENV(thing)->query_transport() ) {
        // Both riding, no penalties.
    } else if( ENV(thing)->query_transport() ) {
        // They are riding...  So we get some penalties.
        riding = -1;
    } else if( ENV(attacker)->query_transport() ) {
        riding = 1;
    }

    if( weapon && classp(attack) && thing && ENV(thing) == ENV(attacker) &&
        thing->query_hp() >= 0 ) {
        string response;
        mapping areas;

        attacker->set_weapon( weapon );

        // Check out what bodyparts they have.
        areas = thing->query_attackable_areas();

        bonus = attacker->query_skill_bonus( MELEE+attack->skill );
        bonus += 50 * attacker->query_raw_combat_attitude();

        // Give people some +ve and -ve changes due to being on a horse.
        if( riding )
            bonus += riding * ( riding < 0 ? 100 : 50 );

        if( bonus + attack->attack_bonus > 0 ) {
            back = ACTION_TIME - ( bonus + attack->attack_bonus ) / 25;
            // Let's make heavier weapons use more action points.
            if( weapon != attacker )
                back += weapon->query_weight() / attacker->query_str();
            if( back < 2 )
                back = 2;
        } else {
            back = ACTION_TIME;
        }

        attacker->adjust_time_left( -back );

#ifdef TIMING_INFORM
            do_inform( attacker, "TIMING: %s - adjusting time by: %i",
                attacker->query_name(), ACTION_TIME );
#endif

        if( bonus < 1 )
            bonus = 1;

        // Make the actual damage a weighted average of their skill and
        // the weapon damage.
        if( weapon != attacker ) {
            attack->final_damage = to_int( sqrt(
                to_float( attack->damage * bonus ) ) );
        } else {
            // Let's make unarmed slightly harder to hit with.
            attack->attack_bonus -= 5;
        }

        // Cap the final damage at 3x weapon damage.
        if( attack->final_damage > 3 * attack->damage )
            attack->final_damage = 3 * attack->damage;

        back = attack->final_damage;

        if( weapon != attacker )
            back += weapon->query_weight();
        else
            back += weapon->query_weight() / 40;

        if( ( back = level_out( back ) ) < 0 )
            back = 0;

        back += attack->difficulty;

#ifdef ATTACK_INFORM
        do_inform( attacker, "ATTACK: %s using %s%s, weapon "
            "damage: %i, final damage: %i, difficulty: %i (modifier: %i), "
            "bonus: %i", attacker->query_name(), weapon != attacker ?
            weapon->a_short() : "unarmed", perc ? ", percentage: "+perc : "",
            attack->damage, attack->final_damage * COMBAT_DAMAGE, back,
            attack->difficulty, bonus );
#endif

        tmp = bonus + 50;

        // Test to see if the player can use this attack.
        switch( TASKER->attempt_task_e( back, tmp, 1, 40 ) ) {
          case AWARD :
          case SUCCEED :
            attack->success = 1;
            // Now check if they can have an extra attack too.
            if( extra_attack ) {
                switch( TASKER->attempt_task_e( back, bonus, 1, 80 ) ) {
                  case AWARD :
                  case SUCCEED :
                    register_extra_attack( extra_attack );
                  break;
                  default :
                }
            }
          break;
          default :
            // Let's miss if the attack is way too hard for us,
            // otherwise halve the damage and make it harder to hit.
            if( back > tmp ) {
                attack->success = 0;
                attack->final_damage = 0;
            } else {
                attack->success = 1;
                attack->final_damage /= 2;
                attack->attack_bonus -= 5;
            }
        }

        // Compare their hit point modifiers.
        attack->attack_bonus += hp_modifier(attacker) - hp_modifier(thing);

        // See what our special attack has to say about it.
        if( attack->flags & MODIFY_ATTACK )
            attack = call_other( sp->ob, sp->fun, attack, MODIFY_ATTACK );

        if( !attack->focus )
            attack->focus = attacker->query_combat_focus();

        if( attack->focus && undefinedp( areas[attack->focus] ) )
            attack->focus = 0;

        if( !attack->focus ) {
            // If there is no focus, pick a random body area to hit.
            attack->focus = choice( keys(areas) );
        } else {
            // Make focused attacks slightly easier to defend against.
            attack->attack_bonus -= FOCUS_DEFENSE_BONUS;
        }

        // Pick an area name.
        attack->area = choice( areas[attack->focus] );

        // Make sure the target sees their hit points when attacked.
        if( thing->query_monitor() )
            HEALTH_H->register_monitor( thing, 0 );

        if( !attack->final_damage ) {
            // See what our special attack has to say about it.
            if( attack->flags & MODIFY_MESSAGES )
                attack = call_other( sp->ob, sp->fun, attack, MODIFY_MESSAGES );

            // We missed, print the relevant messages.
            write_messages( 0, 0, attack );
            return finish_attack( attacker, thing, extra );
        }

        // See what our special attack has to say about it.
        if( attack->flags & MODIFY_DAMAGE )
            attack = call_other( sp->ob, sp->fun, attack, MODIFY_DAMAGE );

        // See if a protector moves to accept the blow for the target.
        if( !attack->unprotectable )
            thing = check_protection( thing, attacker );

        if( thing == attack->target ) {
            // Test to see if the target has magical protection.
            // block_attack() should set attack->success to 0 if blocking
            // the attack successfully, -1 if dodging/parrying should
            // still be attempted or 1 if the attack wasn't blocked and
            // dodging/parrying shouldn't be allowed.
            // Only do this if no-one is protecting us.
            if( classp( tmp = thing->block_attack( attack ) ) ) {
                attack = tmp;
                if( attack->success != -1 ) {
                    // See what our special attack has to say about it.
                    if( attack->flags & MODIFY_MESSAGES )
                        attack = call_other( sp->ob, sp->fun, attack,
                                             MODIFY_MESSAGES );
                    write_messages( 0, 0, attack );
                    return finish_attack( attacker, thing, extra );
                }
            }

            // If there was no magical effect blocking.
            if( ( response = thing->query_combat_response() ) == "neutral")
                response = random( 2 ) ? "dodge" : "parry";

            if( !sizeof( thing->query_holding() - ({ 0 }) ) &&
                !thing->query_unarmed_parry() )
                response = "dodge";

            switch( response ) {
              case "dodge" :
                // Test to see if the target dodges.
                attack = dodge_attack( attack );
              break;
              case "parry" :
                // Test to see if the target parries.
                attack = parry_attack( attack );
              break;
              default :
                error( sprintf("%O using an invalid response %O.\n",
                    thing, response ) );
            }

            // The attack was either magically blocked, dodged or parried.
            if( !attack->success ) {
                // See what our special attack has to say about it.
                if( attack->flags & MODIFY_MESSAGES )
                    attack = call_other( sp->ob, sp->fun, attack,
                                         MODIFY_MESSAGES );
                write_messages( 0, 0, attack );
                return finish_attack( attacker, thing, extra );
            }
        } else {
            attack->target = thing;
        }

        // See what our special attack has to say about it.
        if( attack->flags & MODIFY_MESSAGES )
            attack = call_other( sp->ob, sp->fun, attack, MODIFY_MESSAGES );

        // Subtract the target's armour class from the damage.
        back = thing->query_ac( attack->type, attack->final_damage,
                                attack->focus );

#ifdef AC_INFORM
        do_inform( attacker, "AC: %s has AC of %i on %s for %s",
            thing->query_name(), back, attack->focus, attack->type );
#endif

#ifdef DAMAGE_INFORM
        do_inform( attacker, "DAMAGE: %s - damage: %i, AC: %i (%s), "
            "hitting %s for %i", attacker->query_name(),
            attack->final_damage * COMBAT_DAMAGE,
            back * COMBAT_DAMAGE, attack->focus, thing->query_name(),
            ( attack->final_damage - back ) * COMBAT_DAMAGE );
#endif

        weapon->hit_weapon( back, attack->type );

        // Do the damage, if there is any, and print relevant messages.
        write_messages( back, thing->query_stopped(), attack );

        // Do the damage, if any got past through our armour.
        if( attack->final_damage > back ) {
            attack->final_damage -= back;
            thing->adjust_hp( -attack->final_damage * COMBAT_DAMAGE,
                attacker, weapon, attack->name );
        } else {
            // Armour absorbed all of the blow.
            attack->final_damage = 0;
        }

        // Call the weapon's attack functions.
        if( weapon )
            weapon->attack_function( attack->name,
                attack->final_damage * COMBAT_DAMAGE, thing, attacker );

        // See what our special attack has to say about it.
        if( attack->flags & FINISH_ATTACK )
            attack = call_other( sp->ob, sp->fun, attack, FINISH_ATTACK );

    } else {
#ifdef TIMING_INFORM
        do_inform( attacker, "TIMING: %s - no attacks this round.",
            attacker->query_name() );
#endif
    }

    finish_attack( attacker, thing, extra );

} /* attack_round() */
