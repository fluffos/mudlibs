/**
 * Funky little command to let players silently set their position,
 * with the aim of encouraging players to improve their health and
 * well-being by experimenting with new and exciting positions.
 *
 * @author Mansarde
 * @started 9-apr-99
 * @changed Changed to display the full position string -
 * "You are sitting on a leather couch." vs the old "Sandoz is sitting."
 *- Sandoz, 2nd Oct. 2002.
 */

#include <player.h>

// Max length of a position
#define MAXLEN 80

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string new_pos ) {
    if( !new_pos ) {
        tell_object( TP, "You are "+TP->query_position_short()+".\n");
        return 1;
    }

    if( sizeof(new_pos) > MAXLEN ) {
        tell_object( TP, "Sorry, your position cannot be more than "+
            MAXLEN+" characters long.\n");
        return 1;
    }

    if( TP->query_sp() < SET_POSITION_COST ) {
        tell_object( TP, NO_POWER );
        return 1;
    }

    new_pos = replace_string( replace_string( new_pos, "^", ""), "%", "");

    TP->set_position( new_pos );
    TP->adjust_sp( -SET_POSITION_COST );

    tell_object( TP, "People will now see:\n"+
        TP->short()+" is "+TP->query_position_short()+".\n");

    return 1;

} /* cmd */

/** @ignore yes */
mixed query_patterns() {
  return ({"", (: cmd(0) :),
           "<string'new position'>", (: cmd( $4[0] ) :) });
} /* query_patterns */
