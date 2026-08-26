/**
 * This command lists all the rituals the player has.
 */

#include <spells.h>
#include <deity.h>

inherit COMMAND_BASE;

int cmd( int playtester ) {
    string *religious;
    mapping spells;

    if( playtester ) {
        if( !playtesterp(TP) )
            return 0;

        if( !sizeof( religious = ( PT_RITUALS - RITUALS ) ) ) {
            add_failed_mess("There are no rituals currently in "
                "playtesting.\n");
            return 0;
        }

        religious = map( religious, (: $1->query_name() :) );
        write("The religious ritual"+
             ( sizeof( religious ) == 1 ? "" : "s" ) +" currently in "
             "playtesting are:\n");

    } else {
        if( !sizeof( spells = TP->query_spells() ) ) {
            add_failed_mess("You don't know any religious rituals.\n");
            return 0;
        }

        spells = filter( spells, (: sscanf( $2[0], "%*spriest%*s" ) == 2 ||
                                    sscanf( $2[0], "%*sritual%*s" ) == 2 :) );

        if( !sizeof( spells ) ) {
            add_failed_mess("You don't know any religious rituals.\n");
            return 0;
        }

        religious = keys(spells);
        write("You know the following religious ritual"+
             ( sizeof( religious ) == 1 ? "" : "s" ) +":\n");

    }

    printf("%#-*s\n", (int)TP->query_cols(),
         implode( sort_array( religious, 1 ), "\n") );

    return 1;

} /* cmd() */

mixed query_patterns() {
    return ({ "", (: cmd(0) :) }) +
           ( !playtesterp(TP) ? ({ }) : ({ "playtester", (: cmd(1) :) }) );
} /* query_patterns() */
