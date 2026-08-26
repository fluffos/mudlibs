
inherit COMMAND_BASE;

int cmd( string mess ) {
    if( BULK_DELETE_H->delete_files(mess) ) {
        write("Ok.\n");
        return 1;
    }

    return notify_fail("Sorry.\n");

} /* cmd() */
