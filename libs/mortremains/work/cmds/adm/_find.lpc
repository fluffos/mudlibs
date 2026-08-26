int atoi(string a) { return to_int(a); }
/*
 * Unix-style find
 *
 * Author:	Zak (Luke Mewburn - zak@rmit.edu.au)
 * Date:	930205 00:43
 *
 *  This file is Copyright (C) 1992, 1993, Luke Mewburn. You are free
 * to distribute this file as long as it is not sold for profit,
 * and this header is not removed.
 *
 */

#define VERSION "1.0 930307"

/*
 * Notes:
 *
 * Requires:
 *  - MudOS 0.9.14 or greater.
 *  - get_dir(path, -1) (res of format: file, mtime, size)
 *  - printf() efun.
 *  - match_string (interface to match_string() in file.c)
 *     (if unavailable, uncomment code around `case "-name":' in find_the_way())
 *	(Note: now have simul_efun() for match_string() if necessary)
 *
 * Todo:
 *  - add -mmin, expr grouping.
 *  - fix -ok (currently it doesn't get confirmation)
 *
 */
 
#include <config.h>
#include <mudlib.h>
inherit DAEMON;

#define DIR_NAM	0	// offset in get_dir result for name
#define DIR_SIZ	1	// offset in get_dir result for size
#define DIR_MOD	2	// offset in get_dir result for last modification

#define STAT_SIZ 0	// offset in stat result for size
#define STAT_MOD 1	// offset in stat result for last modification

    // guess who wants enums... :)
#define EXPR_EXPR	1
#define EXPR_NOT	2
#define EXPR_GRTR	4
#define EXPR_LESS	8
#define EXPR_EQUAL	16

#define FLAG_CONFIRM	1
#define FLAG_DEBUG	2


#define EOL_CHAR "\\;"

#define error_rep(err)	printf( "%s: %s\n", query_verb(), err );

nosave mixed *	commands;
nosave object	act_ob;
nosave int	flags;

//
// Format of commands array:
//
//  ({
//     ({ path }) [ ({ expr, pred, args }) .. ] 
//        . . . 
//  })
//  

