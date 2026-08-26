/**
 * This is the finderrors command.
 * It handles bugreports in a collection of dirs for a creator.
 */

inherit "/secure/cmds/creator/errors";

#define HELPER "/handlers/finderror_helper"

/** @ignore yes */
int do_list() {
    string *arr;

    if( sizeof( arr = HELPER->query_dirs( TP->query_name() ) ) ) {
        TP->more_string( sprintf("Error reports will be checked in the "
            "following dirs:\n%s\n", implode( sort_array( arr, 1 ), "\n") ) );
    } else {
        write("You haven't added any directories yet.\n");
    }

    return 1;

} /* do_list() */

/** @ignore yes */
int do_count() {
    string *arr;

    if( sizeof( arr = HELPER->query_dirs_count( TP->query_name() ) ) ) {
        TP->more_string( sprintf("Error reports are in the following dir(s):\n%s\n",
            implode( sort_array( arr, 1 ), "\n") ) );
    } else {
        write("No directories with errors.\n");
    }

    return 1;

} /* do_count() */

/** @ignore yes */
int do_print() {
    string *arr;

    if( sizeof( arr = HELPER->query_dirs( TP->query_name() ) ) ) {
        "/secure/cmds/creator/printe_rrors"->start_collect( TP, arr, 0 );
    } else {
        write("You haven't added any directories yet.\n");
    }

    return 1;

} /* do_print() */

/** @ignore yes */
int do_add( string str ) {
    int ret, recursive;

    if( str[0] != '/')
        str = TP->query_current_path()+"/"+str;

    if( str[<1] == '0')
        str = str[0..<2];

    if( str[<1] == '*') {
        str = str[0..<2];
        recursive = 1;
    }

    if( str[<1] != '/')
        str += "/";

    if( file_size(str) != -2 )
        return notify_fail( str+" is not an existing directory.\n");

    ret = HELPER->add_dir( TP->query_name(), str, recursive );

    if( recursive ) {
        if( ret < 0) {
            printf("%s added, the subdirectories are being added, "
                   "this may take a while.\n", str );
        } else {
            printf("%s was already in the list, the subdirectories are being "
                   "checked for newcomers.\n", str );
        }
    } else {
        if( ret < 0 ) {
            printf("%s added.\n", str );
        } else {
            printf("%s was already in the list, but that's ok.\n", str );
        }
    }

    return 1;

} /* do_add() */

/** @ignore yes */
int do_remove( string str ) {
    int ret, recursive;

    if( str[0] != '/')
        str = TP->query_current_path()+"/"+str;

    if( str[<1] == '0')
        str = str[0..<2];

    if( str[<1] == '*') {
        str = str[0..<2];
        recursive = 1;
    }

    if( str[<1] != '/')
        str += "/";

    ret = HELPER->remove_dir( TP->query_name(), str, recursive );

    if( ret != -1 ) {
        printf("%s removed.\n", str );
    } else {
        printf("%s was not in the list.\n", str );
    }

    return 1;

} /* do_remove() */

/** @ignore yes */
int cmd( string str ) {
    str = HELPER->get_next_dir( TP->query_name() );

    if( !str )
        return notify_fail("No error reports found.\n");

    printf("Checking errors in %s\n", str );
    return ::cmd(str);

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "list", (: do_list() :),
        "count", (: do_count() :),
        "print", (: do_print() :),
        "add <string'path'>", (: do_add($4[0]) :),
        "remove <string'path'>", (: do_remove($4[0]) :),
        "", (: cmd(0) :),
    });
} /* query_patterns() */
