/**
 * This is the basic effects module.
 * Extracted from Ember's living effects code by Deutha.
 * @changed 4-6-1997, Turrican
 * To use arrays of classes, and to allow function pointers.
 * @changed 17-10-1997 Olorin
 * Fixed a bug then adding an effect in the end() function of
 * another effect.
 * @changed 03-09-2002 Sandoz
 * Changed to get shadow objects from the shadows handler.
 * @see help::effects
 */

#include <effect.h>

class effect_shadow {
   object shad_ob;
   int idnum;
}

class effect_event {
   int inctime;
   mixed func;
   int eff_ob_num;
   mixed interval;
   int flags;
}

void delete_effect( int i );

// This keeps track of the effect number being called (beginning/end/etc.).
private nosave int current_enum;
private nosave int next_id;

#undef DEBUG

#ifdef DEBUG
nosave int logging_effects;
void set_logging_effects( int i ) { logging_effects = i; }
int query_logging_effects() { return logging_effects; }
#endif

// This stores shadows for corresponding effects as shadow_ob, idnum.
private nosave class effect_shadow *shadows;

// This stores effects currently active on player as "effect_ob_name", arg
private class effect *effs;

/*
 * effect event queue
 *
 *    This stores all effect events going to be happening...
 *
 *    time_from_previous_event, "function", eff_ob_num, interval, flags
 *
 * where flags can be
 *
 *   EE_REMOVE
 *   EE_CONTINUOUS
 *   EE_ONCE
 *
 * and interval can be
 *   number_of_secs
 *   ({ min_secs, max_secs })  ; "1" dice roll
 *   ({ min_secs, max_secs, n })   ; "n" dice rolls
 *
 * ee are added with
 *   submit_ee("function", interval, flags);
 *
 */
private class effect_event *eeq;

protected void create() {
    effs = ({ });
    shadows = ({ });
    eeq = ({ });
    next_id = 0;
    current_enum = -1;
#ifdef DEBUG
    logging_effects = 0;
#endif
} /* create() */

/**
 * This method removes all the current effects off the object
 * and sets everything back to the initial state.
 * @see add_effect()
 */
void reset_effects() {
    effs = ({ });
    shadows = ({ });
    eeq = ({ });
    current_enum = -1;
    remove_call_out("effect_timer");
#ifdef DEBUG
    if( logging_effects )
        log_file("EFFECT_WOBBLE", "%d:%s(%d) reset_effects:"
            "remove_call_out(\"effect_timer\")\n", time() % 1000,
            TO->query_name(), current_enum );
#endif
} /* reset_effects() */

/**
 * This method returns the outermost shadow on this object.
 * This is useful for making sure functions get called right
 * through the shadow chain.  If there are no objects being
 * shadows, this_object() is returned.
 * @return the outermost shadow object
 */
object affected_object() {
    object this, other;

    this = other = TO;

    while( objectp(other) ) {
        this = other;
        other = query_shadowing(this);
    }

    return this;

} /* affected_object() */

/**
 * This method freezes all the current effects so that they do
 * not continue to be processed.  Basicly it removes the call_out
 * for the effect_timer().  It also ensures the intrval for the
 * immediately pending effect
 * is correct.
 * @see effect_timer()
 * @see add_effect()
 */
void effect_freeze() {
    /* stop effect_timer call_out and put the remaining
     * time value into EEQ_INCTIME of first element */
    int timeleft;

    timeleft = remove_call_out("effect_timer");

#ifdef DEBUG
    if( logging_effects )
        log_file("EFFECT_WOBBLE", "%d:%s(%d) effect_freeze:"
            "remove_call_out(\"effect_timer\")=%d\n", time() % 1000,
            TO->query_name(), current_enum, timeleft );
#endif

    if( sizeof( eeq ) )
        eeq[ 0 ]->inctime = timeleft;

} /* effect_freeze() */