void parse_opts( string path, string str )
{
    mixed	*stbuf;
    string	cur, arg, *list, tstr;
    int		x, max, expr, cpos, today, t, no_print;

    list = explode( str, " " );
    max = sizeof( list );
    commands = ({ ({ path }) });
    cpos = 0;
    expr = 0;
    no_print = 0;
    today = time();

    for ( x = 0; x < max; x++ )
    {
	if ( !list[x] )
	    continue;
	cur = list[x];
	if (x < max -1 )
	    arg = list[x + 1];
	else
	    arg = 0;
	if ( cur == "!" )
	{
	    if ( !arg )
	    {
		error_rep("Invalid expression after !.");
		return 0;
	    }
	    expr |= EXPR_EXPR;
	    expr ^= EXPR_NOT;
	    continue;
	}
	switch( cur )
	{
            case "-debug":
                if ( expr & EXPR_NOT )
                    flags &= ~FLAG_DEBUG;
                else
                    flags |= FLAG_DEBUG;
                arg = 0;
                break;
	    case "-print":
	    case "-ls":
		no_print++;
	    case "-prune":
		arg = 0;
		break;
	    case "-type":
		if ( arg != "d" && arg != "f")
		{
		    error_rep("Argument to -type must be d or f.");
		    return 0;
		}
		break;
            case "-path":
		if ( !arg )
		{
		    error_rep("Expect argument after -path");
		    return 0;
		}
		arg = resolv_path( (string) act_ob->query("cwd"), arg ) + "/";
		break;
	    case "-newer":
		if ( !arg )
		{
		    error_rep("Expect argument after -newer");
		    return 0;
		}
		tstr = resolv_path( (string) act_ob->query("cwd"), arg );
		stbuf = stat( tstr );
		if ( ( sizeof( stbuf ) != 3 ) || ( stbuf[ STAT_MOD ] < 0 ) )
		{
		    error_rep("Argument to -newer must be a file");
		    return 0;
		}
		expr |= EXPR_GRTR;
		arg = "" + stbuf[ STAT_MOD ];
		break;
	    case "-size":
		if ( !arg
		    || arg[0] != '+' && arg[0] != '-' 
			&& ! (arg[0] >= '0' && arg[0] <= '9' )
		    || sscanf( arg + " ", "%d%s", t, tstr ) != 2
		    || tstr != " " && tstr != "c " && tstr != "k "
		    )
		{
		    error_rep("Invalid argument to -size");
		    return 0;
		}
		if ( arg[0] == '+' )
		    expr |= EXPR_GRTR;
		else
		    if ( arg[0] == '-' )
			expr |= EXPR_LESS;
		    else
			expr |= EXPR_EQUAL;
		if ( t < 0 )
		    t = -t;		// ensure value is +ve
		if ( tstr == " " )
		    tstr = "b ";	// b == block
		arg = tstr[0..0] + t;
		break;
	    case "-mtime":
		if ( !arg
		    || arg[0] != '+' && arg[0] != '-' 
			&& ! (arg[0] >= '0' && arg[0] <= '9' )
		    || sscanf( arg + " ", "%d%s", t, tstr ) != 2
		    || tstr != " "
		    )
		{
		    error_rep("Invalid argument to -mtime");
		    return 0;
		}
		if ( arg[0] == '+' )
		    expr |= EXPR_LESS;
		else
		    if ( arg[0] == '-' )
			expr |= EXPR_GRTR;
		    else
			expr |= EXPR_EQUAL;
		if ( t < 0 )
		    t = -t;		// ensure value is +ve
		t = today - t * 60 * 60 * 24;
		arg = "" + t;
		break;
	    case "-exec":
	    case "-ok":
		no_print++;
		for (t = x + 1 ; t < max ; t++ )
		    if ( list[t] == EOL_CHAR )
			break;
		if ( t >= max )
		{
		    error_rep("Expect " + EOL_CHAR + " after expression to " + cur);
		    return 0;
		}
		arg = implode( list[x + 1 .. t - 1], " " );
		x = t;
		break;
	    case "-name":
	    case "-author":
	    case "-user":
	    case "-domain":
	    case "-group":
	    case "-uid":
		if ( !arg )
		{
		    error_rep("Expect argument after " + cur);
		    return 0;
		}
		break;
	    default:
		if ( cur[0] == '-' )
		{
		    error_rep("Invalid predicate `" + cur + "'");
		    return 0;
		}
		if ( expr & EXPR_EXPR )
		{
		    error_rep("Paths must precede expression.");
		    return 0;
		}
		if ( ! no_print )	// default -print.
		    commands[ cpos ] += ({ 0, "-print", 0 });
		no_print = 0;
		expr = 0;
		commands += ({ ({ cur }) });
		cpos++;
		continue;
	} // switch
	commands[cpos] += ({ expr, cur, arg });
	expr = 0;
	if (arg)
	    x++;
    } // for
    if ( ! no_print )	// default -print.
	commands[ cpos ] += ({ 0, "-print", 0 });
} // parse_opts


void debug_command( int pos )
{
    int x;
    if ( sizeof( commands[ pos ] ) <= 1 )
    {
	write("No commands.\n");
	return;
    }
    printf( "Path is: %s\n", commands[pos][ 0 ] );
    for ( x = 1; x < sizeof( commands[pos] ); x+= 3 )
    {
	printf( "%d: %s %s", x, commands[pos][x + 1], commands[pos][x + 2] );
	if ( commands[pos][x] & EXPR_NOT )
	    write( "  [NOT]");
	if ( commands[pos][x] & EXPR_GRTR )
	    write( "  >n");
	if ( commands[pos][x] & EXPR_LESS )
	    write( "  <n");
	write("\n");
    }
} // debug_command


void conf_cmd_res( string res )
{
    if ( !res )
	return;
    if ( lower_case( res[ 0..0 ] ) == "y" )
	flags |= FLAG_CONFIRM;
} // conf_cmd_res

void confirm_cmd( string cmd, string path, string file)
{
    flags ^= FLAG_CONFIRM;
    printf( "< %s ... %s%s >?", cmd, path, file );
    input_to( "conf_cmd_res", 0 );
} // confirm_cmd


