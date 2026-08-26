
inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string str ) {
    string name;

    if( TP->query_auto_loading() ) {
        write("You cannot switch to another character yet: your inventory is "
            "still being generated.\n");
        return 1;
    }

    if( SHUTDOWN_H->query_shutdown() < 10 ) {
        write("You cannot switch to another character so close to a "
            "reboot.\n");
        return 1;
    }

    if( sizeof( TP->query_attacker_list() ) ) {
        write("You cannot switch to another character while in combat.\n");
        return 1;
    }

    if( ( str = lower_case(str) )[0] == '#' || str[0] == '@' )
        name = str[1..];
    else
        name = str;

    if( !PLAYER_H->test_user( name ) ) {
        write("You cannot switch to "+CAP(str)+" because a character by that "
            "name doesn't exist.\n");
        return 1;
    }

    clone_object( LOGIN_OBJ )->do_su(str);

    return 1;

} /* do_su() */

/** @ignore yes */
mixed query_patterns() {
    return ({"[to] <word'character'>", (: cmd( $4[0] ) :) });
} /* query_patterns() */
