#define QUEST_SHA "/quest/quest1/quest"

int time_period(int timep, object me);

void init()
{
	add_action("give_quest", "quest");
	
}

int give_quest()
{
	mapping quest ;
	object me,letter,ob;
	int combatexp, timep, factor;
	me = this_player();
	ob = this_object();
	
	combatexp = (int)(me->query("combat_exp"));
	
	if(combatexp < 100000)
{
	message_vision("$N对$n说：这位"+ RANK_D->query_respect(me)+"怎么好象很面生呀？\n",ob,me);
	return 0;
}

	if(combatexp > 10000000)
{
	message_vision("$N对$n说：您已是武林高手了，这种小事怎敢劳您大驾？！\n",ob,me);
	return 0;
}
 
	if((quest =  me->query("quest"))){
		if( ((int)me->query("task_time")) >  time() ){
		message_vision("$N对$n说： 你得把信帮我送到呀。\n",ob,me);
		return 0;
		}
	}
	if (((int)time() - (int)me->query("last_task_time")) < 1){
	message_vision("$N对$n说：现在还没有信件要送，你还是等会再来吧。\n",ob,me);
	return 0;
}
	else
		{
	message_vision("$N对$n说：你来得正好，我刚好有一封紧急信件要送出去。\n",ob,me);
}
	quest = QUEST_SHA->query_quest();
	timep = random(100) + 50;
	time_period(timep, me);

	tell_object(me,"把信送给『" + quest["quest"] + "』你的任务就完成了。\n"NOR);
	message_vision("$N给了$n一封信。\n",ob,me);
	letter = new("/include/job/obj/letter");
	letter->move(me);
	quest["quest_type"] = "把信送给";
	quest["exp_bonus"] = random(20) + 50;
	quest["pot_bonus"] = random(200) + 20;
	quest["score"] = 0;

	me->set("quest", quest);
	me->set("task_time", (int)time() + timep);
	me->set("quest_factor", factor);
	me->set("last_task_time", time());
	return 1;
}

int time_period(int timep, object me)
{
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;			 t /= 60;
	m = t % 60;			 t /= 60;
	h = t % 24;			 t /= 24;
	d = t;

	if(d)
	time = chinese_number(d) + "天";
	else
	time = "";
	if(h)
	time += chinese_number(h) + "小时";
	if(m)
	time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";

	tell_object(me, HIW+this_object()->name() +"说道：\n在" + time + "内");

	return 1;
}

