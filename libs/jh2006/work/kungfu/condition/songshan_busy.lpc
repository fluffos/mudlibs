// songshan_job.c for both player and npc.

void do_back(object me)
{
	if(!me) return;
	me->delete_temp("songshan_job");
	me->delete_temp("last_lost_to");
	me->set("chat_chance", me->query("chat_c"));
	me->delete("chat_c");
	if(!me->query_temp("location"))
		me->delete("location");
	me->delete_temp("location");
	tell_room(environment(me), me->name() + "哼了一声："+RANK_D->query_self_rude(me)+"不耐烦了！\n", me);
	me->set_leader(0);
	me->reincarnate(); 
	if (!me->return_home())
		destruct(me);
}

int update_condition(object me, int duration)
{
	object player;
	
	if (duration < 2) {
		 if(!userp(me)) do_back(me);
		 return 0;
	}

	me->apply_condition("songshan_busy", duration - 1);

	if(!userp(me) && living(me)){
		if(!objectp(player = me->query_temp("songshan_job")))
		{
			do_back(me);
			return 0;
		}
		if(environment(player) == environment(me))
			return 1;
		tell_room(environment(me) , me->name() + "咦了一声："+player->name()+"跑哪去了？说完便急急忙忙地离开了。\n");
		if (me->move(environment(player)))
			tell_room(environment(me) , me->name() + "急急忙忙地走了过来。\n");
		else destruct(me);
	}
	return 1;
}

string query_type(object me)
{
	return "job";
}