/** @ignore yes */
private void quit_save_effects( string func ) {
    int i, neffs;
    string effn;
    mixed arg;

    neffs = sizeof( effs );

    for( i = 0; i < neffs; i++ ) {
        effn = effs[ i ]->ob_name;
        arg = effs[ i ]->arg;
        if( pointerp(arg) && sizeof(arg) == 3 && arg[ 2 ] == BOGUS_OLD_ARG )
            arg = arg[ 1 ];
        if( effn )
            catch( call_other( effn, func, affected_object(), arg, i ) );
    }

} /* quit_save_effects() */

/**
 * @ignore yes
 * This method is called when a player actually saves.
 * It calls the quitting method on all the effects.
 */
void effects_saving() { quit_save_effects("saving"); }

/**
 * @ignore yes
 * This method is called when a player actually quits.
 * It calls the quitting method on all the effects.
 */
void effects_quiting() { quit_save_effects("quiting"); }

/**
 * This method restarts the internal call_out.
 * @see effects_freeze()
 * @see add_effect()
 */
void effect_unfreeze() {
    /* Restart the timer, checking that it hasn't been restarted
     * already by a nested unfreeze.
     */
    int time;

    if( sizeof( eeq ) ) {
#ifdef DEBUG
        if( logging_effects )
            log_file("EFFECT_WOBBLE", "%d:%s(%d) effect_unfreeze:"
                "call_out(\"effect_timer\", %d )\n", time() % 1000,
                TO->query_name(), current_enum, eeq[ 0 ]->inctime );
#endif
        time = find_call_out("effect_timer");
        if( time != -1 )
            remove_call_out("effect_timer");
        call_out("effect_timer", eeq[ 0 ]->inctime );
   }
} /* effect_unfreeze() */

/** @ignore yes */
protected int int_submit_ee( int eff_ob_num, mixed fun, mixed interval,
                             int flags ) {
    /*
     * This calculates next occurence of this ee and inserts it into the eeq.
     * Note that it can only be called sandwiched between freeze and
     * unfreeze calls.
     */
    int i, ntime;

#ifdef DEBUG
    if( logging_effects )
        log_file("EFFECT_WOBBLE", "%d:%s(%d) int_submit_ee:"
            "( %d, %O, %O, %s )\n", time() % 1000, TO->query_name(),
            current_enum, eff_ob_num, fun, interval,
            ({"once", "remove", "continuous"})[flags] );
#endif
    if( intp(interval) )
        ntime = interval;
    else if( pointerp(interval) ) {
        switch( sizeof(interval) ) {
         case 0:
           return -1;
         case 1:
           ntime = interval[0];
         break;
         case 2:
           ntime = interval[0] + random( interval[1] - interval[0] + 1 );
         break;
         case 3:
           ntime = 0;
           for( i = 0; i < interval[2]; i++ )
               ntime += interval[0] + random( interval[1] - interval[0] + 1 );
           ntime += interval[2] / 2;
           ntime /= interval[2];
         break;
         default:
           return -1;
        }
    } else
        return -1;

    /* If the flag is EE_REMOVE, and one exists for EEQ_EFF_OB already,
     * remove the old one.  This is for occasions when an EE_REMOVE is
     * called from merge_effect() */
    if( flags == EE_REMOVE ) {
        for( i = 0; i < sizeof(eeq); i++ )
            if( eeq[i]->eff_ob_num == eff_ob_num &&
                eeq[i]->flags == EE_REMOVE ) {
                eeq = delete( eeq, i, 1 );
                break;
            }
    }

    /*
     * This removes all scheduled ee's with the
     * specified flag and function.
     */
    if( ntime < 0 ) {
        if( flags != EE_REMOVE ) {
            for( i = 0; i < sizeof(eeq); i++ )
                if( eeq[i]->eff_ob_num == eff_ob_num &&
                    eeq[i]->flags == flags && eeq[i]->func == fun )
                    eeq = delete( eeq, i, 1 );
        }
        return 0;
    }

    for( i = 0; i < sizeof(eeq); i++ ) {
        /* goes in here! */
        if( ntime < eeq[i]->inctime ) {
            eeq[i]->inctime -= ntime;
            eeq = eeq[0..i-1] + ({ new( class effect_event, inctime : ntime,
                  func : fun, eff_ob_num : eff_ob_num, interval : interval,
                  flags : flags ) }) + eeq[i..];
            break;
        }
        ntime -= eeq[i]->inctime;
    }

    if( i == sizeof(eeq) && eeq ) {
        eeq += ({ new( class effect_event,
                       inctime    : ntime,
                       func       : fun,
                       eff_ob_num : eff_ob_num,
                       interval   : interval,
                       flags      : flags )
                       });
    } else if( !sizeof(eeq) ) {
        /* This shouldn't happen, but it does sometimes!
         * Note from Olorin: without testing for !sizeof(eeq), this
         * code mangles the cases where the queue exists and the event
         * already inserted by the for loop.
         */
        eeq = ({ new( class effect_event,
                      inctime    : ntime,
                      func       : fun,
                      eff_ob_num : eff_ob_num,
                      interval   : interval,
                      flags      : flags )
                      });
    }

    return i;

} /* int_submit_ee() */

