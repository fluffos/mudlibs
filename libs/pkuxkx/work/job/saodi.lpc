//job of vworld
//Made by jason@indeed for vworld
//2001.2.26

inherit F_QUEST;

void create()
{
	set_name("清洁工",({"qingjie gong","worker"}));
	set("class","noneclass");//NPC的职业，对于普通的job,这
				//个设置为"noneclass"
	set("rewards",([//奖励的点数。
	"balance":100,
	"combat_exp":50,
	]));
	set("job_name","扫地");
	set("job_time",200);
	//set("quest_city",({"vcity","pku","zhgcun","tsinghua"}));
	setup();
}

void init()
{	
	object ob;
	
	if( interactive(ob = this_player())  ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	::init();
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	
	command( "say 这位" + RANK_D->query_respect(ob)
		+ "，我们正在争创世界卫生城市，来我这里帮帮忙(askjob)吧。");
	
}

string quest(object me)
{
	if(me->is_busy())
	{
		message("vision","你正忙着呢！\n",me);
		return "";
	}
	message_vision("$N用力的清扫着地面！！\n",me);
	me->add_temp("saodicishu",1);
	if(random(20)==2)
	{
		message_vision("$N突然发现地上有张皱巴巴的纸币，赶快拣了起来！\n"
		+"哇!赚大了耶！！\n",me);
		me->add("money",1000);
	}
	me->start_busy(1);
	if(me->query_temp("saodicishu")>9)
	{
		message("vision","你的任务完成了！\n",me);
		me->set_temp("quest/quest_done",1);
		me->delete_temp("saodicishu");
		return "quest_done";
	}
	else
		return "";
}


