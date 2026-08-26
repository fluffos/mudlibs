/**
 * This file contains all the information related creator commands.
 * @author Ember
 */

#define PEOPLER "/handlers/peopler"

protected int do_gauge( string str );
private int start_gauge( string str );
int add_command( string name, object ob, string format, function func );

/** @ignore yes */
protected void wiz_commands() {
    add_command("gauge", TO, "<string'command'>", (: do_gauge($4[0]) :) );
    if( clonep() )
        call_out("driver_version", 20 );
} /* wiz_commands() */

/* small addition by a retired creator aka wonda */
/**
 * This method is called slighty after the login time.
 * It checks to see if the driver version has changed and
 * notifies the creator.
 */
int driver_version() {
    string old = TO->query_property("driver_version");

    if( !old )
        return TO->add_property("driver_version", __VERSION__ );

    if( old != __VERSION__ ) {
        TO->add_property("driver_version", __VERSION__);
        write("%^RED%^The driver has been changed to version "+
            __VERSION__+".%^RESET%^\n");
    }

    return 1;

} /* driver_version() */

/** @ignore yes */
int review() {
    PEOPLER->review();
    return 1;
} /* review() */

/**
 * This method returns the number of evaluation cycles the
 * particular command took to run.  It is kind of useful for
 * figuring out how much time a given command takes
 * to execute
 * @param str the command to execute
 * @return 1 on success, 0 on failure
 */
protected int do_gauge( string str ) {
    if( this_player(1) != TO )
        return 0;

    // Use a callout to cut the call stack.
    call_out( (: start_gauge :), 0, str );
    return 1;

} /* do_gauge() */

private int start_gauge( string str ) {
    int time, eval;

    time = time_expression( eval = command(str) );

    tell_object( TO, sprintf("\nThe command '%s' took %i (%i) CPU cycles to "
        "complete.\n", str, time, eval ) );

} /* start_gauge() */
