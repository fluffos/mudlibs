/****************************************************************
*								*
* Module:							*
*	/bin/pub/_fill.c					*
* Description:							*
*	The standard "fill"-command for StickLib. As this was	*
*	a specialized command in stickmud, it's still somewhat	*
*	kludgy... Should actually be rewritten.			*
* Version:							*
*	1.0a (for StickLib), Sep-98				*
* Last update:							*
*	05-Sep-98 by Doomdark					*
*								'
* Modifications:						*
*								*
****************************************************************/

#include <cmd.h>

#include <invis_levels.h>

nomask status
fill_cmd(string s, object me)
{
    int i;
    object ob, here;
    string what, with_what;

    if (!me && !(me = this_player()))
	return 0;
    if (me->test_dark() || !me->query_can_move())
	return 0;
    if(!s)
	return notify_fail("Fill what (and perhaps, with what?)?\n"),0;

    if (sscanf(s, "%s%twith%t%s", what, with_what) < 2) {
	with_what = 0;
	what = s;
    }
    ob = present4(what, me, me, IL_VISIBLE);

    /* The generic case is the one in which we just notify the object
     * about the player trying to fill it:
     */
    // Hmmh. However, we may have to give the surrounding room a chance
    // too, if the object 'fails' to catch the event. :-/
    if (ob) {
	if (i =  (int) ob->fill_cmd(what, me, with_what))
	    return i;
	if (i =  (int) environment(me)->fill_cmd(ob, me, with_what))
	    return i;
	if (with_what)
	    notify_fail(sprintf("You are not quite sure how to fill\
 %s with %s...\n", what, with_what));
	else
	    notify_fail(sprintf("You are not quite sure how to fill\
 %s.\n", what));
	return 0;
    }

    /* However, there may be some special cases... If so, we'll let the
     * surrounding room (try to) take care of that...
     */
    notify_fail(sprintf("You don't have any %s to fill.\n", what));
    return (int) environment(me)->fill_cmd(what, me, with_what);
}
