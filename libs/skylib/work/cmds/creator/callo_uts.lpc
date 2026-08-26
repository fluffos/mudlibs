/**
 * Callouts command by Someone.
 * @changed Changed to use wiz-present and cleaned up a little.
 * - Sandoz, April 2003.
 */

#include <creator.h>

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( object *obs, int flag ) {
    string ret, str;
    mapping count;
    mixed junk;
    int i;

    if( sizeof( junk = call_out_info() ) < 1000 )
        junk = sort_array( junk, (: ( $1[ 2 ] > $2[ 2 ] ) -
                                    ( $1[ 2 ] < $2[ 2 ] ) :) );

    if( pointerp(obs) ) {
        if( sizeof(obs) > 1 ) {
            add_failed_mess("You can only find callouts in one "
                "object at a time.\n");
            return 0;
        }

        if( !sizeof( junk = filter( junk, (: $1[0] == $(obs[0]) :) ) ) ) {
            add_failed_mess("There are no active callouts in "+
                WIZ_PRESENT->desc_f_object( obs[0] )+".\n");
            return 0;
        }

        str = file_name( obs[0] );
    }

    ret = "";

    if( flag ) {
        count = ([ ]);

        for( i = 0; i < sizeof(junk); i++ )
            count[base_name(junk[i][0]) + ":" + junk[i][1]]++;

        foreach( string item in keys(count) )
            ret += sprintf("%-30s %d\n", item, count[item] );

    } else {
        if( str ) {
            for( i = 0; i < sizeof(junk); i++ ) {
                if( sscanf( file_name( junk[ i ][ 0 ] ),
                    "%*s"+str+"%*s" ) == 2 )
                    ret += sprintf("%O: %O in %O\n", junk[ i ][ 0 ],
                                     junk[ i ][ 1 ], junk[ i ][ 2 ] );
            }
        } else {
            for( i = 0; i < sizeof(junk); i++ )
                ret += sprintf("%O: %O in %O\n", junk[ i ][ 0 ],
                                 junk[ i ][ 1 ], junk[ i ][ 2 ] );
        }
    }

    TP->more_string( ret, "Callouts");
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "", (: cmd( 0, 0 ) :),
        "count", (: cmd( 0, 1 ) :),
        "<indirect:wiz-present>", (: cmd( $1, 0 ) :),
        "count <indirect:wiz-present>", (: cmd( $1, 1 ) :),
    });
} /* query_patterns() */
