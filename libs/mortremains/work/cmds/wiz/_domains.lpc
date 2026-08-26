/*
// The "domains" command.
// Brought to you by Jubal.
// Part of the TMI mudlib.
// Mobydick updated it for the new login, 1-28-92
*/

#include <config.h>
#include <fingerd.h>
#include <domains.h>
#include <daemons.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_domains( string str )
{
	int i, flag;
	object ob;
	object link ;

	if( ! str )
	{
		ob = this_player();
		str = (string) ob -> query("cap_name");
	}
	else ob = find_player( str );
	if (!ob && user_exists(str)) {
		ob = FINGER_D -> restore_data(str) ;
	}

	i = -1;
	if( ! ob && ( i = member_array( str, DOMAIN_LIST ) ) < 0 )
	{
		notify_fail( "Player not found.\n" );
		return 0;
	}
	else if( i >= 0 )
	{
		int j;
		object *u ;
		string buf, tb;

		u = users(); buf = ""; flag = 0;
		for( j=0 ; j<sizeof(u) ; j++ )
		{
			link = u[j]->query_link() ;
			tb = (string) DOMAIN_D -> query_domain(link,str) ;
			if( tb != str ) continue;
			if( strlen( buf ) + strlen( tb ) > 70 )
			{
				if( ! flag ) write( "Logged in members of the " + str + " domain are:\n" );
				flag = 1;
				write( buf + ",\n" );
				buf = "";
			}
			if( strlen( buf ) > 0 ) buf += ", ";
			buf += (string) u[j] -> query("cap_name");
		}
		if( strlen( buf ) > 0 )
		{
			if( ! flag ) write( "Logged in members of the " + str + " domain are:\n" );
			write( buf + ".\n" );
		}
		else
			write( "No members of that domain are logged in.\n" );
		return 1;
	}

	write( "Domain affiliations for " + capitalize( str ) + ":  " );
	link = ob->query_link() ;
	for( flag=i=0 ; i<sizeof(DOMAIN_LIST) ; i++ )
		if ((string) DOMAIN_D->query_domain(link,DOMAIN_LIST[i]))
	{
		flag = 1;
		printf( "\n  %-10s %10s (%s)", DOMAIN_LIST[i],
			(string) DOMAIN_D -> query_domain_level (link, DOMAIN_LIST[i] ),
			(string) DOMAIN_D -> query_domain_sponsor (link, DOMAIN_LIST[i] )) ;
	}
	if( ! flag )
	{
		if ((string) DOMAIN_D -> query_domain_level(link) == "seeker")
			write( "seeker" );
		else
			write( "guest" );
	}
	write( "\n" );
	return 1;
}


int help()
{
	int i;

	write(
"Command: domains\n" +
"Syntax:  domains [name|domain]\n" +
"  The domains command lists all of your domain affiliations, or if\n" +
"the optional argument is given, the domain affiliations of the named\n" +
"person. The person need not be logged in for this to work. If the name\n"+
"of a domain is given instead of a player name, all of the members of\n" +
"that domain who are logged in are listed.\n" +
"  TMI currently has " + sizeof(DOMAIN_LIST) + " domains:\n    " );
	for( i=0 ; ; i++ )
	{
		if( i == sizeof( DOMAIN_LIST ) ) break;
		if( i>0 ) write( ", " );
		write( DOMAIN_LIST[i] );
	}
	write( "\n" +
"  Within each domain, there are " + (sizeof(LEVEL_LIST)-2) + " levels:\n" +
"    " );
	for( i=2 ; ; i++ )
	{
		if( i == sizeof( LEVEL_LIST ) ) break;
		if( i>2 ) write( ", " );
		write( LEVEL_LIST[i] );
	}
	write( "\n  See Also: sponsor, demote, primary\n" );
	return 1;
}


/* EOF */