/**
 * This submits an effect event schedule.  It will call "function name" in
 * your effect object after the interval specified in interval_spec, with
 * behaviour modified by flags.
 * interval_spec can be one of:
 * <dl><dt>n
 * <dd>time in seconds
 * <dt>({ m, n })
 * <dd>minimum time m seconds, maximum time n seconds, simple random
 *     distribution
 * <dt>({ m, n, r })
 * <dd>as for the ({ m, n }) case, except the random factor is effectively
 *     "rolled" r times ... the higher r is, the more likely the interval
 *     is to be close to (m + n)/2.
 * <dt>If the interval is a negative figure, any functions with the
 *     specified function name will be removed from the queue.
 *     This is useful in removing unwanted things from the effects queue.
 * </dl>
 * flags may be:
 * <dl>
 * <dt>EE_REMOVE
 * <dd>remove the effect from the player after the function call
 * <dt>EE_CONTINUOUS
 * <dd>do it repeatedly.  Default (EE_ONCE) is only do it once.
 * <dt>EE_ONCE
 * <dd>do it once
 * </dl>
 * These are defined in /include/effect.h
 * <p>
 * Only one EE_REMOVE can be in place at a time.  Subsequent EE_REMOVEs
 * will wipe previous ones.
 * <p>
 * NB:  submit_ee can ONLY be called from the effect object itself in the
 * course of a beginning/handler/end call, or from the effect shadow.
 * @see submit_ee2()
 * @see /include/effect.h
 * @see add_effect()
 * @param fun the function to call
 * @param interval the interval specifier
 * @param flags the flags for the event
 */
void submit_ee( mixed fun, mixed interval, int flags ) {
    /* public access point for int_submit_ee ... it uses current_enum or
       previous_object (for shadows) to determine what effect it refers to */
    int enumb;

#ifdef DEBUG
    if( logging_effects )
        log_file("EFFECT_WOBBLE", "%d:%s(%d) submit_ee:( %O, %O, %s )\n",
            time() % 1000, TO->query_name(), current_enum, fun, interval,
            ({"once","remove","continuous"})[flags] );
#endif

    if( ( enumb = current_enum ) < 0 ) {
        enumb = member_array( 1, map( shadows, (: $1 &&
            ((class effect_shadow)$1)->shad_ob == PO :) ) );
        if( enumb < 0 )
            error("Cannot submit from that object.");
    }

    effect_freeze();
    int_submit_ee( enumb, fun, interval, flags );
    effect_unfreeze();

} /* submit_ee() */

