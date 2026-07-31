void init()
{
	if (userp(this_player()) && !wizardp(this_player()))
		 add_temp("num", 1);
     	add_action("do_action", ({"dazuo", "tuna", "lian", "learn", "du", "steal", "hit",
                             "kill", "fight", "study", "practice","exercise", "exert",
                             "emote", "ask", "tell", "reply", "mm", "shout" }));
}

void reset()
{
	int i, j = 0;
	object *ob = all_inventory(this_object());
	i = sizeof(ob);
	while (i--) if(userp(ob[i]) && !wizardp(ob[i])) j++;
	set_temp("num", j);
	::reset();
}