/**
 * This is the taskmaster handler.
 * It includes functions that deal with all sorts of skill checks
 * and give out skill increases.
 *
 * @changed Changed to use general.language instead of other.language.
 * - Shaydz, 2002.
 * @changed Tried to improve the level of information returned by the
 * perform task function.
 * - Shiannar, 2001.
 * @changed Added a new function to handle TMing points skills.
 * - Sandoz, 2002.
 * @changed Changed compare_skills() to be more skills dependent.
 * - Sandoz, June 2003.
 * @changed Changed success/fail degree to be slightly skill based.
 * - Sandoz, July 2003.
 */

#include <tasks.h>

#undef DEBUG            "shaydz"
#ifdef DEBUG
#define WATCH            "molark"
#endif

#define LOG_STATS        2

/*
 * These are the defines for tweaking the TM rates at
 * different skill levels.
 */
#define BASE             30.0
#define DECAY            350.0
#define MODIFIER         5

#define SAVE_FILES       "/save/tasks/"
#define TIME_PER_USER    1800

#define CONT_OB          control[0]
#define CONT_SK          control[1]
#define CONTROL          ( pointerp(control) && CONT_OB && CONT_SK )

mapping stats;
nosave int last_save;

nosave int last;
nosave string skill;
nosave mixed control;

/** @ignore yes */
void create() { seteuid("Root"); }

varargs mixed attempt_task( int difficulty, int bonus, int upper, mixed extra,
                            int use_class );
varargs mixed attempt_task_e( int difficulty, int bonus, int upper, int half,
                              int use_class );

/** @ignore yes */
int is_valid_tm( object person, string skill ) {

    skill = explode( skill, "." )[0];

//    if( interactive(person) && !person->query_property("tm_"+skill) ) {
//        person->add_property("tm_"+skill, 1, 180 );
//        return 1;
//    }
//
// This is temporary until I decide how I want the tm system to handle things.

    if( interactive(person) && !person->query_property("last_tm") ) {
        person->add_property("last_tm", 1, 300 );
        return 1;
    }

    return 0;

} /* is_valid_tm() */

/** @ignore yes */
mapping query_stats( string s_name ) {
    if( skill != s_name ) {
        skill = s_name;
        if( file_size( SAVE_FILES + skill +".o" ) > 0 )
            unguarded( (: restore_object, SAVE_FILES + skill :) );
        else
            stats = 0;
    }

    if( !stats )
        stats = ([ ]);

    return copy( stats );

} /* query_stats() */

/** @ignore yes */
int query_last() { return last; }

/** @ignore yes */
mixed *query_control() { return control; }

/**
 * This function should only be used in the very rare situations
 * where the last skill checked with query_skill_bonus() wasn't the
 * one relevant for the task attempt.
 *
 * @param args an array consisting of ({ object player, string skill })
 */
void set_control( mixed *args ) { control = args; }

/** @ignore yes */
void reset_control() { control = 0; }

/** @ignore yes */
void award_made( string p_name, string o_name, string s_name, int level ) {
    user_event("inform", "TM:("+ctime(time())+") "+p_name+" gains a level in "+s_name+" from "+
                o_name+" at level "+level, "skill");
    log_file("TMS", "TM:(%s) %s gains a level in %s from %s at level %d\n",
                    ctime(time()),p_name,s_name,o_name,level);

#ifdef LOG_STATS
#if LOG_STATS == 1
    query_stats( s_name );
    if( !stats[ level ] )
        stats[ level ] = ([ ]);
    stats[ level ][ explode( o_name, "#" )[ 0 ] ]++;
#else
    query_stats("summary");

    // These two just skew the stats so we don't record them.
    if( s_name[<7..] == ".points" || s_name[0..13] == "general.language")
        return;

    s_name = explode( s_name, ".")[0];

    if( !stats[s_name])
        stats[s_name] = ({ ({ 0 , 0 }),  ({ 0, 0 }),  ({ 0, 0 }) , ({0,0})});

    switch( level ) {
      case 0..149:
          stats[s_name][0] = ({ stats[s_name][0][0], stats[s_name][0][1]+1 });
      break;
      case 150..299:
          stats[s_name][1] = ({ stats[s_name][1][0], stats[s_name][1][1]+1 });
      break;
      case 300..599:
          stats[s_name][2] = ({ stats[s_name][2][0], stats[s_name][2][1]+1 });
      break;
      default:
          stats[s_name][3] = ({ stats[s_name][3][0], stats[s_name][3][1]+1 });
      break;
    }

    if( last_save < time() - 300 ) {
        unguarded( (: save_object, SAVE_FILES + "summary" :) );
        last_save = time();
    }
#endif
#endif
} /* award_made() */