/**
 * This submits an effect event for a specific effect.
 * Apart from this it is the same as submit_ee()
 * @param enum the enum of the effecrt
 * @param fun the function to call
 * @param interval the interval specifier
 * @param flags the flagds associated with the event
 */
void submit_ee2( int enum, mixed fun, mixed interval, int flags ) {
    /* public access point for int_submit_ee ... it uses enum
     * to determine what effect it refers to (for those cases where
     * current_enum isn't defined)
     */

#ifdef DEBUG
    if( logging_effects )
        log_file("EFFECT_WOBBLE", "%d:%s(%d) int_submit_ee:"
            "( %d, %O, %O, %s )\n", time() % 1000,
            TO->query_name(), current_enum, enum, fun, interval,
            ({"once","remove","continuous"})[flags] );
#endif

    if( enum < 0 )
        error("Cannot submit from that object.");

    effect_freeze();
    int_submit_ee( enum, fun, interval, flags );
    effect_unfreeze();

} /* submit_ee() */

/**
 * This method returns the time until any EE_REMOVE effect
 * is expected to occur.  It will return -1 if no remove event
 * is scheduled.  If the flag is not set to true, the the
 * current enum is checked, otherwise the new_enum is checked.
 * @param flag if true, use new_enum not current_enum
 * @return the time until the remove event will occur,
 * or -1 if none is scheduled
 * @see submit_ee()
 * @see aff_effect()
 */
int expected_tt( int flag, int new_enum ) {
    int timeleft, enum;

    if( flag )
        enum = new_enum;
    else
        enum = current_enum;

    if( enum < 0 )
        return -1;

    if( !sizeof(eeq) )
        return -1;

    // Stop the event timer.
    effect_freeze();

    // Add up the incremental times in the queue until you get to the
    // EE_REMOVE for the one your asking about.
    foreach( class effect_event eff in eeq ) {
        timeleft += eff->inctime;
        if( eff->eff_ob_num == enum && eff->flags == EE_REMOVE ) {
            // Restart the event timer.
            effect_unfreeze();
            return timeleft;
        }
    }

    // Restart the event timer.
    effect_unfreeze();
    return -1;

} /* expected_tt() */

/**
 * This method adds an effect onto the object.  The arg is passed
 * directly onto the function 'beginning' on the effect object.
 * If the result is non-zero then the return value of the begining
 * function is used instead of the arg and stored away.  If an
 * effect of the same type is already on the object then the
 * function 'merge_effect' will be called on the effect object.
 * If it returns a non-zero value then the arg for the initial
 * effect will be updated to the new value, otherwise both effects
 * will run with different arguments.
 * @see help::effects
 * @see submit_ee()
 */
void add_effect( string eff, mixed arg ) {
    string shad;
    object ob, effob;
    mixed hbf, res;
    int i, old_current_enum, enum;

#ifdef DEBUG
    if( logging_effects )
        log_file("EFFECT_WOBBLE", "%d:%s(%d) add_effect:(%s,%O)\n",
            time() % 1000, TO->query_name(), current_enum, eff, arg );
#endif

    if( !( hbf = (mixed)eff->query_secs_between_hb() ) &&
        ( hbf = (mixed)eff->query_heart_beat_frequency() ) && intp(hbf) )
        hbf *= 60;

    old_current_enum = current_enum;

    if( !effob = find_object(eff) )
        error("Bad effect object.");

    for( i = 0; i < sizeof(effs); i++ ) {
        if( effs[i]->ob_name == eff ) {
            if( function_exists("merge_effect", effob ) ) {
                current_enum = i;
                if( hbf ) {
                    if( res = (mixed)effob->merge_effect( affected_object(),
                        effs[i]->arg[1], arg ) )
                        effs[i]->arg[1] = res;
                } else {
                    if( res = (mixed)effob->merge_effect( affected_object(),
                        effs[i]->arg, arg ) )
                        effs[i]->arg = res;
                }
                current_enum = old_current_enum;
                return;
            }
        }
    }

    if( shad = (string)effob->query_shadow_ob() ) {
        ob = (object)SHADOW_H->get_shadow(shad);
        shadows += ({ new( class effect_shadow, shad_ob : ob,
                      idnum : next_id ) });
        ob->attach_to_player( affected_object(), next_id );
    } else {
        shadows += ({ new( class effect_shadow, shad_ob : 0,
                      idnum : next_id ) });
    }

    current_enum = sizeof(effs);
    enum = current_enum;

    effs += ({ new( class effect, ob_name : eff, arg : arg ) });

    if( function_exists("beginning", effob ) ) {
        if( res = (mixed)effob->beginning( affected_object(), arg, next_id ) )
            effs[enum]->arg = res;
    }

    next_id++;

    if( hbf ) {
        submit_ee("effect_heart_beat", hbf, EE_CONTINUOUS | EE_OLD );
        effs[enum]->arg = ({ 0, effs[<1]->arg, BOGUS_OLD_ARG });
    }

    current_enum = old_current_enum;

} /* add_effect() */

