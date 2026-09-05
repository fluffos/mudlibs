//任务NPC的示范模板和说明
//Made by jason@indeed
//2001.2.26

inherit F_QUEST;

void create()
{
	set_name("虚拟",({"xu ni","faint"}));//NPC的名字
	set("class","business");//NPC的职业，对于普通的job,这
				//个设置为"无业游民"
	set("rewards",([
		"money":900+random(400),
		"mor":5+random(3),
	]));
	set("quest_room",({"/d/start/timespace",}));
	//本任务NPC指定的任务地点
	//还可以指定所在城市：set("quest_city",({"nanjing","pku","tsinghua",}));
	//系统就只在所指定的城市搜索
	//set("permit_character",({"street",}));
	//特定的场所，这里是大街，还可能是farmer...
	//目前系统中地图多数没有加上这个属性。
	set("job_name","叫卖");//工作的名字
	set("job_time",100);//任务限定完成的时间
	setup();
}

//quest 函数，inherit "/feature/newquest"的 NPC都
//要有这个函数，用来给出具体的quest内容，要求是string
//类型，完全完成后return "quest_done",否则return ""
//尽量不要使用call_out!!!
//推荐只使用这个函数启动 quest,其他的交给新的物件
//上的函数来解决。尽早return "quest_done";

void init()
{
	::init();// 执行F_QUEST的init()
}
string quest(object me)
{
	message_vision("$N大声的叫卖着！！\n",me);
	me->add_temp("jiaomaicishu",1);
	if(me->query_temp("jiaomaicishu")>9)
	{
		message("vision","你的任务完成了！\n",me);
		me->set_temp("quest/quest_done",1);
		me->delete_temp("jiaomaicishu");
		return "quest_done";
	}
	else
		return "";
}


