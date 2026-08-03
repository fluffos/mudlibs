void init()
{
	object me = this_player();

	if (userp(me) && !wizardp(me))
		add_temp("num", 1);
	add_action("do_action", ({"dazuo", "tuna", "lian", "learn", "du", "steal", "hit",
		"kill", "fight", "study", "practice","exercise", "exert" }));
}

void reset()
{
	int i, j = 0;
	object *ob = all_inventory();

	i = sizeof(ob);
	while (i--)
		if (userp(ob[i]) && !wizardp(ob[i])) j++;
	set_temp("num", j);
	::reset();
}