#define EFF_OB_NAME 0
#define EFF_ARG 1

#define EEQ_INCTIME 0
#define EEQ_FUNC 1
#define EEQ_EFF_OB 2
#define EEQ_INTERVAL 3
#define EEQ_FLAGS 4

#define EFF_SIZE 2
#define EEQ_SIZE 5

/** @ignore yes */
protected void convert_arrays() {
    int i, neffs, neeq;
    mixed old;

    if( sizeof(effs) && !classp(effs[0]) ) {
        old = effs;
        effs = allocate( neffs = sizeof(old) / EFF_SIZE );
        for( i = 0; i < neffs; i++ )
            effs[i] = new( class effect,
                ob_name : old[i*EFF_SIZE+EFF_OB_NAME],
                arg     : old[i*EFF_SIZE+EFF_ARG] );
    }

    if( sizeof(eeq) && !classp(eeq[0]) ) {
        old = eeq;
        eeq = allocate( neeq = sizeof(eeq) / EEQ_SIZE );
        for( i = 0; i < neeq; i++ )
            eeq[i] = new( class effect_event,
                inctime    : old[ i * EEQ_SIZE + EEQ_INCTIME ],
                func       : old[ i * EEQ_SIZE + EEQ_FUNC ],
                eff_ob_num : old[ i * EEQ_SIZE + EEQ_EFF_OB ],
                interval   : old[ i * EEQ_SIZE + EEQ_INTERVAL ],
                flags      : old[ i * EEQ_SIZE + EEQ_FLAGS ] );
    }

} /* convert_arrays() */

/**
 * @ignore yes
 * This method is called after restore_object is done to init shadows etc.
 */
void init_after_save() {
    int i, neffs, *ee_exists;
    string shad, effn;
    object ob;
    mixed arg;

    convert_arrays();

    shadows = allocate( neffs = sizeof(effs) );

    for (i = 0; i < neffs; i++) {
        effn = effs[i]->ob_name;
        shadows[i] = new( class effect_shadow, idnum : next_id );
        if( catch( shad = (string)effn->query_shadow_ob() ) )
            continue;
        if( shad ) {
            ob = (object)SHADOW_H->get_shadow(shad);
            shadows[i]->shad_ob = ob;
            ob->attach_to_player( affected_object(), next_id );
        }

        current_enum = i;
        arg = effs[i]->arg;

        if( pointerp(arg) && sizeof(arg) == 3 && arg[ 2 ] == BOGUS_OLD_ARG )
            arg = arg[1];

        catch( effn->restart( affected_object(), arg, next_id++ ) );

    }

    ee_exists = allocate(neffs);

    for( i = 0; i < sizeof(eeq); i++ )
        ee_exists[eeq[i]->eff_ob_num] = 1;

    for( i = sizeof(ee_exists) - 1; i >= 0; i-- ) {
        if( catch( ob = load_object(effs[i]->ob_name) ) || !ob ) {
            delete_effect(i);
            continue;
        }
        if( !ee_exists[i] && !ob->query_indefinite() )
            delete_effect(i);
    }

    current_enum = -1;
    effect_unfreeze();

} /* init_after_save() */

