/**
 * ScreenWrite Command.
 * Used to send blocks to text to other creators, in a more
 * readable fashion.
 * Written by Terano, on 14th September, 1998
 * @changed Sandoz, 2002.
 * Fixed an error with targets logging off mid-screen.
 * Fixed runtimes in screen_toggle.
 * Removed the target variable and made input_to to pass it to
 * the callback function instead, so the target won't get mixed
 * up when multiple people are trying to screen. *urgh*
 */

inherit COMMAND_BASE;

/** @ignore yes */
private void do_screen( string spam, object player ) {
    if( !player ) {
        write("Oops, the person you were screening to seems to have logged "
            "off.\n");
        return;
    }

    if( spam == "**" ) {
        tell_object( player, "Stopped receiving text from "+
            TP->the_short()+".\n");
        tell_object( TP, "Stopped sending text to "+
            player->the_short()+".\n");
        return;
    }

    if( spam ) {
        tell_creator( player, "] " + spam );
        write("] ");
    }

    input_to( (: do_screen :), player );

} /* do_screen() */

/** @ignore yes */
private int cmd( object player ) {

    if( player == TP ) {
        add_failed_mess("You start to send text to yourself, but think "
            "better of it.\n");
        return 0;
    }

    if( !creatorp(player) ) {
        add_failed_mess("Sorry, you can only screen text to creators.\n");
        return 0;
    }

    if( player->check_earmuffs("remote-spam") ) {
        tell_object( player, TP->the_short()+" tried to screen some text to "
            "you.\n");
        add_failed_mess("$I currently has "+player->HIS+" screen earmuffs "
            "on, ask "+player->HIM+" to turn them off first.\n",
            ({ player }) );
        return 0;
    }

    tell_object( player, "Receiving text from "+TP->the_short()+".\n");
    tell_object( TP, "Sending text to "+player->the_short()+".  "
        "Use ** to stop.\n] ");

    input_to( (: do_screen :), player );
    return 1;

} /* cmd() */

/** @ignore yes */
private int screen_toggle( string toggle ) {
    string *earmuffs;

    earmuffs = TP->query_property("earmuffs") || ({ });

    if( toggle == "off") {
        if( member_array("remote-spam", earmuffs ) == -1 ) {
            add_failed_mess("You aren't earmuffing remote-spam events!\n");
            return 0;
        }

        if( sizeof( earmuffs -= ({"remote-spam"}) ) )
            TP->add_property("earmuffs", earmuffs );
        else
            TP->remove_property("earmuffs");
        write("You turn the remote-spam earmuffs off.\n");
        return 1;

    }

    if( toggle == "on") {
        if( member_array("remote-spam", earmuffs ) != -1 ) {
            add_failed_mess("You are already earmuffing remote-spam "
                "events!\n");
            return 0;
        }

        TP->add_property("earmuffs", earmuffs += ({ "remote-spam" }) );

        write("You turn on your remote-spam earmuffs.\n");

        if( !TP->query_earmuffs() )
            write("Remeber to \"earmuff on\" to enable them.\n");

        return 1;

    }

} /* screen_toggle() */

/** @ignore yes */
mixed query_patterns() {
    return ({"<indirect:player>", (: cmd( $1[0] ) :),
             "{on|off}", (: screen_toggle( $4[0] ) :) });
} /* query_patterns() */
