/*
// File     : identify.c
// Syntax   : string identify( mixed a )
// Purpose  : identify the variable 'a' as a string.
// 92-12-12 : Pallando wrote this function, based on ones he wrote
//            for Ephemeral Dales and other muds.
// 93-03-03 : Pallando added floats
// 93-03-28 : Pallando changed implode(explode()) to replace_string()
//            Pallando added replacement of \\ and \"
// 93-08-19 : Pallando added check for recursive arrays and mappings
//            Pallando added check for too deep recursion
*/

#define MAX_RECURSION 20
nosave mapping found;
nosave string *position;
nosave int recursion;

varargs string identify( mixed a, int flag )
{
    int i, j, s;
    string rec, ret;
    mapping map;

    if( undefinedp( a ) ) return flag? a: "UNDEFINED";
    if( nullp( a ) ) return "0";
    if( intp( a ) ) return "" + a;
    if( floatp( a ) ) return "" + a;
    if( objectp( a ) )
    {
//		if( flag ) return base_name(a);
        if( ret = a-> query( "name" ) ) ret += " ";
        else ret = "";
        return "OBJ(" + ret + file_name( a ) + ")";
    }
    if( stringp( a ) )
    {
        a = replace_string( a, "\\", "\\\\" );
        if( flag && strlen( a ) > 70 )
            a = "@LONG_TEXT\n" + a + (a[strlen(a)-1]=='\n'?"":"\n") + "LONG_TEXT\n";
        else {
            a = replace_string( a, "\"", "\\\"" );
            a = replace_string( a, "\\\"", "\"" );
            a = replace_string( a, "\n", "\\n" );
            a = replace_string( a, "\t", "\\t" );
            a = "\"" + a + "\"";
        }
        return a;
    }
    if( functionp( a ) )
        return "(: " + identify( a[0], flag ) + ", " + identify( a[1], flag ) + " :)";
    if( origin() !="local" )
    {
        found = ([ ]);
        position = allocate( MAX_RECURSION + 1 );
        recursion = 0;
        position[recursion] = "X";
    }
    if( recursion == MAX_RECURSION )
        return "TOO_DEEP_RECURSION";
    if( pointerp( a ) )
    {
        found[a] = implode( position[0..recursion], "" );
        recursion++;
        ret = "({ ";
        s = sizeof( a );
        for( i = 0 ; i < s ; i++ )
        {
            if( i ) ret += ", ";
            if( flag ) {
                ret += "\n";
                for(j=0; j<=flag; j++) ret += "\t";
            }
            position[recursion] = "[" + i + "]";
            if( rec = found[a[i]] ) ret += rec;
            else ret += identify( a[i], flag? flag+1: 0 );
        }
        recursion--;
        return ret + ( s ? " " : "" ) + "})";
    }
    if( mapp( a ) )
    {
        found[a] = implode( position[0..recursion], "" );
        recursion++;
        ret = "([ ";
        map = (mapping)(a);
        a = keys( map );
        s = sizeof( a );
        for( i = 0 ; i < s ; i++ )
        {
            if( i ) ret += ", ";
            if( flag ) {
                ret += "\n";
                for(j=0; j<=flag; j++) ret += "\t";
            }
            position[recursion] = ".KEY(" + i + ").";
            if( !( rec = found[a[i]] ) ) rec = identify( a[i] );
            ret += rec;
            ret += " : ";
            position[recursion] = "[" + rec + "]";
            if( rec = found[map[a[i]]] ) ret += rec;
            else ret += identify( map[a[i]], flag? flag+1: 0 );
        }
        recursion--;
        return ret + ( s ? " " : "" ) + "])";
    }
    return "UNKNOWN";
}
