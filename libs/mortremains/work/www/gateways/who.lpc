/*    /www/gateways/who.c
 *    handles dynamic World Wide Web data
 *    It uses do_who() in the who command to get a string output.
 *    If your who command doesn't do this, check the /xtra/_who.c from Tmi
 *    which I converted to do just that. You might have to add CMD_WHO
 *    in your commands.h. It also uses the mudinfo command, also included
 *    in /xtra if you don't already have it.
 *    940606 Leto@Earth
 *    940615 Pallando@TMI-2 improved the efficiency
 */

#include <mudlib.h>
#include <config.h>
#include <daemons.h>
#include <commands.h>

inherit DAEMON;


string gateway( string args )
{
    return sprintf( @EndFormat
<HTML>
<HEAD>
<TITLE>%s Who Gateway</TITLE>
</HEAD>
<BODY>
<H1>%s Who Gateway</H1>
<LISTING>%s%s%s</LISTING>
</BODY>
</HTML>
EndFormat
        , capitalize( mud_name() ),
	capitalize( mud_name() ),
	(string)CMD_WHO-> do_who(),
	(string)CMD_MUDINFO-> do_info(),
"______________________________________________________________________________"
    );
}
