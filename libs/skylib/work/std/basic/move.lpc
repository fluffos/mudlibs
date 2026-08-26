/**
 * This class defines the basic move function and support functions.
 * @author Pinkfish
 */
#include <move_failures.h>

#define DROP 1
#define GET 2

private int move_flag;

/**
 * The basic move method.  The destination can be an object or a string.
 * if it is neither of these then the failure MOVE_EMPTY_DEST is
 * returned.  If the function test_add() was called on the
 * destination and it returns 0 then MOVE_NO_GET is returned as
 * a failure.  If the destination is TO then
 * MOVE_INVALID_DEST is returned as the failure.  If the
 * function test_remove is called on the current environment and it
 * returns 0 then MOVE_NO_DROP is returned as the move failure.
 * <p>
 * The events "enter" and "exit" are generated as part of the
 * move process.  Both of these events are passed two
 * arguments.  The exit event is passed the exit message
 * and the destination.  The enter event is passed the
 * enter message and the place we came from.
 * <p>
 * The function event_move_object() is called (call_other)
 * on the object if the move was successful (MOVE_OK).
 * @param dest where to move to
 * @param messin the message to print when entering
 * @param messout the message to print when leaving
 * @see /include/move_failures.h
 * @return MOVE_OK on success, or a failure reason on failure
 * @see /secure/simul_efun->event()
 * @see event_move_object()
 * @example
 * move(find_player("pinkfish"));
 * @example
 * move("/d/am/am/mendeddrum");
 * @example
 * move (environment(find_player("ceres")),
 *          the_short()+" flaps in hopelessly.\n",
 *          the_short()+" flaps away hopelessly.\n");
 */
varargs int move( mixed dest, string messin, string messout ) {
    object env;

    if( !objectp( dest ) ) {
        if( !stringp( dest ) || !( dest = find_object( dest ) ) )
            return MOVE_EMPTY_DEST;
    }

    if( !dest->test_add( TO, TO->get(dest) ) )
        return MOVE_NO_GET;

    if( dest == TO )
        return MOVE_INVALID_DEST;

    if( env = environment() ) {
        if( !env->test_remove( TO, TO->drop(dest), dest ) )
            return MOVE_NO_DROP;
        event( env, "exit", messout, dest );
    }

    if( dest != env ) {
        move_object(dest);
        TO->event_move_object( env, dest );
    }

    if( !dest->no_event_enter() )
        event( dest, "enter", messin, env );

    TO->remove_hide_invis("concealed");
    TO->remove_hide_invis("secreted");

    return MOVE_OK;

} /* move() */

/**
 * Turns off the get flag.
 * @see move()
 * @see set_get()
 * @see get()
 */
void reset_get() { move_flag |= GET; }

/**
 * Turns on the get flag.
 * @see move()
 * @see reset_get()
 * @see get()
 */
void set_get() { move_flag &= ~GET; }

/**
 * Turns off the drop flag.
 * @see move()
 * @see set_drop()
 * @see drop()
 */
void reset_drop() { move_flag |= DROP; }

/**
 * Turns on the drop flag.
 * @see move()
 * @see reset_drop()
 * @see drop()
 */
void set_drop() { move_flag &= ~DROP; }

/**
 * This method destructs the object.  Zap us totally!  It generates
 * the event "dest_me", which is passed no arguments.
 * The function event_destruct() is called (call_other) on
 * the object for special last minute actions however
 * the destruct will not prevented.  If you need to prevent
 * the destruction mask dest_me() or do_death().
 * @see efun::destruct()
 * @see event_dest_me()
 * @see event_destruct()
 * @see do_death()
 * @see dwep()
 * @see /secure/simul_efun->event()
 */
void dest_me() {
    object env;

    if( env = environment() )
        event( env, "dest_me");

    TO->event_destruct();
    efun::destruct(TO);

} /* dest_me() */

/* Do not, I repeat, do not mask this function.
 * It is used when all else fails to destruct the object...
 * If we find you masking this function, we will cut you up
 * into many little bits... slowly.
 */

/**
 * Dest with extreme predejuce.  This is the last way to destruct an
 * object.  Used if all other methods fail.
 * @return a string "Destructed With Extreme Prejudice"
 */
nomask string dwep() {
    efun::destruct(TO);
    return "Destructed With Extreme Prejudice";
} /* dwep() */

/**
 * The current value of the drop flag. This function is called by the
 * test_remove() function in the living object.  So it allows you to
 * move the object out of inanimate objects, just not out of the
 * players.
 * @return 1 if it is set, 0 if it is reset
 * @see set_drop()
 * @see reset_drop()
 * @see get()
 */
int drop( mixed dest ) { return move_flag & DROP; }

/**
 * The current value of the get flag.  This function is called by the
 * test_add() function in the living object.  So it allows you to
 * move the object into innimate objects, just not into player
 * characters.
 * @return 1 if it is set, 0 if it is reset
 * @see set_get()
 * @see reset_get()
 * @see drop()
 */
int get( mixed dest ) { return move_flag & GET; }

/** @ignore yes  This is a debugging call. */
void set_move_flag( int i ) { move_flag = i; }