/**
 * This method returns an array of effects matching the
 * classification.  The start part of the classification is
 * used to match, so passing "npc." into this function will
 * match all the effects which modify how an npc functions.
 * @param eff the classification to match
 * @return the array of enums corresponding to the effects
 * @see add_effect()
 */
int *effects_matching( string eff ) {
    int i, neffs, *match;
    string clas;
    object ob;

    match = ({ });
    neffs = sizeof(effs);

    for( i = 0; i < neffs; i++ ) {
        if( catch( ob = load_object(effs[i]->ob_name) ) || !ob )
            continue;

        if( !stringp( clas = (string)ob->query_classification() ) )
            continue;

        if( clas[0..strlen(eff)-1] == eff )
            match += ({ i });
    }

    return match;

} /* effects_matching() */

/**
 * This removes an effect from the player.  It uses the enum as
 * returned from sid to enum.  This is the number you see in
 * the stat of the object next to the effect.
 * @param i the enum to remove
 * @see add_effect()
 */
void delete_effect( int i ) {
    int id, j;
    object effect_object, shadow_object;
    string effect_file;
    mixed arg;

#ifdef DEBUG
    if( logging_effects )
        log_file("EFFECT_WOBBLE", "%d:%s(%d) delete_effect:(%d) "
            "sizeof(eeq)=%d\n", time() % 1000, TO->query_name(),
            current_enum, i, sizeof(eeq) );
#endif

    if( i < 0 || i >= sizeof( effs ) )
        return;

    id = shadows[i]->idnum;
    arg = effs[i]->arg;

    effect_freeze();

    for( j = 0; j < sizeof(eeq); j++ ) {
        if( eeq[j]->eff_ob_num == i ) {
            if( sizeof(eeq)-1 > j )
                eeq[j+1]->inctime += eeq[j]->inctime;
            eeq = delete( eeq, j--, 1 );
        } else {
            if( eeq[j]->eff_ob_num > i )
                eeq[j]->eff_ob_num--;
        }
    }

    effect_file = effs[i]->ob_name;
    effs = delete( effs, i, 1 );

    shadow_object = shadows[i]->shad_ob;
    shadows = delete( shadows, i, 1 );

    effect_unfreeze();

    /* Once all bookkeeping's done, it's safe to call end(), since we're
     * essentially outside the effects system.
     */
#ifdef DEBUG
    if( logging_effects )
        log_file("EFFECT_WOBBLE", "%d:%s(%d) delete_effect: before end\n",
            time() % 1000, TO->query_name(), current_enum );
#endif

    catch( effect_object = load_object(effect_file) );

    if( effect_object )
        if( pointerp(arg) && sizeof(arg) == 3 && arg[ 2 ] == BOGUS_OLD_ARG )
            effect_object->end( affected_object(), arg[1], id );
    else
        effect_object->end( affected_object(), arg, id );

#ifdef DEBUG
    if( logging_effects )
        log_file("EFFECT_WOBBLE", "%d:%s(%d) delete_effect: after end\n",
            time() % 1000, TO->query_name(), current_enum );
#endif

    // Kill the shadow if it exists.
    if( objectp(shadow_object) )
        shadow_object->remove_effect_shadow(id);

    if( !sizeof(effs) )
        TO->event_all_effects_deleted();

} /* delete_effect() */

/**
 * This method returns the effect number for the given effect id.  The
 * effect number is an internal nhandle used by delete_effect()
 * arg_of() set_arg_of() functions.  "id" is passed into the
 * begining/end etc functions on the effect object.
 * @param sid the effect id
 * @return the effect number
 * @see submit_ee2()
 * @see delete_effect()
 * @see add_effect()
 * @see arg_of()
 * @see set_arg_of()
 */