#if LOG_STATS == 2
/** @ignore yes */
void skill_checked( string s_name, int level ) {
    query_stats("summary");
    if( s_name[<7..] == ".points" || s_name[0..13] == "general.language")
        return;

    s_name = explode(s_name, ".")[0];

    if( !stats[s_name] )
        stats[s_name] = ({ ({ 0 , 0 }),  ({ 0, 0 }),  ({ 0, 0 }), ({0,0}) });

    switch(level) {
      case 0..149:
          stats[s_name][0] = ({ stats[s_name][0][0]+1, stats[s_name][0][1] });
      break;
      case 150..299:
          stats[s_name][1] = ({ stats[s_name][1][0]+1, stats[s_name][1][1] });
      break;
      case 300..599:
          stats[s_name][2] = ({ stats[s_name][2][0]+1, stats[s_name][2][1] });
      break;
      default:
          stats[s_name][3] = ({ stats[s_name][3][0]+1, stats[s_name][3][1] });
      break;
    }

    if( last_save < time() - 300 ) {
        unguarded( (: save_object, SAVE_FILES + "summary" :) );
        last_save = time();
    }
} /* skill_checked() */
#endif

/** @ignore yes */
string *query_skill_files() {
    return unguarded( (: get_dir, SAVE_FILES +"*.o" :) );
} /* query_skill_files() */

/** @ignore yes */
void clear_skill_files() {
    string word;
    foreach ( word in unguarded( (: get_dir, SAVE_FILES +"*.o" :) ) )
    unguarded( (: rm, SAVE_FILES + word :) );
    skill = 0;
} /* clear_skill_files() */

/**
 * This function will attempt a task.  It handles all the stuff about
 * looking up the skill, and giving the tm advance, but doesn't give
 * any messages to the player, you'll have to do that.
 *
 * @param person the one attempting the task (could be any living thing)
 * @param skill the skill tested against
 * @param difficulty the lowest bonus where the attempt can succeed
 * @param tm_type This should use one of the standard definitions in
 *        /include/tasks.h
 *        They are:
 *        TM_FIXED - for use where the difficulty is a fixed value
 *        TM_FREE  - for use when the tm attempt doesn't cost anything.
 *        TM_CONTINUOUS - for use in continuous actions eg. combat or sneak
 *        TM_COMMAND - for use with guild commands
 *        TM_RITUAL - when the action is a ritual
 *        TM_SPELL - when the action is a spell
 * @param use_class This is 0 when you don't want a class returned,
 * and 1 when you do.
 *
 * @return BARF if something screwed up, AWARD if the task succeeded, and
 * should give an advance, SUCCEED if it succeeded, FAIL if it failed.
 *
 * @example
 *
 * switch( TASKER->perform_task( person, "covert.manipulation.stealing", TM_COMMAND ) ) {
 *  case AWARD :
 *    tell_object( person, "%^YELLOW%^You manage to grasp the principles "
 *                "of stealing more firmly.%^RESET%^\n");
 *    // Note, no break;
 *  case SUCCEED :
 *    // Whatever happens when it succeeds
 *    break;
 *  default :
 *    // Whatever happens when it fails
 * }
 */
