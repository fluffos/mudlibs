// smith.c



inherit NPC;
inherit F_DEALER;

string ask_me();
int  do_stop(string arg);
int  do_gu(string arg);
int  do_dapi(string arg);
int  do_cuihuo(string arg);
int  do_repair(string arg);
void reward(object me);

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_gu", "gu");
	add_action("do_stop", "stop");
	add_action("do_dapi", "dapi");
	add_action("do_cuihuo", "cuihuo");
	add_action("do_repair", "repair");
	add_action("do_repair", "xiuli");
}

void setup()
{
	set("inquiry/工作",    (: ask_me :));
	set("inquiry/修理",   "你想要修(repair)点什么？");
	::setup();
}
string ask_me()
{
	object me;
 

	me = this_player();
	if (me->query("afk/file")=="datie")
		return "干活怎么尽偷懒？";

	if (me->query_temp("pending/afk")||me->query("afk"))
		return "你正忙着呢！";

	if (me->query("qi") < 20)
		return "我看你脸色不行啊，先歇会儿吧，我可不想工作出人命来。";

	if (! interactive(me))
		return "...";

	me->delete("afk");
	me->set("afk/file","datie");
	me->set("afk/room", environment(me));
	return "好，你就帮我打铁吧！工具都在这儿。";
}

