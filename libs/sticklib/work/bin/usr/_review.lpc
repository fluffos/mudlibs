#include <cmd.h>

nomask status
review_cmd(string s) {

    object ob;
    string who;

    if (!CHECK) return 0;

    if (!s || s == "me" || s == "myself")
	ob = this_player();
    else if (s == "here" || s == "this room")
	ob = environment(this_player());
    else if (environment(this_player()))
	ob = present(s, environment(this_player()));
    if (!ob) ob = find_player(s);
    if (!ob) ob = find_living(s);

    if (!ob) this_player() -> tell_me(
	  "Can't find any player or monster named '"+s+"'.\n");
    else {
	if (!who && (who = (string) ob -> query_real_name()))
	    who = capitalize(who);
	if (!who) who = s;
	if (interactive(ob)) who = "player " + who;
	this_player() -> tell_me(
	  "Moving messages for " + who + ":\n"
	  +"mout:\t" + (string) ob -> query_move_msg("mout")
	  +"\nmin:\t" + (string) ob -> query_move_msg("min")
	  +"\nmmout:\t" + (string) ob -> query_move_msg("mmout")
	  +"\nmmin:\t" + (string) ob -> query_move_msg("mmin")
	  +"\n");
    }
    return 1;
}
