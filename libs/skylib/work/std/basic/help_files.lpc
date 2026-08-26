/**
 * This inheritable allows objects or rooms to have help attached to them.
 * @author Pinkfish
 */
#include <room.h>
#include <nroff.h>

mixed query_property( string name );
void add_property( string name, mixed value );

/**
 * This method sets up the help for the room.  All the help file names are
 * relative to /doc/room unless a complete path is specified.
 * @param help_file the help file name
 */
void add_help_file( string help_file ) {
    string *help;

    if( help = query_property(ROOM_HELP_FILE_PROPERTY) ) {
        if( member_array( help_file, help ) == -1 )
            help += ({ help_file });
    } else {
        help = ({ help_file });
    }

    add_property(ROOM_HELP_FILE_PROPERTY, help );

} /* add_help_file() */

/**
 * This method removes the specified help file from the current ones.
 * @param help_file the help file name to remove
 */
void remove_help_file( string help_file ) {
    string* help;

    if( help = query_property(ROOM_HELP_FILE_PROPERTY) ) {
        help -= ({ help_file });
        add_property(ROOM_HELP_FILE_PROPERTY, help );
    }
} /* remove_help_file() */

/**
 * This method returns the help files for the current room.
 * @return the array of help files
 */
string *query_help_files() {
   return query_property(ROOM_HELP_FILE_PROPERTY);
} /* query_help_files() */

/**
 * This method is used to get the directory for the help files.
 * This should be overridden in higher up objects that use this object.
 */
string query_help_file_directory() { return "/doc/unknown/"; }

/*
 * Make a string from a nroff input...
 */
private string nroff_file( string name, int html ) {
    string nroff_fn, str;

    if( name[0] != '/')
        name = query_help_file_directory() + name;

    nroff_fn = NROFF_DIR + replace( name, "/", ".");

    if( html )
        str = NROFF_HAND->html_file( nroff_fn, 1 );
    else
        str = NROFF_HAND->cat_file( nroff_fn, 1 );

    if( !str ) {
        NROFF_HAND->create_nroff( name, nroff_fn );
        if( html )
            str = NROFF_HAND->html_file( nroff_fn, 0 );
        else
            str = NROFF_HAND->cat_file( nroff_fn, 0 );
    }

    return str;

} /* nroff_file() */

/**
 * This method returns the help data as a function pointer.
 * The function pointer needs to be evaluated to create the actual text.
 * @return the function pointer for the help text
 */
mixed help_function() {
    string *help;

    // So that we can override this function in objects if needed.
    // Useful to cut down the size of save files.
    // - Sandoz.
    help = TO->query_help_files();

    if( sizeof(help) ) {
        string str, *ret = ({ });
        foreach( str in help )
           ret += ({ ({ replace_string( str, "_", " "),
                     (: nroff_file($(str), 0 ) :) }) });
        return ret;
    }

    return 0;

} /* help_function() */

/**
 * This method returns the help as a string.
 * @return the help as a string
 */
string help_string() {
    string *help;

    // See the comments in help_function().
    help = TO->query_help_files();

    if( sizeof(help) ) {
        string str, ret = "";
        foreach( str in help )
            ret += nroff_file( str, 0 );
        return str;
    }

    return 0;

} /* help() */
