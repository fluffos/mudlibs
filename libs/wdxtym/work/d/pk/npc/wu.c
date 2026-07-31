// wulaoda.c

inherit NPC;

string ask_me();
int ask_duihuan();

mapping list = ([
	"/clone/pkd/tianfu2" : 100,
	"/clone/pkd/tianxiang" : 100,
	"/clone/pkd/putao3" : 25,
]);

void create()
{
	set_name("乌老大", ({ "wu laoda", "wu" }));
	set("gender", "男性");
	set("age", 47);

	set("inquiry", ([
		"屠人大赛" : (: ask_me :),
		"点券道具" : (: ask_duihuan :),
		"入场规则" : ("没比赛时，进场需要5灵石的入场费"),
	]));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_sign", "sign");
	add_action("do_join", "join");
	add_action("do_duihuan", "duihuan");
}

void unconcious()
{
	die();
}

void die()
{
	message_vision("$N打了个喷嚏，随即恢复正常。\n", this_object());
}

int ask_duihuan()
{
	int i;
	string str,*items;
	object me = this_player();

	str = ZJOBLONG"你目前可用的兑换点券还有"+me->query("pkd_pot")+"点，请选择兑换物品：\n"ZJOBACTS2+ZJMENUF(3,3,9,30);
	items = keys(list);
	for(i=0;i<sizeof(items);i++)
	{
		str += items[i]->query("name")+ZJBR"兑换点："+list[items[i]]+":duihuan "+items[i]+ZJSEP;
	}
	tell_object(me,str+"\n");
	return 1;
}

int do_duihuan(string arg)
{
	int i,num;
	string str,*items;
	object ob,me = this_player();

	if(!arg)
	{
		tell_object(me,"你要兑换什么物品？\n");
		return 1;
	}

	if(sscanf(arg,"%d %s",num,arg)!=2)
	{
		if(arg->query_amount())
		{
			tell_object(me,INPUTTXT("你想兑换多少"+arg->query("name")+"？","duihuan $txt# "+arg+"\n"));
			return 1;
		}
		num = 1;
	}

	if(!list[arg])
	{
		tell_object(me,"你要兑换什么物品？\n");
		return 1;
	}

	if(!me->query("pkd_pot")||me->query("pkd_pot")<list[arg]*num)
	{
		tell_object(me,"你的兑换点不足！！\n");
		return 1;
	}

	me->add("pkd_pot",-list[arg]*num);
	ob = new(arg);
	if(ob->query_amount())
		ob->set_amount(num);
	ob->move(me);
	me->save();
	tell_object(me,"你从乌老大那里兑换了一"+ob->query("unit")+ob->query("name")+"。\n");
	return 1;
}

string ask_me()
{
	object me;

	me = this_player();
	if (PK_D->is_pking())
		return "现在屠人大赛正在举行呢，你想干什么？";

	if (PK_D->is_ready())
		return "很好，现在屠人大赛正要开始，你要报名么(sign)？";

	return "屠人大赛？你慢慢等着吧，还没到开始时间呢。";
}

int do_join()
{
	
	object me;
	me = this_player();
	
	//if(!wizardp(this_player()))
	//return notify_fail("近期非比赛时间场地暂时不开放。”\n");

	if (PK_D->is_pking())
		return notify_fail("乌老大眼睛一弹，喝道：“现在里面正比赛呢，你这些人等等吧。”\n");

	if (PK_D->is_ready())
		return notify_fail("乌老大懒懒道：“要想正式比赛就进去，其他人先等着。”\n");

	message_vision("$N赔笑对$n道：“我进去溜达溜达，放行可好？”\n",this_player(), this_object());

	 if(me->query("yuanbao") < 5)
		{
		return notify_fail("乌老大懒懒道：“要想进去，要交5灵石当入场费。”\n");
		}
	 
	if (PK_D->join_competition(this_player()))
	{
		
		me->add("yuanbao",-5);
		message("vision", this_player()->name() + "一溜小跑进了屠人场。\n",
			environment());
		return 1;
	}

	return 0;
}

int do_sign()
{
	object me;
	string msg;
	object ob;

	me = this_player();
	message_vision("$N陪着笑脸对$n道：“您好，您好，我也来签个到。”\n",me, this_object());
	if (me->query("combat_exp") < 1000)
	{
		message_vision("$n抬头看了看$N，不屑道：“就你这点本事？只好参加被屠大赛！”\n",me, this_object());
		return 1;
	}

	if (stringp(msg = PK_D->reject_join(me)))
	{
		command("say " + msg);
		return 1;
	}

	foreach (ob in deep_inventory(me))
		if (ob->is_character())
		{
			command("say 你背的谁？去比赛还拖家带口的？快给我滚！");
			message_vision("$N飞起一脚，把$n踢倒在地！\n",this_object(), me);
			me->receive_damage("qi", 50);
			return 1;
		}

	message_vision("$n点点头，对$N道：“好吧，你先进去准备吧。”\n$N点点头，向北面的准备室走去。\n", me, this_object());
	me->move("/d/pk/ready");
	message("vision", me->name() + "精神抖擞的走了进来。\n",environment(me), ({ me }));
	return 1;
}

