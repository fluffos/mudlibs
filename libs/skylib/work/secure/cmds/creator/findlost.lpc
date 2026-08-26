
inherit COMMAND_BASE;

int cmd( string str ) {
    string info;
    object *obs;
    int i;

    obs = filter( objects(), (: "/handlers/garbage"->get_junk($1) :) );

    if( !sizeof(obs) ) {
        write("There are no lost objects.\n");
        return 1;
    }

    info = implode( map( obs,
        (: sprintf("  %O : %O\n", $1, ENV($1) ) :) ), "\n");
    info += "\nA total of "+( i = sizeof(obs) )+" object"+
        ( i > 1 ? "s" : "")+".\n";

    TP->more_string("%^CYAN%^Pending objects to be purged in "
                    "routine cleanup.%^RESET%^\n" + info );
    return 1;

} /* cmd() */
