/* Now players can disguise themselves. When disguised, other players see
   only race. 31.1.1993 //Frobozz
/* Moved to /bin/pub 22-sep-94. //Doomdark
 */
varargs nomask status
disguise_cmd(string str, object me)
{
    int dl;
    if (!me && !(me = this_player())) return 0;
    if ((string)me->query_real_name() == "guest") return 0;
    if((int)me->query_disguised() > 1){
	me->tell_me("That is futile right now.");
	return 1;
    }
    if (!str) str = "toggle";
    switch (str) {
    case "on": dl = 1; break;
    case "off": dl = 0; break;
    case "toggle": dl = !((int)me->query_disguised()); break;
    default: return notify_fail(
	  "Disguise what? (\"disguise [on/off/toggle]\")\n"), 0;
    }
    me -> tell_me("Ok. You are "+({ "not disguised","disguised" })[dl]+".");
    me -> set_disguised(dl);
    return 1;
}
