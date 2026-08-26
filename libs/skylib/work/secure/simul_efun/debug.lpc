/**
 * Debugging simul efuns.
 * @author Ceres
 */

/**
 * This method will generate a debug inform for any creators in the room
 * where it is generated.  It will always attempt to identify the room
 * that the event should be sent to.
 *
 * @example
 * #ifdef DEBUG
 *   debug_printf("Error, player is: %O\n", player);
 * #endif
 *
 * @param all printf style parameters
 * @see printf
 */
void debug_printf( string fmt, mixed args ...) {
    object env;

    env = PO;
    if( env )
        while( ENV(env) )
            env = ENV(env);

    if( ( !env || !env->query_is_room() ) && TP )
        env = ENV(TP);

    if( env ) {
#if efun_defined(event)
        event( env, "inform", sprintf("%O:\n " + fmt, PO, args ... ),
            "debug");
#else
        TO->event( env, "inform", sprintf("%O:\n "+fmt, PO, args ... ),
            "debug");
#endif
    }
} /* debug_printf() */

/**
 * This method writes a message to a creator, it's mainly meant
 * for debug messages where sending a message to a specific
 * creator is smarter than sending it to players, who will only get confused.
 * Typically you should use debug_printf() instead of this.
 * @param cre the name or object to send the message to
 * @param fmt the format string
 * @param args the arguments to the sprintf
 * @see debug_printf
 */
varargs void tell_creator( mixed cre, string fmt, mixed args ... ) {
    if( stringp(cre) ) {
#if efun_defined(find_player)
        cre = efun::find_player(cre);
#else
        cre = "/handlers/livings"->find_player(cre);
#endif
    }

    if( objectp(cre) && TO->creatorp(cre) ) {
        if( sizeof(args) )
            fmt = sprintf( fmt, args... );
        TO->tell_object( cre, fmt+"\n");
    }

} /* tell_creator() */