void find_the_way( int pos, string cwd, string path )
{
    mixed *dir;
    string curpath, tstr;
    int sx, x, sy, y;
    int res, dif, prune, sixmonths;

    curpath = path;
    if ( curpath != "/" )
	curpath += "/";
    path = resolv_path( cwd, path );
    if ( path != "/" )
	path += "/.";
    dir = get_dir( path, -1 );
    sx = sizeof( dir );
    sy = sizeof( commands[ pos ] );
    prune = 0;
    sixmonths = time() - 60*60*24*30*6;
    for ( x = 0; x < sx; x++ )
    {
	for ( y = 1; y < sy; y+= 3 )
	{
	    res = 0;
	    switch ( commands[ pos ][ y + 1 ] )
	    {
		case "-print":
		    printf( "%s%s\n", curpath, dir[ x ][ DIR_NAM ] );
                    	// fall thru.
                case "-debug":
		    res = ( ! ( commands[ pos ][ y ] & EXPR_NOT ) );
			    // force TRUE
		    break;
		case "-ls":
		    tstr = ctime( (int) dir[ x ][ DIR_MOD ] );
	    // if file older than 6 months, use year instead of hh:mm
		    if ( dir[ x ][ DIR_MOD ] < sixmonths )
			tstr = tstr[ 4..9 ] + tstr[ 19..23 ];
		    else
			tstr = tstr[ 4..15 ];
		    printf("% 7d  %s  %s%s\n", dir[ x ][DIR_SIZ], tstr, curpath, dir[ x ][DIR_NAM]);
		    res = ( ! ( commands[ pos ][ y ] & EXPR_NOT ) );
			    // force TRUE
		    break;
		case "-type":
		    if ( ( commands[ pos ][ y + 2 ] == "f" && dir[ x ][ DIR_SIZ ] >= 0 )
		      || ( commands[ pos ][ y + 2 ] == "d" && dir[ x ][ DIR_SIZ ] < 0 ) )
			res = 1;
		    break;
		case "-newer":
		case "-mtime":
		case "-size":
		    if ( commands[ pos ][ y + 1 ] == "-size" )
		    {
			dif = dir[ x ][ DIR_SIZ ];
			if ( commands[ pos ][ y + 2 ][ 0 ] == 'b' ) 
			{
			    dif = ( dif + 511 ) >> 9;
				// round up to nearest block
			}
			else
			    if ( commands[ pos ][ y + 2 ][ 0 ] == 'k' ) 
			    {
				dif = ( dif + 1023 ) >> 10;
				    // round to nearest K
			    }
			dif -= atoi( extract( commands[ pos ][ y + 2 ], 1 ) );
		    }
		    else
			dif = dir[ x ][ DIR_MOD ] - atoi( commands[ pos ][ y + 2 ] );
		    if ( ( dif < 0 ) && ( commands[ pos ][ y ] & EXPR_LESS )
		      || ( dif > 0 ) && ( commands[ pos ][ y ] & EXPR_GRTR )
		      || ( dif == 0 ) && ( commands[ pos ][ y ] & EXPR_EQUAL ) )
			res = 1;
		    break;
		case "-ok":
// ignore confirmation for now.
//		    confirm_cmd( commands[ pos ][ y + 1 ], curpath, commands[ pos ][ y + 2] );
//		    if ( ! ( flags & FLAG_CONFIRM ) )
//			break;
		    // fall thru
		case "-exec":
		    tstr = replace_string( commands[ pos ][ y + 2 ],
				"{}", curpath + dir[ x ][ DIR_NAM ] );
		    res = act_ob->force_me( tstr );
		    break;
		case "-name":
		    res = match_string( commands[ pos ][ y + 2 ], dir[ x ][ DIR_NAM ] );
// uncomment below if no match_string() available
//		    res = ( commands[ pos ][ y + 2 ]== dir[ x ][ DIR_NAM ] );
		    break;
		case "-path":
		    tstr = ( path == "/" ?  path :
					    path[ 0..strlen( path ) - 2 ] );
		    res = match_string( commands[ pos ][ y + 2 ], tstr );
// uncomment below if no match_string() available
//		    res = ( tstr == commands[ pos ][ y + 2 ] );
		    break;
		case "-prune":
		    res = ( ! ( commands[ pos ][ y ] & EXPR_NOT ) );
			// force TRUE
		    prune = 1;
		    break;
		case "-author":
		case "-user":
		    tstr = MASTER_OB->author_file( curpath + dir[ x ][ DIR_NAM ] );
		    res = ( commands[ pos ][ y + 2 ] == tstr );
		    break;
		case "-domain":
		case "-group":
		    tstr = MASTER_OB->domain_file( curpath + dir[ x ][ DIR_NAM ] );
		    res = ( commands[ pos ][ y + 2 ] == tstr );
		    break;
		case "-uid":
		    tstr = MASTER_OB->creator_file( curpath + dir[ x ][ DIR_NAM ] );
		    res = ( commands[ pos ][ y + 2 ] == tstr );
		    break;
		default:
			// for predicates we forgot to code for.
		    printf( "%s: %s%s\n", commands[ pos ][ y + 1 ], curpath, dir[ x ][ DIR_NAM ] );
		    break;
	    } // switch
	    if ( commands[ pos ][ y ] & EXPR_NOT )
		res = !res;
	    if ( !res )
		break;
	} // for commands
	if ( ( dir[ x ][ DIR_SIZ ] == -2 ) && ( !prune ) )	// recurse dirs
	{
	    find_the_way( pos, cwd, curpath + dir[ x ][ DIR_NAM ] );
	    continue;
	}
    } // for x .. dir
} // find_the_way


