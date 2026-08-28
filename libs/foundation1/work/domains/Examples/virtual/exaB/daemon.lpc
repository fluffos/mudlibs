/*
// File     :  /domains/Examples/virtual/exaB/daemon.c
// Comment  :  This object works out what each .exaB looks like
// 94-05-20 :  Pallando @ Nightmare wrote it
*/
#include "defines.h"

string *exits;
string *terrs;
string *descs;

mapping get_data( string arg )
{
    mapping data = ([]);
    string format;
    int x, y, i;

    // Get coordinates of room (x,y)
    // X increases to the east, Y increases to the south
    sscanf( arg, "%d,%d", x, y );

    data["prop"] = ([ "indoors" : 1, "light" : 1 ]);

    sscanf( terrs[y][3*x..3*x+1], "%d", i );
    sscanf( descs[i], "%s\n%s", data["short"], data["long"] );

    data["exits"] = ([]);
    format = PREFIX "%d,%d" SUFFIX;

    if( exits[2*y][2*x..2*x] == "\\" )
	data["exits"]["northwest"] = sprintf( format, x-1, y-1 );
    if( exits[2*y][2*x+1..2*x+1] == "|" )
	data["exits"]["north"] = sprintf( format, x, y-1 );
    if( exits[2*y][2*x+2..2*x+2] == "/" )
	data["exits"]["northeast"] = sprintf( format, x+1, y-1 );
    if( exits[2*y+1][2*x..2*x] == "-" )
	data["exits"]["west"] = sprintf( format, x-1, y );
    if( exits[2*y+1][2*x+2..2*x+2] == "-" )
	data["exits"]["east"] = sprintf( format, x+1, y );
    if( exits[2*y+2][2*x..2*x] == "/" )
	data["exits"]["southwest"] = sprintf( format, x-1, y+1 );
    if( exits[2*y+2][2*x+1..2*x+1] == "|" )
	data["exits"]["south"] = sprintf( format, x, y+1 );
    if( exits[2*y+2][2*x+2..2*x+2] == "\\" )
	data["exits"]["southeast"] = sprintf( format, x+1, y+1 );

    if( exits[2*y+1][2*x+1..2*x+1] == "*" )
        data["exception"] = 1;

    return data;
}

void create()
{
    exits = read_database( PREFIX "exits.db" );
    terrs = read_database( PREFIX "terrs.db" );
    descs = explode( read_file( PREFIX "descs.df" ), "### " );
}

/* EOF */
