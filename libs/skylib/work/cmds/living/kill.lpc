/**
 * Moved all the checks to the health handler so it
 * could be used elsewhere as well.
 * - Sandoz, 2002.
 */

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( object *things ) {

    things = HEALTH_H->do_attack_checks( things, 1 );

    // Assume a message has been given already.
    if( !things )
        return 0;

    if( sizeof( things ) )
        write("You prepare to attack "+query_multiple_short( things )+".\n");

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({ "<indirect:living:here>", (: cmd($1) :) });
} /* query_patterns() */
