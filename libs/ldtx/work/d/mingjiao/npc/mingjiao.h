// MingJiao.h for all npc of mingjiao

void greeting(object me, object ob)
{
	mapping party;

	if ( environment(ob) != environment(me) ) return;
	if ( !mapp(party = ob->query("party")) ) return;
	if ( party["party_name"] == HIG "明教" NOR )
	{
	if ( party["level"] < me->query("level"))
		message_vision("$N对$n躬身行礼，说道："+me->query("title")+me->query("name")
			+"，参见"+party["rank"]+ob->query("name")+"！\n", me, ob );
	}

}
