// New standard "show"-command. With this players (and npcs too)
// can show an item to other players or npcs.
//
// Version 1.0 01-jun-95 by Doomdark
//
// This command calls function "catch_show" in player/npc to whom
// the object is shown, with 2 arguments:
// 1st: Object pointer of the player/npc who shows the object and
// 2nd: Object that is being shown. Ie:
//	"living_item_is_showed_to -> catch_show(who_shows, what_shows);"
//
// 12-30-97  Kieve -- Remove the check for showing yourself. Yes, some people
//                    Want to show things to themself.
//                    Added a catch_show() call to the object being shown.

#include <cmd.h>

varargs nomask status
show_cmd(string str, object me)
{
    string item, showed, s, s2;
    object item_ob, showed_ob;
    if (!me && !(me = this_player())) return 0;

    if (!str) return notify_fail("Show what to whom?\n"), 0;
    if (!me -> query_can_move() || me -> test_dark()) return 0;
    if (me -> query_rest()) {
	me -> tell_me(TOO_RELAXED);
	return 1;
    }

    if (sscanf(str, "%s%tto%t%s", item, showed) < 2) return
	notify_fail("Show what to whom?\n"), 0;

    // Let's remove "the"s in case someone uses them...

    if (sscanf(item, "the%t%s", s)) item = s;
    if (sscanf(showed, "the%t%s", s)) showed = s;

    showed = lower_case(showed);

    if (!(item_ob = present(item, me))) {
	me -> tell_me("You don't have any \""+item+"\".");
	return 1;
    }

    if (!(showed_ob = present(showed, environment(me)))) {
	me -> tell_me("You don't see any \""+showed+"\" here.");
	return 1;
    }

    if (!living(showed_ob)) {
	me -> tell_me("Sure. How did you think you could show\
 anything to it?!?");
	return 1;
    }

    s = (string) me -> query_name(0, showed_ob);
    s2 = (string) showed_ob -> query_name(0, me);
    item = (string) item_ob -> query_name();
    if (!item) item = "something";

    showed_ob -> tell_me(sprintf("%s shows the %s to you.", s, item));
    environment(me) -> tell_here(sprintf("%s shows the %s to %s.",
	s, item, s2), ({ me, showed_ob }));
    me -> tell_me(sprintf("Ok, you show the %s to %s.", item, s2));

    // Call the event function!
    // If it returns 1, we won't print anything... Otherwise let's tell
    // player that person item was shown to wasn't too interested in it.
    // But only if it's npc we were showing it to.

    if (!showed_ob -> catch_show(me, item_ob) && !interactive(showed_ob)) {
	me -> tell_me("...but "+(string)showed_ob->Pronoun()+
	  " doesn't seem to be too interested in it...");
    }
    item_ob->catch_show(me, showed_ob);

    return 1;
}
