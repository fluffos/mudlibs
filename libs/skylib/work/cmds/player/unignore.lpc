inherit COMMAND_BASE;

string *do_clean( string *people ) {
    return filter( people, (: ( find_player($1) || rank($1) ) &&
                                !creatorp($1) :) );
} /* do_clean() */

int cmd( string str ) {
    string *ignoring;
    int i;

    if( !ignoring = TP->query_property("ignoring") )
        ignoring = ({ });

    if( !sizeof( ignoring = do_clean( ignoring ) ) ) {
        TP->remove_property("ignoring");
        write("You are not ignoring anyone.\n");
        return 1;
    }

    if( !str ) {
        add_failed_mess("Unignore who?\n");
        return 0;
    }

    str = TP->expand_nickname(str);

    if( str == "all" ) {
        TP->remove_property("ignoring");
        write("You are no longer ignoring anyone.\n");
        return 1;
    }

    if( ( i = member_array( str, ignoring ) ) == -1 ) {
        write("You are not ignoring "+str+".\n");
        return 1;
    }

    ignoring = delete( ignoring, i, 1 );

    if( !sizeof(ignoring) )
        TP->remove_property("ignoring");
    else
        TP->add_property("ignoring", ignoring );

    write(str+" has been removed from your list of ignored players.\n");
    return 1;

} /* cmd() */

mixed query_patterns() {
   return ({ "<string'person'>", (: cmd($4[0]) :),
             "all", (: cmd("all") :) });
} /* query_patterns() */
