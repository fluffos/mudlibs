/*
// File     :  /cmds/std/_who.c
// Comment  :  A command to let users know who else is on this mud
//	       It has the option to see who is on other muds
//	       There was a "who" command in MUD1, but the code for
//	       this one was written from scratch for TMI and is part
//	       of the TMI-2 distribution mudlib.  If you use any of
//	       this code, please keep this header.
// 91-**-** :  Jubal @ TMI wrote it
// 92-01-02 :  Sulam @ TMI changed the title stuff
// 92-01-20 :  DocZ @ TMI modified it for time zones
// 92-02-15 :  Truilkan @ TMI modified it for players (removed wizard only info)
//	       Original TMI _who is now _people
// 92-10-10 :  Mobydick modified it to respect invisibility
// 93-02-22 :  Pallando changed [0] to <login> on aesthetic grounds
// 93-03-22 :  Watcher removed user inhabited monsters from the display
// 93-04-14 :  Watcher change the query("invisible") to a visible() check
// 93-07-13 :  Grendel added sorting alphabetically
// 93-07-26 :  Grendel added -d option, optimised
// 93-08-18 :  Grendel added @mud option, optimised
// 94-06-06 :  Leto split do_who() off from cmd_who() for the use of http.c
// 94-06-12 :  Pallando fixed a few bugs
// 94-06-14 :  Leto added the checks for this_player for the http.c
// 94-09-04 :  Beek added some code for % ^FOO% ^ support
// XX-OO-XX :  Drizzt@Tmi-2 added support for I3 rwho requests

// Bugs: wont detect netdead wizards in monster bodies (!)
//       Don't know whether to get round this by checking for connection
//       objects or not - haven't looked at connection objects
//       closely yet to figure out if it is safe

//       Could be optimised some more...
*/

#include <writef.h>
#include <mudlib.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <net/ftpd_base.h>

#define SYNTAX "Usage: who [ @<mud> | -d | -f ]\n"

inherit "/adm/daemons/timezone";
inherit DAEMON;

string do_who( string args );
string divide;

create()
{
    int i;
    
    ::create();
    for( divide = "", i = 0; i < 78; i++ )
	divide += "_";
    divide += "\n";
}

// sort array doesn't allow the optional argument the way filter array
// does, so we have to make it global
// This mapping is used so we don't have to do player->query("name")
// several zillion times in the sort function
mapping names;

int cmd_who( string arg )
{
    write( do_who( arg ) );
    return 1;
}

string ansi_kludge(string f1, string f2) {
    // Remember % ^FOO% ^ takes up no space
    string *tmp = explode(f1, "%^");
    int i,n;

    n = (sizeof(tmp)+1)/2;
    for (i=0; i<n; i++) tmp[i] = tmp[2*i];
    tmp = tmp[0..n-1];
    n = strlen(implode(tmp,""));
    return sprintf("%s%"+(65-n)+"s %4s\n", f1, "", f2);
}