varargs mixed perform_task( object person, string skill, int difficulty,
                            int tm_type, int use_class ) {
    int bonus, extra;
    mixed result;

    bonus = person->query_skill_bonus( skill );

    if( difficulty )
        extra = 6 * sqrt(difficulty);

    switch( tm_type ) {
    case TM_FIXED:
      result = attempt_task( difficulty, bonus, 100, extra, use_class );
    break;
    case TM_FREE:
      result = attempt_task( difficulty, bonus, 25, extra, use_class );
    break;
    case TM_CONTINUOUS:
      result = attempt_task( difficulty, bonus, 40, extra, use_class );
    break;
    case TM_COMMAND:
      if( explode( skill, ".")[0] == "covert")
          result = attempt_task_e( difficulty, bonus, 50, 30, use_class );
      else
          result = attempt_task( difficulty, bonus, 50, extra, use_class );
    break;
    case TM_RITUAL:
      result = attempt_task_e( difficulty, bonus, 30, 25, use_class );
    break;
    case TM_SPELL:
      result = attempt_task_e( difficulty, bonus, 30, 40, use_class );
    break;
    case TM_NONE:
      result = attempt_task_e( difficulty, bonus, 1, extra, use_class );
      if( result == AWARD )
          result = SUCCEED;
    break;
    default:
      error("Invalid TM type in perform_task().\n");
    }

    if( classp(result) ) {
        if( result->result == AWARD ) {
            if( !is_valid_tm( person, skill ) ||
                !person->add_skill_level( skill, 1, PO ) ) {
                result->result = SUCCEED; // No advance.
            }
        }
    } else {
        if( result == AWARD ) {
            if( !is_valid_tm( person, skill ) ||
                !person->add_skill_level( skill, 1, PO ) ) {
                result = SUCCEED; // No advance.
            }
        }
    }

    return result;

} /* perform_task() */

/**
 * This function will compare the skills of two objects and return which one
 * won and if the winner got a TM.
 * With equal skills the chances are 50/50 as to who will win. As the balance
 * shifts so do the chances. Additionally a modifier can be applied to
 * account for conditions favouring one or the other. This should be
 * considered a percentage eg. -50 will add 50% to the defenders chances of
 * winning.
 *
 * @param offob the attacking object
 * @param offskill the name of the skill the attacker is using
 * @param deffob the defending object
 * @param deffskill the name of the skill the defender is using
 * @param modifier the percentage modifier
 * @param off_tm_type this should be one of the standard definitions in
 * /include/tasks.h and is for the attacker
 * @param def_tm_type this should be one of the standard definitions in
 * /include/tasks.h and is for the defender
 * @param use_class whether or not to return a class like perform_task()
 *
 * @example
 *
 * switch( TASKER->compare_skills( attacker, "fighting.combat.melee.sharp",
 *                                 defender, "fighting.combat.parry.unarmed",
 *                                 25, TM_COMMAND, TM_FREE ) {
 *   case OFFAWARD:
 *     tell_object( attacker, "%^YELLOW%^You manage to grasp one of the "
 *         "principles of slicing people up more firmly.%^RESET%^\n");
 *   case OFFWIN:
 *     tell_object( defender, "You lose an arm.\n");
 *     tell_room( ENV(attacker), defender->one_short()+" loses an arm.\n",
 *         defender );
 *   break;
 *   case DEFAWARD:
 *     tell_object( defender, "%^YELLOW%^You feel more able to keep your "
 *         "arms attached when parrying unarmed.%^RESET%^\n");
 *   case DEFWIN:
 *     tell_object( defender, "You keep your arm attached.\n");
 *     tell_room( ENV(defender), defender->one_short()+" keeps "+
 *         defender->HIS+" arm attached.\n", defender );
 *   break;
 * }
 *
 * @see perform_task()
 *
 */
varargs mixed compare_skills( object offob, string offskill, object defob,
              string defskill, int modifier, int off_tm_type, int def_tm_type,
              int use_class ) {
    int offbonus, defbonus, percent;
    mixed result;

    offbonus = offob->query_skill_bonus(offskill);
    defbonus = defob->query_skill_bonus(defskill);

    if( !offbonus && !defbonus ) {
        percent = 50;
    } else {
        percent = ( offbonus * 100 ) / ( offbonus + defbonus );
        if( offbonus > defbonus )
            percent += 100 * offbonus / ( offbonus + defbonus ) - 50;
        else if( defbonus > offbonus )
            percent -= 100 * defbonus / ( offbonus + defbonus ) - 50;
    }

    // The difficulty may be weighted.
    percent += modifier;

    if( random(100) < percent ) {
        // The winner is the offender, now do a TM check.
        result = perform_task( offob, offskill, defbonus + modifier,
                               off_tm_type, use_class );
        if( classp(result) ) {
            result->result = ( result->result == AWARD ? OFFAWARD : OFFWIN );
            return result;
        } else {
            return ( result == AWARD ? OFFAWARD : OFFWIN );
        }
    } else {
        // The winner is the defender.
        result = perform_task( defob, defskill, offbonus + modifier,
                               def_tm_type, use_class );
        if( classp(result) ) {
            result->result = ( result->result == AWARD ? DEFAWARD : DEFWIN );
            return result;
        } else {
            return ( result == AWARD ? DEFAWARD : DEFWIN );
        }
    }

} /* compare_skills() */

