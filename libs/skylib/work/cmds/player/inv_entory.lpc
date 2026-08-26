/**
 * @changed Added playtester stuff - Sandoz, Sept. 2002.
 */

#define CM(x)  TP->convert_message(x)
#define QMS(x) query_multiple_short( x, "a")

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( int pt ) {
    object *obs;

    if( TP->query_property( "dead" ) ) {
        write("You are just a disembodied spirit.  "
              "You have mist; what else do you want?\n");

        obs = filter( INV(TP), (: $1->query_property("dead usable") :) );
        if( sizeof(obs) )
            write("Hang on!  You appear to have "+
                query_multiple_short(obs)+".  Amazing.\n");

        return 1;

    }

    if( pt ) {
        mapping map;
        object *keys;
        int i, cols;
        string ret;

        if( !playtesterp(TP) ) {
            add_failed_mess("You are not a playtester!\n");
            return 0;
        }

        obs = filter( deep_inventory(TP),
            (: $1->effects_matching("mudlib.pt.item") :) );

        if( !sizeof(obs) ) {
            write("You have no playtester items.\n");
            return 1;
        }

        map = unique_mapping( obs, (: ENV($1) :) );
        cols = TP->query_cols();
        ret = "";

        if( !undefinedp(map[TP]) ) {
            ret += indent("    Your inventory: "+CM( QMS( map[TP] ) ),
                4, cols )[8..]+".\n";
            map_delete( map, TP );
        }

        i = sizeof( keys = keys( map ) );

        while( i-- )
            ret += "$C$"+indent("    "+CM( inside_one_short( keys[i] ) )+": "+
                CM( QMS( map[keys[i]] ) ), 4, cols )[8..]+".\n";

        write( ret );

        return 1;

    }

    write( TP->query_living_contents( 1 ) );

    if( TP->query_auto_loading() )
        write("\n%^YELLOW%^Please note that your inventory is still being "
            "generated.%^RESET%^\n");

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    if( playtesterp(TP) )
        return ({"", (: cmd( 0 ) :), "playtester", (: cmd( 1 ) :) });
    return ({"", (: cmd( 0 ) :) });
} /* query_patterns() */
