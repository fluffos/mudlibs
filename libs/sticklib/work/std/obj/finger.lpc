/*
 * Mortal finger. Uses /bin/daemons/fingerd.
 */
#include <treasure.h>

#include <daemons.h>

void init() {
    if(environment(this_player()) == environment(this_object()))
	add_action("finger_cmd", "finger");
}

void
create_treasure()
{
    set_name("finger tool");
    set_short("A magical finger");
    set_long(
      "You can point the finger to any players, present or not: 'finger <player>'"
    );
    set_id( ({ "finger", "magical finger" }) );
}

/* Can't be taken */
int get() { return 0; }


int finger_cmd(string str) {
    //    string tmp;
    if (!str) {
	notify_fail("Finger who?\n");
	return 0;
    }
    if (!FINGER_D->show_mortal(str, this_player())) {
	write("No such player.\n");
    }
    /* Finger daemon now handles this.
	tmp = (string)MAIL_D->query_mail(str);
	if( tmp && (strstr(tmp, "NEW") != -1) )
	  this_player()->tell_me("There is unread mail.");
	else
	  this_player()->tell_me("No unread mail.");
    */
    /*
	if (PATH_USER "cigam/post/post"->query_mail(str))
	  this_player()->tell_me("There is unread mail.");
    */
    return 1;
}
