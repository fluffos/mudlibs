
inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string who )  {
    object player;
    int last;

    who = lower_case(who);

    if( who == TP->query_name() ) {
        write("You are currently logged on, but you already know that.\n");
        return 1;
    }

    who = TP->expand_nickname( who );
    player = find_player( who );

    if( player ) {
        write( CAP(who)+" is currently "+( interactive(player) ?
            "logged on" : "net-dead")+".\n");
        return 1;
    }

    last = PLAYER_H->test_last( who );

    if( last < 1 ) {
        add_failed_mess( CAP(who)+" doesn't appear to have a character on "+
            mud_name()+".\n");
        return 0;
    }

    write( CAP(who)+" last logged on "+time_string( time() - last )+" ago.\n");
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns()  {
    return ({"<string'player name'>", (: cmd( $4[0] ) :) });
} /* query_patterns() */