string do_who( string arg )
{
    mixed *list;
    string lines, zone_name, str;
    int i, time_zone;
    int dead;
    string mud;
    
    names = ([]);
    // check args
    if( arg && arg != "" )
    {
	// linkdead option
	if( arg == "-d" )
	{
	    this_player()-> block_attack( 2 );
	    list = filter_array( children( USER ), "deadp", this_object() );
	    list = filter_array( list, "filter_users", this_object() );
	    if( !sizeof( list ) )
		return sprintf(
		  "%sThere are no linkdead users at this time\n%s",
		  divide, divide );
	    list = sort_array( list, "sort_users", this_object() );
	    write( divide + "  Linkdead users\n" + divide );
	    i = sizeof( list );
	    while( i-- )
		write( capitalize( geteuid( list[i] ) ) + "\n" );
	    write( divide );
	    return "";
	} else
	    if( arg == "-f" )
	    {
		this_player()-> block_attack( 2 );
		if (find_object(FTP_D) &&
		      catch( list = (mapping *)FTP_D->query_connections() ) )
		    return "";
		if( !sizeof( list ) )
		{
		    write( divide + "There are no FTP users at this time.\n"
		      + divide );
		    return "";
		}
		list = sort_array( list, "sort_users_in_mapping",
		  this_object() );
		write( divide + "  FTP users\n" + divide );
		i = sizeof( list );
		if( adminp(geteuid( previous_object() )) )
		    while( i-- )
		    {
			write( sprintf( "%-16s %s\n", ( list[i][USER_NAME] ),
			  ( list[i][USER_SITE] ) ) );
		    }
		else
		    while( i-- )
		    {
			write( ( list[i][USER_NAME] ) + "\n" );
		    }
		write( divide );
		return "";
	    // rwho option
	    } else if( sscanf( arg, "@%s", mud ) == 1 ) {
		return "/adm/daemons/network/I3/who"->send_who_req(mud, this_player()->query("name"));
	    } else {
		// bad option
		notify_fail( SYNTAX );
		return "";
	    }
    }
    
    if( this_player() ) this_player()-> block_attack( 2 );
    lines = divide;
    
    list = filter_array( users(), "filter_users", this_object() );
    list = sort_array( list, "sort_users", this_object() );
    
    if( !sizeof( list ) )
    {
	return( divide +
	  "\tLooks like no one is logged on. Strange beans, huh?\n" + divide );
    }
    
    if( sizeof( list ) > 1 )
	lines += "\t\t   There are " + sizeof( list ) +
	  " users connected.\n";
    else // (Buddha claims this message ;-)
	lines += "\t\tHow lonely!  You're the only one here.\n";
    
    if( this_player() )
	zone_name = (string)this_player()-> getenv( "TZONE" );
    else
	zone_name = "GMT";
    
    if( !time_zone = query_tzone( zone_name ) )
    {
	lines += "\t\tMud time is " + ctime( time() ) + "\n" +
	  "\t\t[Those contained in brackets are editing.]\n";
    } else {
	lines += "\t\t" + zone_name + " time is " + ctime( time_zone ) + "\n";
    }
    lines += divide +
      "Name                                                              Idle\n"
    + divide;
    
    i = sizeof( list );
    while( i-- )
    {
	string field1, field2;
	mixed val;
	
	if( !list[i] ) continue;
	if( (int)list[i]-> query( "npc" ) )
	    field1 = "(" + capitalize( (string)list[i]-> link_data( "name" ) ) +
	      " is inhabiting " +
	      (string)list[i]-> query( "short" ) + ")";
	else field1 = (string)list[i]-> query( "short" );
	
	if( in_edit( list[i] ) || in_input( list[i] ) )
	    field1 = "[" + field1 + "]";
	if( !field1 ) field1 = "(null)";
	if( field1 == "[0]" ) field1 = "<login>";
	
	val = query_idle( list[i] );
	if( val >= 3600 )
	    field2 = val/3600 + "h";
	else if( val >= 60 )
	    field2 = val/60 + "m";
	else field2 = "";
//	      lines += writef(field1,65,QUIET|TRUNC_RIGHT) + " "+
//		       writef(field2,4,QUIET|JFY_RIGHT) + "\n";
//	lines += sprintf( "%-:65s %4s\n", field1, field2 );
    lines += ansi_kludge( field1, field2 );
    }
    lines += divide;
    return( lines );
}

// note this returns the list in REVERSE order - this is a speed
// optimisation, instead of doing for(i=0;i<sizeof(foo);i++)
// we can do i=sizeof(foo); while(i--)
int sort_users( object u1, object u2 )
{
    // use the names mapping for speed
    return strcmp( names[u2], names[u1] );
}

int sort_users_in_mapping( mapping u1, mapping u2 )
{
    return strcmp( u1[USER_NAME], u2[USER_NAME] );
}

int filter_users( object who )
{
    if( (int)who-> query( "npc" ) && !wizardp( this_player() ) ) return 0;
    if( !who-> query( "name" ) ) return 0;
    if( visible( who, this_player() ) )
    {
	// build up the names mapping
	names[who] = (string)who-> query( "name" );
	return 1;
    }
    return 0;
}

// used by linkdead option
int deadp( object who )
{
    if( !geteuid( who ) )
	return 0;
    return (int)who-> query_linkdead();
}

int help()
{
    write( SYNTAX + "\n" + @HELP
The who command will give you a list of all user's presently logged
onto the MUD, and whether or not they are idle at this time.
The "@<mud>" options requests a list of users at the remote mud.
This is usually shorter than the finger output, though that depends
on the remote mud.
The "-d" option gives a list of linkdead users.
The "-f" options lists all current FTP users.
HELP
    );
    
    return 1;
}

/* EOF */