int sid_to_enum( int sid ) {
    return member_array( 1, map( shadows, (: classp($1) &&
        ((class effect_shadow)$1)->idnum == $(sid) :) ) );
} /* sid_to_enum() */

/**
 * This method turns an effect number into an effect id.
 * @see sid_to_enum()
 * @see add_effect()
 * @param enum the effect number
 * @return the effect id
 */
int enum_to_sid( int enum ) { return shadows[enum]->idnum; }

/**
 * This method returns the effect object for the given effect number.
 * @param enum the effect number
 * @return the effect object
 * @see arg_of()
 * @see add_effect()
 * @see sid_to_enum()
 */
string eff_of( int enum ) { return effs[enum]->ob_name; }

/**
 * This method returns the current arguments associated with the
 * given effect number.
 * @param enum the effect number
 * @return the arguments associated with the effect
 * @see add_effect()
 * @see set_arg_of()
 * @see sid_to_enum()
 */
mixed arg_of( int enum ) {
    mixed arg;

    if( sizeof(effs) <= enum )
        return 0;

    if( pointerp( arg = effs[enum]->arg ) && sizeof(arg) == 3 )
        if( arg[2] == BOGUS_OLD_ARG )
            return copy(arg[1]);

    return copy(arg);

} /* arg_of() */

/**
 * This sets the argument of the given effect to a new value.
 * @param enum the effect number to change
 * @param newarg the new argument value
 * @see sid_to_enum()
 * @see arg_of()
 * @see add_effect()
 */
void set_arg_of( int enum, mixed newarg ) { effs[enum]->arg = newarg; }

/** @ignore yes */
class effect *query_effs() { return effs; }
/** @ignore yes */
class effect_shadow *query_effect_shadows() { return shadows; }
/** @ignore yes */
class effect_event *query_eeq() { return eeq; }

/** @ignore yes */
void effect_timer() {
    int enum;
    object effect_object;
    mixed res, last_flags;
    class effect_event thisee;

#ifdef DEBUG
    if( logging_effects )
        log_file("EFFECT_WOBBLE", "%d:%s(%d) effect_timer:() "
            "sizeof(eeq)=%d\n", time() % 1000, TO->query_name(),
            current_enum, sizeof(eeq) );
#endif

    if( !sizeof(eeq) )
        return;

    thisee = eeq[0];
    eeq = eeq[1..];
    enum = current_enum = thisee->eff_ob_num;

    if( enum >= sizeof(effs) ) {
        effect_unfreeze();
        if( creatorp(TO) )
            tell_object( TO, "Effect number out of range, ignoring.\n");
        return;
    }

    if( thisee->flags & EE_CANCELLED ) {
        effect_unfreeze();
        return;
    }

    if( thisee->flags & EE_CONTINUOUS ) {
        last_flags = int_submit_ee( enum, thisee->func,
            thisee->interval, thisee->flags );
    }

    // Restart the timer.
    effect_unfreeze();

    catch( effect_object = load_object( effs[enum]->ob_name ) );

    if( !effect_object ) {
        if( creatorp(TO) )
            tell_object( TO, "Non-existent effect "+
                effs[enum]->ob_name+", deleting.\n");
        delete_effect(enum);
        current_enum = -1;
        return;
    }

    if( thisee->flags & EE_OLD ) {
        res = (mixed)effect_object->effect_heart_beat( TO,
            ++effs[enum]->arg[0], effs[enum]->arg[1], shadows[enum]->idnum );
        if( res == REMOVE_THIS_EFFECT )
            delete_effect(enum);
        else
            effs[enum]->arg[1] = res;
    } else {
        if( stringp(thisee->func) ) {
            res = call_other( effect_object, thisee->func, affected_object(),
                effs[enum]->arg, shadows[enum]->idnum, enum );
            if( res == REMOVE_THIS_EFFECT )
                delete_effect(enum);
            else if( res == CANCEL_THIS_EE )
                eeq[last_flags]->flags |= EE_CANCELLED;
        } else if( functionp(thisee->func) ) {
            res = evaluate( thisee->func, affected_object(), effs[enum]->arg,
                shadows[enum]->idnum, enum );
            if( res == REMOVE_THIS_EFFECT )
                delete_effect(enum);
            else if( res == CANCEL_THIS_EE )
                eeq[last_flags]->flags |= EE_CANCELLED;
        }
    }

    if( thisee->flags & EE_REMOVE )
        delete_effect(enum);

    current_enum = -1;

} /* effect_timer() */

