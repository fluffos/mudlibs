/**
 * dnickname command by Turrican for the commands daemon.
 */

inherit COMMAND_BASE;

int cmd( string str ) {
    mapping map_nicknames;

    if( !mapp( map_nicknames = TP->query_nicknames() ) )
        map_nicknames = ([ ]);

    if( !map_nicknames[str] ) {
        add_failed_mess("That nickname does not exist.\n");
        return 0;
    }

    map_delete( map_nicknames, str );
    TP->set_nicknames(map_nicknames);

    write("Deleted nickname : "+str+"\n");
    return 1;

} /* cmd() */
