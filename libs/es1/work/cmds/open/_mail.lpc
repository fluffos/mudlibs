//#pragma save_binary
/* _mail.c
 * Command front-end to my mailer front-end!
 *
 * Huthar (5/8/92)
*/

#include <mailer.h>
#include <mudlib.h>

inherit DAEMON;

int cmd_mail(string arg)
{
   object ob;

   seteuid("TEMP");

   ob = new(MAILER);
   ob->move(this_player());

   ob->start_mail(arg);
   return 1;
}

void help()
{
    this_player()->more(MAILER_LONG);
}