/**
 * This function will attempt to figure out if a tm should be given
 * in the points skill used.  It handles all the stuff about looking
 * up the skill, giving the tm advance, and reducing the guild points.
 * It will also give a generic tm message to the player.
 *
 * @param person the one attempting the points task (could be any living thing)
 * @param type the type (covert, magic etc.) of points skill to check against
 * @param amount the amount of guild points to check against
 * @return 1 if player has enough available guild points of the type, 0 if not
 *
 * @example
 *
 * if( !TASKER->point_tasker( person, "covert", 80 ) ) {
 *     add_failed_mess("You can't concentrate enough to hide.");
 *     return 0;
 * }
 */
int point_tasker( object person, string type, int amount ) {
    string skill;
    int m, level, bonus;
    float b;

    if( ( amount < 1 ) || ( person->query_gp() < amount ) )
        return 0;

    person->adjust_gp( -amount );

    skill = "general.points";

    level = (int)person->query_skill( skill );
    bonus = (int)person->query_skill_bonus( skill );

    b = to_float( ( bonus < 50 ? 50 : bonus ) + ( level < 50 ? 50 : level ) );

    m = (int)person->stat_modify( 10, skill, 1 );

    if( random(1000) < to_int( 25 * sqrt( to_float( 20 + amount ) ) * ( m / b ) ) &&
        is_valid_tm( person, type ) && person->add_skill_level( skill, 1, PO ) )
        tell_object( person, "%^YELLOW%^You feel more able to concentrate "
            "on this task than you thought.%^RESET%^\n");

    return 1;

} /* point_tasker() */

/** @ignore yes */
float calc_upper( mixed upper, int bonus ) {
    float tmp;

#ifdef DEBUG
    tell_creator( DEBUG, "TM: %s - %s [lvl: %d, bonus: %d] OU: %O",
        CONT_OB->query_name(), CONT_SK, CONT_OB->query_skill(CONT_SK),
        bonus, upper );
#endif

    // Reduce the upper dependant on their stats.
    upper = CONT_OB->stat_modify( upper, CONT_SK );

#ifdef DEBUG
    tell_creator( DEBUG, "Statted Upper: %O", upper );
#endif

    // Reduce the upper dependant on their level.
    tmp = exp( ( CONT_OB->query_skill(CONT_SK) - BASE ) / DECAY );
    upper = upper / tmp - MODIFIER;

#ifdef DEBUG
    tell_creator( DEBUG, "Levelled Upper: %O", upper );
#endif

    // Prevent upper from going negative.
    if( upper < 0 )
        upper = 0;

#ifdef DEBUG
    tell_creator( DEBUG, "Final Upper: %O", upper );
#endif

    return upper;

} /* calc_upper() */

