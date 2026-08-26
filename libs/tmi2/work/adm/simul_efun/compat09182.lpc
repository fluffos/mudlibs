/*
// File     :  compat_0.9.18.2.c
// Purpose  :  Simulated efuns to replace efuns removed from the MudOS Driver
//             between versions 0.9.18.1 and 0.9.18.2
// 93-09-21 :  Pallando wrote simul_efun versions of: log_file(), extract(),
//             first_inventory(), next_inventory(), shadowp() and cat()
// Missing  :  next_living(), add_worth(), add_verb() and add_xverb()
*/
#include <config.h>
#include <uid.h>
#include <commands.h>

#define CAT_LINES_DEFAULT 24
#define CAT_LINES_MAXIMUM 40
#define MAX_LOG_SIZE 200000

varargs int cat( string path, int start, int num )
{
    string text;
    int trun;

    if( !path ) return 0; // syntax error
    if( !start ) start = 0;
    if( !num ) num = CAT_LINES_DEFAULT;
    if( num > CAT_LINES_MAXIMUM )
    {
        num = CAT_LINES_MAXIMUM;
        trun = 1;
    }
    seteuid( geteuid( previous_object() ) );
    if( text = read_file( path, start, num ) )
    {
        if( trun && ( strlen( text ) < file_size( path ) ) )
            text += "***TRUNCATED***\n";
        message( "cat", text, this_player() );
        return 1; // success
    }
    // File doesn't exist, start is a non-positive number or 
    // you have tried to read past the end of the file
    return 0; // fail
}

varargs string extract( string str, int from, int to )
{
    if( !stringp( str ) ) return ""; // syntax error
    if( nullp( from ) ) return str;
    if( nullp( to ) ) to = strlen( str );
    return str[from..to];
}

object first_inventory( mixed ob )
{
    object *inv;

    if( stringp( ob ) )
        ob = find_object( ob );
    if( !objectp( ob ) ) return 0;
    if( sizeof( inv = all_inventory( ob ) ) )
        return inv[0];
    return 0;
}

// NB Use of this function is inefficient.  Where before you may have done:
// {
//   object ob;
//   for( ob = first_inventory( X ) ; ob ; ob = next_inventory( ob ) )
//     ...
// }
// you should now do 
// {
//   int loop, size; object ob, *obs;
//   size = sizeof( obs = all_inventory( X ) );
//   for( loop = 0 ; loop < size ; loop++ )
//     ob = obs[loop];
//     ...
// }
object next_inventory( object ob )
{
    object env, *inv;
    int ind;

    if( !objectp( ob ) ) return 0; // syntax error
    if( !objectp( env = environment( ob ) ) ) return 0; // fail
    // The following 'if' statement is the equivalent of:
    //   inv = all_inventory( env );
    //   ind = 1 + member_array( ob, inv  );
    //   if( ind == sizeof( inv ) ) return 0;
    // but has been made compact for speed
    if( sizeof( inv = all_inventory( env ) ) ==
      ( ind = 1 + member_array( ob, inv  ) )   )
        return 0; // fail
    return inv[ind]; // success
}

object shadowp( object ob ) { return query_shadowing( ob ); } 

void log_file( string file, string text )
{
    if( !stringp( file ) || !stringp( text ) ) return; // syntax error
    if( -1 != strsrch( file, ".." ) ) return; // security error
    if (previous_object()) {
	if (base_name( previous_object() ) ==USER_OB ||
            base_name( previous_object() ) == CONNECTION ||
	    base_name( previous_object() ) == CMD_ED) {
	    seteuid(ROOT_UID) ;
	} else {
	    seteuid(geteuid(previous_object())) ;
	}
   }
    file = LOG_DIR + file; // would 'sprintf' be much better here?
    if( file_size( file ) > MAX_LOG_SIZE )
        rename( file, file + ".old" );
    write_file( file, text );
}
