/*
// File     : identify.c
// Syntax   : varargs string identify( mixed a, string indent )
// Purpose  : identify the variable 'a' as a string.
// 92-12-12 : Pallando wrote this function, based on ones he wrote
//            for Ephemeral Dales and other muds.
// 93-03-03 : Pallando@TMI-2 added floats
// 93-03-28 : Pallando changed implode(explode()) to replace_string()
//            Pallando@Nightmare added replacement of \\ and \"
// 93-08-19 : Pallando added check for recursive arrays and mappings
//            Pallando added check for too deep recursion
// 93-09-09 : Pallando@CWLIB added indent option
//            Pallando included config.h (for __tmi__) and origin.h
*/
#include <driver/origin.h>
#include <config.h>

#define MAX_RECURSION 20
#ifdef __tmi__
#define QUERY_NAME query( "name" )
#else
#define QUERY_NAME query_name()
#endif /* __tmi__ */

nosave mapping found;
nosave string *position;
nosave int recursion;

varargs string identify( mixed a, string indent )
{
    int i, s;
    string ind, rec, ret;
    mapping map;

    if( origin() != ORIGIN_LOCAL )
    {
        found = ([ ]);
        position = allocate( MAX_RECURSION + 1 );
        recursion = 0;
        position[recursion] = "X";
    }
    ind = "";
    if( stringp( indent ) )
        for( i = 0 ; i < recursion ; i++ )
            ind += indent;
    if( undefinedp( a ) )
        return ind + "UNDEFINED";
    if( nullp( a ) )
        return ind + "0";
    if( intp( a ) )
        return ind + a;
    if( floatp( a ) )
        return ind + a;
    if( objectp( a ) )
    {
        if( stringp( ret = (string)a-> QUERY_NAME ) )
            ret += " ";
        else
            ret = "";
        return ind + "OBJ(" + ret + file_name( a ) + ")";
    }
    if( stringp( a ) )
    {
        a = replace_string( a, "\"", "\\\"" );
        a = "\"" + a + "\"";
        a = replace_string( a, "\\", "\\\\" );
        a = replace_string( a, "\\\"", "\"" );
        a = replace_string( a, "\n", "\\n" );
        a = replace_string( a, "\t", "\\t" );
        return ind + a;
    }
    if( functionp( a ) )
        return ind + "(: " + identify( a[0] ) + ", " + identify( a[1] ) + " :)";
    if( recursion == MAX_RECURSION )
        return ind + "TOO_DEEP_RECURSION";
    if( pointerp( a ) ) 
    {
#if 0
        found[a] = implode( position[0..recursion], "" );
        if( !( s = sizeof( a ) ) ) return ind + "({ })";
        recursion++;
        ret = "";
        for( i = 0 ; i < s ; i++ )
        {
            position[recursion] = "[" + i + "]";
            if( !( rec = found[a[i]] ) )
                rec = identify( a[i], indent );
            ret += ( i ? ( indent ? ",\n" : ", " ) : "" ) + rec;
        }
        recursion--;
        if( !indent ) return "({ " + ret + " })";
        return ind + "({\n" + ret + "\n" + ind + "})";
#else
        ret = "({ ";
        s = sizeof( a );
        for( i = 0 ; i < s ; i++ )
        {
            if( i ) ret += ", ";
            ret += identify( a[i] );
        }
        return ret + ( s ? " " : "" ) + "})";
#endif
    }
    if( mapp( a ) )
    {
        found[a] = implode( position[0..recursion], "" );
        map = (mapping)(a);
        a = keys( map );
        if( !( s = sizeof( a ) ) ) return ind + "([ ])";
        recursion++;
        ret = "";
        for( i = 0 ; i < s ; i++ )
        {
            ret += ( i ? ( indent ? ",\n" : ", " ) : "" );
            position[recursion] = ".KEY(" + i + ").";
            if( !( rec = found[a[i]] ) )
                rec = identify( a[i] );
            ret += ind + ( indent ? indent : "" ) + rec + " : ";
            position[recursion] = "[" + rec + "]";
            if( !( rec = found[map[a[i]]] ) )
            {
                if( indent && (
                  ( mapp( map[a[i]] ) && sizeof( keys( map[a[i]] ) ) ) ||
                  ( pointerp( map[a[i]] ) && sizeof( map[a[i]] ) ) ) )
                    rec = "\n" + identify( map[a[i]], indent );
                else
                    rec = identify( map[a[i]] );
            }
            ret += rec;
        }
        recursion--;
        if( !indent ) return "([ " + ret + " ])";
        return ind + "([\n" + ret + "\n" + ind + "])";
    }
    return ind + "UNKNOWN";
}