/** @ignore yes */
mixed stats() {
    mixed ret;
    int i;
    object ob;

    ret = ({ });

    for( i = 0; i < sizeof(effs); i++ ) {
        if( catch( ob = load_object(effs[i]->ob_name ) ) || !ob ) {
            ret += ({ ({ "effect#" + i, " (buggered)"}) });
            continue;
        }

        if( intp(effs[i]->arg) || stringp(effs[i]->arg) )
            ret += ({ ({ "effect#" + i,
                effs[i]->ob_name->query_classification()+" ("+
                effs[i]->arg+")"}) });
        else
            ret += ({ ({ "effect#" + i,
                effs[i]->ob_name->query_classification()+" (complex)"}) });
    }

    return ret;

} /* stats() */

/**
 * This method removes all the effects as we die.  It calls the function
 * survive_death() on the effect objects themselves to determine if
 * they should be kept when the living dies.
 */
void effects_thru_death() {
    int i;
    object ob;

    i = sizeof( effs );

    while( i-- ) {
        if( catch( ob = load_object(effs[i]->ob_name) ) || !ob ||
            !ob->survive_death() )
            delete_effect(i);
    }

} /* effects_thru_death() */

/**
 * This method returns the current enum.
 * @return the current enum
 */
int query_current_effect_enum() { return current_enum; }

/**
 * This method is used to force the effects setup in the object to be a
 * specified value.  This is used in the effects effect which sets up
 * effects on someone using a shadow.  This should only be used on startup.
 * @param args the effects array to overwrite the old one with
 */
protected void set_effs( mixed args ) {
    int i, neffs;

    if( sizeof( args ) && !classp( args[ 0 ] ) ) {
        effs = allocate( neffs = sizeof( args ) / EFF_SIZE );
        for( i = 0; i < neffs; i++ )
            effs[ i ] = new( class effect,
                        ob_name : args[ i * EFF_SIZE + EFF_OB_NAME ],
                        arg     : args[ i * EFF_SIZE + EFF_ARG ] );
    } else {
        effs = args;
    }

} /* set_effs() */

/**
 * This method is used to force the effects setup in the object to be a
 * specified value.  This is used in the effects effect which sets up
 * effects on someone using a shadow.  This should only be used on startup.
 * @param args the effects array to overwrite the old one with
 */
protected void set_eeq( mixed args ) {
    int i, neeq;

    if( sizeof( args ) && !classp( args[ 0 ] ) ) {
        eeq = allocate( neeq = sizeof( args ) / EEQ_SIZE );
        for( i = 0; i < neeq; i++ )
            eeq[ i ] = new( class effect_event,
                       inctime    : args[ i * EEQ_SIZE + EEQ_INCTIME ],
                       func       : args[ i * EEQ_SIZE + EEQ_FUNC ],
                       eff_ob_num : args[ i * EEQ_SIZE + EEQ_EFF_OB ],
                       interval   : args[ i * EEQ_SIZE + EEQ_INTERVAL ],
                       flags      : args[ i * EEQ_SIZE + EEQ_FLAGS ] );
    } else {
        eeq = args;
    }

} /* set_eeq() */
