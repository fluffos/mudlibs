
inherit COMMAND_BASE;

/** @ignore yes */
private string get_last_log( int last_log_on ) {
    string retval;
    int tmp_time, sec, min, hour, day;

    // Should be a nice number.
    tmp_time = time() - last_log_on;
    if( !tmp_time )
        sec = min = hour = day = 0;

    if( tmp_time > 24*60*60 ) {
        retval = ( day = tmp_time / (24*60*60) )+" day"+( day < 2 ? "" :
                   "s")+" ago.";
        if( day > 14 )
            retval = "%^RED%^"+retval+"%^RESET%^";
        else if( day > 7 )
            retval = "%^YELLOW%^"+retval+"%^RESET%^";
        else
            retval = "%^GREEN%^"+retval+"%^RESET%^";
    } else
        retval = "%^GREEN%^Today%^RESET%^";

    return retval;

} /* get_last_log() */

/** @ignore yes */
private int dinfo( string name, int option ) {
    string ret, *members;
    int cols;

    if( !DOMAIN_H->query_domain(name) )
        return notify_fail("No such domain: "+name+"\n");

    cols = (int)TP->query_cols();
    members = DOMAIN_H->query_members(name);

    members = ( option ? sort_array( members, (: PLAYER_H->test_last($2) -
        PLAYER_H->test_last($1) :) ) : sort_array( members, 1 ) );

    ret = "The current members of "+CAP(name)+" are:\n";

    foreach( name in members )
        ret += sprintf("%-12s: Last login: %s\n",
               CAP(name), find_player(name)? "%^GREEN%^%^BOLD%^Now%^RESET%^" :
               get_last_log( PLAYER_H->test_last(name) ) );

    TP->more_string( ret, "Domain Info");
    return 1;

} /* dinfo() */

/** @ignore yes */
mixed query_patterns() {
  return ({ "<string'domain'>", (: dinfo( $4[0], 0 ) :),
            "<string'domain'> [by] login", (: dinfo( $4[0], 1 ) :),
         });
} /* query_patterns() */