int cmd_find( string str )
{
    string path, pred, cwd;
    int    x;

    act_ob = this_player();
    if ( !adminp(geteuid(this_player(1))) )
    {
        write("Sorry, due to the fact that this command eats lots of CPU, only admins\nan use it.\n");
        return 1;
    }
    seteuid( getuid( act_ob ) );

    if ( !str || str == "" )
    {
	notify_fail( "Usage: find path [ predicates ] ...\n" );
	return 0;
    }
    if ( sscanf( str, "%s %s", path, pred ) != 2 )
    {
	path = str;
	pred = "";
    }
    parse_opts( path, pred );
    if ( ! commands )
	return 1;			// it failed
    cwd = (string) previous_object()->query( "cwd" );
    for ( x = 0; x < sizeof( commands ); x++ )
    {
	if ( flags & FLAG_DEBUG )
	    debug_command( x );
	find_the_way( x, cwd, commands[ x ][ 0 ] );
    }
    return 1;
} // find


string help( string str )
{
    return "\
Usage: find path predicates\n\
\n\
path       - directory to begin the search from.\n\
predicates - list of commands which determine all must be true if further\n\
	     actions are to be performed upon the current file.\n\
\n\
Predicates supported include:\n\
!		inverts the result of the following expression.\n\
-name expr      true if current file matches expr\n\
-path dir	true if dir matches preceeding path of current file\n\
-print          print current match (is always true)\n\
-ls             print current match as long listing (is always true)\n\
-prune		don't descend into subtree (always true)\n\
-type (d|f)     true if file is of correct type (d == dir, f == file)\n\
-newer cmpfil	true if file is newer than cmpfil\n\
-mtime n	true if file modified n days ago\n\
-size n[ck]	true if file of size n 512byte blocks [c=byte, k=Kbyte]\n\
-author wiz	true if file is owned by wiz\n\
-user wiz	as -author\n\
-domain dom	true if file is in domain dom\n\
-group dom	as -domain\n\
-uid id		true if file has uid id (only at load time)\n\
-exec cmd " + EOL_CHAR + "    executes command cmd. True if commands returns non-zero\n\
		result. Occurances of {} in cmd will be replaced by the\n\
		current filename.\n\
-ok cmd " + EOL_CHAR + "      as -exec, but displays the command which will be executed\n\
		and prompts with for a confirmation of each action.\n\
\n\
'n' as an argument is 'n' for exactly n, '-n' for < n, and '+n' for > n.\n\
\n\
This command was written by Zak, version " +VERSION+ ". Send all comments to:\n\
zak@rmit.edu.au\n\
\n\
Warning!:  -ok  doesn't actually ask for confirmation in this\n\
version, it just acts as -exec.\n\
";
} // help
