/*
// The "primary" guild command.
// Brought to you by Jubal.
// Part of the TMI mudlib.
// Revised for the new login system by Mobydick, 1-27-93
*/

#include <config.h>
#include <mudlib.h>
#include <domains.h>
#include <daemons.h>

inherit DAEMON ;

int cmd_primary( string domain )
{
	object link ;

	if( ! domain )
	{
		notify_fail( "Usage: primary <domain>\n" );
		return 0;
	}
	if( member_array( domain, DOMAIN_LIST ) == -1 )
	{
		notify_fail( "No such domain.\n" );
		return 0;
	}

	link = this_player()->query_link() ;
	if ((int)DOMAIN_D->set_primary_domain(link,domain)) {
		write( "Primary domain set to " + domain + ".\n" );
	} else {
		write( "Unable to set primary domain.\n" );
	}
	return 1;
}


int help()
{
	write(
"Command: primary\n" +
"Syntax:  primary <domain>\n" +
"  If you are in more than one domain, the primary command will set\n" +
"the domain which finger, people, etc. tell everyone else you're in.\n" +
"  See also: domains\n" );
	return 1;
}


/* EOF */
