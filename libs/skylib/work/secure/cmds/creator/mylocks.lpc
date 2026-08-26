#include <creator.h>

inherit COMMAND_BASE;

int cmd(string person)  {
    string *locked;
    string who_string;

    if ( person ) {
        who_string = capitalize( person ) + " has ";
        locked = RCS_HANDLER->query_locks( person );
    }
    else {
        who_string = "You have";
        locked = RCS_HANDLER->query_locks( this_player() );
    }

    if ( !sizeof( locked ) ) {
        add_failed_mess( who_string + " no files locked.\n" );
        return -1;
    }

    locked = sort_array( locked, 1 );

    write( who_string + " the following files locked:\n" +
      implode(locked, "\n") + "\n");
    return 1;
} /* cmd() */

mixed *query_patterns() {
    return ({ "", (: cmd(0) :),
      "<string'creator'>", (: cmd($4[0] ) :) });
} /* query_patterns() */