/**
 * DO NOT USE THIS FUNCTION. Use perform_task() instead.
 * This function will attempt a task and return whether it succeeded.<br>
 * <br>
 * Chance of      /|\<br>
 * success  100% __|            ______..<br>
 *                 |           /<br>
 *                 |          /<br>
 *                 |         /<br>
 *            0% __| .._____/<br>
 *                 |_____________________\   Player's bonus<br>
 *                          |   |        /<br>
 *                 difficulty   difficulty + margin<br>
 * <br>
 * Chance of       /|\<br>
 * gaining  upper __|        .<br>
 *                  |        |\<br>
 *                  |        | \<br>
 *                  |        |  \<br>
 *             0% __| .._____|   \_____..<br>
 *                  |_____________________\  Player's bonus<br>
 *                           |   |        /   <br>
 *                  difficulty   difficulty + margin<br>
 * <br>
 * @param difficulty the lowest bonus where the attempt can succeed
 * @param bonus the bonus the player has in the relevant skill
 * @param upper the maximum chance of getting an advance
 * @param extra the margin control. If it is an int, the margin is set
 * to extra. It it's 0 the margin will be calculated automatically from
 * the difficulty as 3*sqrt(difficulty), if it's an array, it'll be
 * calculated as extra[0]+extra[1]*sqrt(difficulty)
 * @return BARF if something screwed up, AWARD if the task succeeded, and
 * should give an advance, SUCCEED if it succeeded, FAIL if it failed.
 * @see perform_task
 */
mixed attempt_task( int difficulty, int bonus, int upper, mixed extra,
                    int use_class ) {
    class task_class_result return_class;
    int margin, result;

#if LOG_STATS == 2
    if( CONTROL )
        skill_checked( CONT_SK, CONT_OB->query_skill( CONT_SK ) );
#endif

    // If the bonus is below the difficulty, they fail.
    if( bonus < difficulty ) {
        if( use_class ) {
            return_class = new( class task_class_result );
            return_class->result = FAIL;

            // Compatible with degree of failure, and not always critical.
            if( difficulty < 1 )
                difficulty = 1;

            return_class->degree = 100 * bonus / difficulty;
            return_class->degree -= 100 + random(50);

            if( return_class->degree < -100 )
                return_class->degree = -100;

            return return_class;
        } else {
            return FAIL;
        }
    }

    // Work out the margin between total failure and total success.
    if( !extra )
        if( !difficulty )
            margin = 6;
        else
            margin = 6 * sqrt( difficulty );
    else {
        if( intp( extra ) )
            margin = extra;
        if( pointerp( extra ) )
            margin = extra[ 0 ] + extra[ 1 ] * sqrt( difficulty );
    }

    if( !margin )
        margin = 1;

    // If the bonus is above the margin, they succeed.
    if( bonus > difficulty + margin ) {
        if( use_class ) {
            return_class = new( class task_class_result );
            return_class->result = SUCCEED;

            // Compatible with degree of failure, and not always critical.
            if( bonus < 1 )
                bonus = 1;

            return_class->degree = 100 + random(50);
            return_class->degree -= 100 * ( difficulty + margin ) / bonus;

            if( return_class->degree > 100 )
                return_class->degree = 100;

            return return_class;
        } else {
            return SUCCEED;
        }
    }

    // They might fail in the margin.
    result = 50 * ( bonus - difficulty ) / margin - random(50);

    // This is so that the degree would be from -50 to -1 or 1 to 50.
    if( result < 1 )
        result--;

    if( use_class ) {
        return_class = new( class task_class_result );
        return_class->degree = result;
    }

    if( result < 0 ) {
#ifdef DEBUG
        if( CONTROL && CONT_OB->query_name() == WATCH )
            tell_creator( DEBUG, "TM: %s Skill: %s [%d] [%d] - FAILED",
                CONT_OB->query_name(), CONT_SK, bonus, difficulty );
#endif
        if( use_class ) {
            return_class->result = FAIL;
            return return_class;
        } else {
            return FAIL;
        }
    }

    // If information is available, adjust the chance to award based on stats.
    if( CONTROL )
        upper = calc_upper( upper, bonus );

    // If they succeed, they might be awarded a level.
#ifdef DEBUG
    tell_creator( DEBUG, "TM variable %d.",
        ( upper * ( difficulty + margin - bonus + 5 ) ) / margin );
#endif
    if( random(200) < ( upper * ( difficulty + margin - bonus + 5 ) ) / margin ) {
        if( use_class) {
            return_class->result = AWARD;
            return return_class;
        } else {
            return AWARD;
        }
    }

    if( use_class ) {
        return_class->result = SUCCEED;
        return return_class;
    } else {
        return SUCCEED;
    }

} /* attempt_task() */

