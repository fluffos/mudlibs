
inherit COMMAND_BASE;

/** @ignore yes */
int command_history( string arg ) {
    return TP->print_history(arg);
} /* command_history() */

/** @ignore yes */
int channel_history( string arg ) {
    if( !TP->query_channels() ) {
        add_failed_mess("You don't appear to have any channels.  "
            "Please try again in a moment if you just logged on.\n");
        return 0;
    }

    if( member_array( arg, TP->query_channels() ) != -1 ) {
        if( HISTORY_H->query_chat_history(arg) ) {
            if( TP->query_in_jail() ) {
                add_failed_mess("You are in jail, channel history is out of "
                    "your reach.\n");
                return 0;
            }

            return CHANNEL_H->query_history(arg);
        }
    }

    add_failed_mess("There is no "+arg+" history.\n");
    return 0;

} /* channel_history() */

/** @ignore yes */
int tell_history( string arg, int brief ) {
    return evaluate( TP->get_htell_func(), arg, brief );
} /* tell_history() */

/** @ignore yes */
int say_history( string arg, int brief ) {
    return evaluate( TP->get_hsay_func(), arg, brief );
} /* say_history() */

/** @ignore yes */
mixed query_patterns()  {
    return ({
        "tell brief search <string'name'>",
            (: tell_history( lower_case($4[0]), 1 ) :),
        "tell search <string'name'>", (: tell_history( lower_case($4[0]),
            !TP->query_verbose("htell") ) :),
        "tell brief", (: tell_history("", 1 ) :),
        "tell verbose", (: tell_history("", 0 ) :),
        "tell", (: tell_history("", !TP->query_verbose("htell") ) :),
        "say brief search <string'name'>",
            (: say_history(lower_case($4[0]), 1 ) :),
        "say search <string'name'>",
            (: say_history( lower_case($4[0]), !TP->query_verbose("hsay") ) :),
        "say brief", (: say_history("", 1 ) :),
        "say verbose", (: say_history("", 0 ) :),
        "say", (: say_history("", !TP->query_verbose("hsay") ) :),
        "command <string>", (: command_history( $4[0] ) :),
        "command", (: command_history("") :),
        "<string'channel name'>",(: channel_history($4[0]) :),
    });
} /* query_patterns() */
