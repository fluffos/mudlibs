/* Command 'ask' to be used in rooms etc.
 * like: 'ask old man about the quest' etc.
 */

varargs public status
ask_cmd(string str, object me)
{
    int i;
    string whom, what, s, me2;
    object whom2;
    if (!me && !(me = this_player())) return 0;
    if (str && sscanf(str, "the %s", s)) str = s;
    if (!str || sscanf(lower_case(str),"%s about %s", whom, what) < 2)
	return notify_fail( "Ask what? (usage is: 'ask <someone> about <something>')\n"), 0;
    if (!(whom2 = present(whom, environment(me)))) {
	me->tell_me("You can't see any \""+whom+"\" here.");
	return 1;
    }
    if (!living(whom2)) {
	me -> tell_me("Huh? Well, "+whom+" doesn't answer...");
	return 1;
    }
    if (sscanf(what, "the %s", s)) what = s;
    whom = (string) whom2 -> query_name(0, me);
    me2 = (string) me -> query_name(0, whom2);
    me -> tell_me("You ask "+whom+" about "+what+".");
    whom2 -> tell_me(me2+" asks you about "+what+".");
    environment(me) -> tell_here(me2+" asks "+whom+" about something.",
      ({ whom2, me }));
    if (!interactive(whom2))
	/* Let's check if NPC is interested in this question... */
	if (!whom2 -> catch_ask (this_player(), what))
	    me -> tell_me(whom + " doesn't answer.");
	/* Give this answer npc returned 0 (or no such function). */
    return 1;
}