/**
 * DO NOT USE THIS FUNCTION. Use perform_task() instead.
 * This method acts like attempt_task() except that the failure chance
 * starts at 100% at the difficulty and is halved every (half) bonus levels.
 *
 * @param difficulty the lowest bonus where the attempt can succeed
 * @param bonus the bonus the player has in the relevant skill
 * @param upper the maximum chance of getting an advance
 * @param half every time the bonus rise by half, the failure
 * chance is halved
 *
 * @return BARF is something screwed up, AWARD if the task succeeded, and
 * should give an advance, SUCCEED if it succeeded, FAIL if it failed.
 *
 * @see perform_task
 */
varargs mixed attempt_task_e( int difficulty, int bonus, mixed upper,
                              int half, int use_class ) {
    class task_class_result return_class;
    float fail_chance, degree, tmp;

#ifdef DEBUG
    tell_creator( DEBUG, "Difficulty[%d], Bonus[%d], Upper[%d], Half[%d]",
        difficulty, bonus, upper, half );
#endif

#if LOG_STATS == 2
    if( CONTROL )
        skill_checked( CONT_SK, CONT_OB->query_skill(CONT_SK) );
#endif

    // If the bonus is below the difficulty, they fail.
    if( bonus < difficulty ) {
        if( use_class ) {
            return_class = new( class task_class_result );
            return_class->result = FAIL;

            // Compatible with degree of failure, and not always critical.
            if( difficulty < 1 )
                difficulty = 1;

            return_class->degree = 100 * bonus / difficulty;
            return_class->degree -= 100 + random(50);

            if( return_class->degree < -100 )
                return_class->degree = -100;

            return return_class;
        } else {
            return FAIL;
        }
    }

    if( !half )
        half = 2 * sqrt( difficulty );

    fail_chance = exp( ( -0.693 * ( bonus - difficulty ) ) / half );

    degree = ( random(100) + ( 100 * ( 1 - fail_chance ) ) - 99 );

    // The degree will be 50 units wide.
    switch( to_int(degree) ) {
      case -1 :
      break;
      case 0 :
        degree++;
      break;
      case 1 :
      break;
      default :
        degree /= 2;
    }

    // This means we can no longer fail the task,
    // so we make our degree rise above the 0-49 range.
#ifdef DEBUG
        tell_creator( DEBUG, "Fail chance (first): %O", fail_chance );
#endif
    if( fail_chance * 100 < 1 ) {
        tmp = 50 + ( 50 * ( ( 100 * ( 1 - fail_chance ) ) - 100 ) );
        if( tmp < 1 )
            degree++;
        else
            degree += tmp;
    }

    if( degree > 99 )
        degree = 99;

    if( use_class ) {
        return_class = new( class task_class_result );
        return_class->degree = degree;
    }

    if( degree < 0 ) {
#ifdef DEBUG
        tell_creator( DEBUG, "Fail chance: %O", fail_chance );
#endif
        if( use_class ) {
            return_class->result = FAIL;
            return return_class;
        } else {
            return FAIL;
        }
    }

    // If information is available, adjust the chance to award based on stats.
    if( CONTROL )
        upper = calc_upper( upper, bonus );

    // If they succeed, they might be awarded a level.
#ifdef DEBUG
    tell_creator( DEBUG,
        "TM chance: fail chance: %O\n"
        "TM chance: part 1: random(1000) < %O\n"
        "TM chance: part 2: %O < %O",
        fail_chance, ( upper * fail_chance * 5 ),
        bonus, ( difficulty + ( half * 5 ) ) );
#endif

    if( random(1000) < ( upper * fail_chance * 5 ) &&
        bonus < ( difficulty + ( half * 5 ) ) ) {
#ifdef DEBUG
        tell_creator( DEBUG, "TM given out, difficulty was %O, "
            "upper was %O, bonus was %O.\n---", difficulty, upper, bonus );
#endif
        if( use_class ) {
            return_class->result = AWARD;
            return return_class;
        } else {
            return AWARD;
        }
    }

#ifdef DEBUG
    tell_creator( DEBUG, "---");
#endif

    if( use_class ) {
        return_class->result = SUCCEED;
        return return_class;
    } else {
        return SUCCEED;
    }

} /* attempt_task_e() */
