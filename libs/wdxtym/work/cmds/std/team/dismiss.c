// team command: dismiss

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object *t;
	object ob;

	if (! pointerp(t = me->query_team()))
		return notify_fail("你现在并没有参加任何队伍。\n");

	if (me->is_team_leader())
	{
		if(arg&&objectp(ob=find_player(arg)))
		{
			ob->dismiss_team();
			message("team", me->name(1) + "将"+ob->query("name")+"踢出队伍。\n", t, me);
			return 1;
		}
		message("team", me->name(1) + "将队伍解散了。\n", t, me);
		write("你将队伍解散了。\n");
	} else
	{
		message("team", me->name(1) + "决定脱离队伍。\n", t, me);
		write("你脱离了你的队伍。\n");
	}

	me->dismiss_team();
	return 1;
}
