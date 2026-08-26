/* mailinfo command, trial out by Turrican for a commands daemon. */

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string str ) {
    if( !str || str == "") {
        write("You have "+
            lower_case( MAIL_H->finger_mail( TP->query_name() ) ) );
        return 1;
    }

    str = TP->expand_nickname(str);

    if( !PLAYER_H->test_user(str) ) {
        write("Sorry, but "+CAP(str)+" isn't a player.\n");
        return 1;
    }

    write( CAP(str)+" has "+lower_case( MAIL_H->finger_mail(str) ) );
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "", (: cmd(0) :),
        "<word'player'>", (: cmd($4[0]) :),
    });
} /* query_patterns() */
