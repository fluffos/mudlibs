/* _from.c
 * Command front-end to the from command
 *
 * Zak, 930413
 */

#include <mailer.h>
#include <mudlib.h>
#include <config.h>
inherit DAEMON;

int cmd_from(string arg)
{
    object ob;

    seteuid("TEMP");
    ob = new(MAILER);
    ob->move(this_player());
    return (int) ob->do_from(arg);
} // cmd_from


void help()
{
    write( @HELP
Usage: from [ new ]
	lists the contents your mailbox. With the optional 'new' arg,
	only new mail is listed
HELP
);
} // help