/*
string ask_me()
{
	object me = this_player();

	if (me->is_busy())
		return "你先把手头儿的事儿忙完再说吧！";

	if (me->query("combat_exp") > 1500000)
		return "让您老干这个未免屈尊了吧？";

	if (me->query("qi") < 40)
		return "你还是歇会儿吧！要是出了人命我可承担不起。";

	if (me->query_temp("smith/gu"))
		return "让你"ZJURL("cmds:gu")+ZJSIZE(15)"【鼓】"NOR"风箱，你怎么还磨蹭(gu)？";

	if (me->query_temp("smith/dapi"))
		return "叫你打的坯你"ZJURL("cmds:dapi")+ZJSIZE(15)"【打】"NOR"了没有(dapi)？";

	if (me->query_temp("smith/cuihuo"))
		return "干活怎么尽偷懒？快给我"ZJURL("cmds:cuihuo")+ZJSIZE(15)"【淬火】"NOR"去(cuihuo)！";

	me->set_temp("pending/auto_tie",1);
	switch(random(3))
	{
	case 0:
		me->set_temp("smith/gu", 1);
//		if(me->query("zjvip/level")&&me->query_temp("pending/auto_tie"))
			tell_object(me,ZJFORCECMD("gu"));
		return "好！你帮我"ZJURL("cmds:gu")+ZJSIZE(15)"【鼓】"NOR"一会儿风箱(gu)。";

	case 1:
		me->set_temp("smith/dapi", 1);
//		if(me->query("zjvip/level")&&me->query_temp("pending/auto_tie"))
			tell_object(me,ZJFORCECMD("dapi"));
		return "这样吧，你帮我"ZJURL("cmds:dapi")+ZJSIZE(15)"【打】"NOR"一下坯吧(dapi)！";

	case 2:
		me->set_temp("smith/cuihuo", 1);
//		if(me->query("zjvip/level")&&me->query_temp("pending/auto_tie"))
			tell_object(me,ZJFORCECMD("cuihuo"));
		return "去帮我把这些刚出炉的"ZJURL("cmds:cuihuo")+ZJSIZE(15)"【淬】"NOR"一下火(cuihuo)。";
	}
}

int do_gu(string arg)
{
	object me = this_player();
	int skill_exp;
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");

	if (! me->query_temp("smith/gu"))
	{
		message_vision("$n刚偷偷的拉起鼓风机，鼓了几阵风。就听见$N对$n大喝道：滚开，乱搞什么。\n",this_object(), me);
		return 1;
	}

	message_vision("$n拉起鼓风机拼命鼓了起来，$N看了点了点头。\n",this_object(), me);
	skill_exp=me->query_int()/10 + random(2);
	me->improve_skill("force",skill_exp);
	write(HIG"你在<鼓风>中对<运气>有所领悟，\n[基本内功] 熟练度提升 +"+skill_exp+""NOR"\n");
	call_out("reward",5,me);
	me->start_busy(5);
	return 1;
}

int do_dapi(string arg)
{
	object me = this_player();
	int skill_exp;
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");

	if (! me->query_temp("smith/dapi"))
	{
		message_vision("$n拿起几块生铁，在手里掂了掂。就听见$N对$n大喝道：放下，乱搞什么。\n",this_object(), me);
		return 1;
	}

	message_vision("$n拿着锤子对刚出炉的火热的生铁用力敲打着，$N“嗯”了一声，看上去有些满意。\n",this_object(), me);
	skill_exp=me->query_int()/10 + random(2);
	me->improve_skill("unarmed",skill_exp);
	write(HIG"你在<打坯>中对<拳脚运用>所领悟，\n[基本拳脚] 熟练度提升 +"+skill_exp+""NOR"\n");
	call_out("reward",5,me);
	me->start_busy(5);
	return 1;
}

int do_cuihuo(string arg)
{
	object me = this_player();
	int skill_exp;
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");

	if (! me->query_temp("smith/cuihuo"))
	{
		message_vision("$n刚抄起一个打造好的坯子，就听见$N对$n大喝道：放下，别给我搞坏了。\n",this_object(), me);
		return 1;
	}

	message_vision("$N用铁钳抄起一块火红的坯子，伸进了水池，“哧”的一声轻烟四冒。\n",me);
	skill_exp=me->query_int()/10 + random(2);
	me->improve_skill("dodge",skill_exp);
	write(HIG"你在<淬火>中对<腾转挪移>所领悟，\n[基本轻功] 熟练度提升 +"+skill_exp+""NOR"\n");
	call_out("reward",5,me);
	me->start_busy(5);

	return 1;
}

void reward(object me)
{
	object coin;
	int exp_add;
	mixed *local;
	
	if (!me) return;
	me->delete_temp("smith/gu");
	me->delete_temp("smith/dapi");
	me->delete_temp("smith/cuihuo");

			     
      message_vision("$N对$n道：这是给你的工钱。\n",this_object(), me);
	
	if (me->query("combat_exp") < 1500000)
	{
      	exp_add= 10 + random(11);
		
		local = localtime(time());
		if (to_int(local[4])+1 == 5 && (local[3] >= 25) || to_int(local[4])+1 == 6 &&  local[3] <= 8 ) {
			exp_add *=2;
		}
		
		coin = new("/clone/money/coin");
		coin->set_amount(exp_add*3/2);
		coin->move(me);
//      	command("give coin to " + me->query("id"));
		write(HIG"你辛苦工作获得： 铜板：+"+exp_add*3/2+"  经验：+"+exp_add+"  阅历：+1\n"NOR);
		me->add("score", 1);//me->improve_potential(exp_add*2);
		me->add("combat_exp", exp_add);
	}
	me->receive_damage("qi", 25 + random(10));
	if(me->query_temp("pending/auto_tie"))
	{
		write(ZJEXIT"northwest:"RED"结束托管"NOR":stop\n");
		write(YEL"托管中，稍后继续工作。。。"NOR"\n");
		call_out("auto_ask",5,me);
	}
}

void auto_ask(object me)
{
	if(!me||!interactive(me)) return;
	if(me->is_busy()||me->query("qi") < 40)
		call_out("auto_ask",3,me);
	else if(present(me,environment(this_object())))
		tell_object(me,ZJFORCECMD("ask "+this_object()->query("id")+" about 工作"));
}

int do_stop(string arg)
{
	if(this_player()->query_temp("pending/auto_tie"))
	{
		write(YEL"结束托管。。。"NOR"\n");
		this_player()->delete_temp("pending/auto_tie");
	}
	return 1;
}
*/
int do_repair(string arg)
{
	object me;
	object ob;
	mixed  msg;
	int consistence;
	int cost;
	mapping repair;

	if (! arg)
		return 0;

	me = this_player();
	if (! objectp(ob = present(arg, me)))
		return notify_fail("你身上好像没有这样东西。\n");

	if (undefinedp(consistence = ob->query("consistence")))
		return notify_fail(ob->name() + "似乎不需要在这里修理吧？\n");

	if (consistence >= 100)
		return notify_fail(ob->name() + "现在完好无损，修理做什么？\n");

	if (! undefinedp(msg = ob->query("no_repair")))
	{
		if (stringp(msg))
			write(name() + "道：这我可修理不了。\n");
		else
			write(name() + "道：" + msg);
		return 1;
	}

	if (mapp(repair = me->query_temp("pending/repair")) && repair["item"] == ob)
	{
		if (me->is_busy())
			return notify_fail("你现在正忙着呢！\n");

		notify_fail("你先带够了钱再说。\n");
		if (MONEY_D->player_pay(me, repair["cost"]) != 1)
			return 0;

		message_vision("$n把" + ob->name() + "递给了$N。只见$N拿起工具，东敲西补，将" + ob->name() + "好修了修。\n", this_object(), me);
		ob->set("consistence", 100);
		message_vision("$N道：“好了！”随手把" + ob->name() + "了$n，$n看了看，满意的掏出了一些钱付了帐。\n", this_object(), me);
		me->start_busy(1 + random(100 - consistence) / 10);
		me->delete_temp("pending/repair");
		return 1;
	}

	cost = ob->query("magic/power")+ob->query("point")+ob->level_now(1)*30;
	if(cost<80) cost = 80;
	cost *= 1000;
	cost = (100 - consistence)*cost/100;

	msg = "$n拿出一" + ob->query("unit") + ob->name() + "，$N瞥了一眼，道：“要修好它得要" + MONEY_D->price_str(cost) + "才行。”\n";
	message_vision(msg, this_object(), me);	
	tell_object(me, YEL "你"ZJSIZE(20)+ZJURL("cmds:repair"+arg)"确定"NOR+YEL"想花费"+MONEY_D->price_str(cost)+"修理"+ob->name()+"吗？"NOR"\n");
	me->set_temp("pending/repair/item", ob);
	me->set_temp("pending/repair/cost", cost);
	return 1;
}