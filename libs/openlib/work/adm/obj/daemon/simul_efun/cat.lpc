/*
// File     :  cat.c
//
// This code is part of the TMI-2 mudlib distribution.
// Adapted from: compat_0.9.18.2.c
// 93-09-21 :  Pallando wrote simul_efun versions of: cat()
//
*/

#define CAT_LINES_DEFAULT 50
#define CAT_LINES_MAXIMUM 60

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

    if( text = read_file( path, start, num ) )
    {
        if( trun && ( strlen( text ) < file_size( path ) ) )
            text += "***TRUNCATED***\n";
        message( "system", text, this_player() );
        return 1; // success
    }
    // File doesn't exist, start is a non-positive number or 
    // you have tried to read past the end of the file
    return 0; // fail
}
