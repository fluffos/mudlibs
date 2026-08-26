/* _mail.c
 * Command front-end to my mailer front-end!
 *
 * Huthar (5/8/92)
*/

#include <mailer.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_mail(string arg) {
    object ob;

if (arg && strsrch(arg,"@") != -1 ) {
  write("Intermud mail is not yet supported with the current I3 protocol\n");
   return 1;
  }
    seteuid("TEMP");

    ob = new(MAILER);
    if( ob -> move( this_player() ) ) {
	printf( "You can't seem to get your hands on the mailer.\n"
	  "Report this to an Admin.\n" );
	ob -> remove();
    }
    else

	ob->start_mail(arg);
    return 1;
}

void help() {
    this_player()->more(MAILER_LONG);
}
