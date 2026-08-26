
inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string str, int verbose )  {
    string mud;

    if( creatorp(TP) && str && sscanf( str, "@%s", mud ) == 1 ) {
        if( !INTERMUD_H->who(mud) ) {
            add_failed_mess("There is no such mud on the mudlist.\n");
            return 0;
        }
        tell_object( TP, "Intermud who requested from "+
            INTERMUD_H->mud_exists(mud)+".\n");
        return 1;
    }

    TP->more_string( WHO_H->who_string( TP->query_cols(), creatorp(TP),
                     verbose, str ), "Who", 1 );
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({ "", (: cmd( 0, 1 ) :),
        "brief", (: cmd( 0, 0 ) :),
        "players", (: cmd("players", 1, ) :),
        "creators", (: cmd("creators", 0 ) :),
        "helpers", (: cmd("helpers", 0 ) :),
        "killers", (: cmd("killers", 0 ) :),
        "playtesters", (: cmd("playtesters", 0 ) :),
        "families", (: cmd("families", 0 ) :),
        "friends", (: cmd("friends", 0 ) :),
        "<string'domain'>", (: cmd( $4[0], 0 ) :),
        "<string'project'>", (: cmd( $4[0], 0 ) :),
        });
} /* query_patterns() */
