inherit ROOM;

void create()
{
	set("short", "中央广场");
	set("long", @LONG
这里是城市的正中心，一个很宽阔的广场。中央有一棵大榕树，据传已有千年的树龄，是这座城市的历史见证。树干底部有一个很大
的树洞。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "city");
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/tiaoz1" : 1,	
	]));
	set("item_desc", ([
		"【树洞】" : "这是一个黑不溜湫的大洞，里面不知道有些什么古怪。\n"
		ZJOBACTS2"钻洞:enter dong\n",
		"【公告】" :HIY"欢迎来到武动仙途！

1.公屏记得找个师傅哦！记住一定要加师傅QQ，不懂得话就一直问师傅，师傅会给你启动资金，和一些新手物资，记得谢谢师傅！
然后加群qq537803188，多在群里看看攻略，问问其他玩家。

2.刚进入游戏的你，或许会觉得难度很高，这是因为这个游戏有着超级高的自由度，只要你肯认真的研究，保证你会发现一个全新的武侠世界！！

3.离线挂机在哪？：离线挂机在【宝昌客栈】右边，记得在那里下线，上线时就能收集修为了。

4.记得加群（武动仙途）qq537803188"NOR"\n",
	//	 "雕像":HIR"血色染红了天空\n"HIY"这代表了无数武者渴望最强的执念。\n"HIM"然着，百日枯骨遍地生，曰知：“泉涸，日落，月不在，人从爱欲生忧，从忧生怖。若离於爱，何忧何怖 。此中来，相濡以沫，不如相忘于江湖，天下五绝，最强的信念！”"NOR"\n"ZJOBACTS2"查看雕像:lunsword\n",
		 "【悬赏】" : "这是悬赏公告栏，你可以在这里查看悬赏信息。\n"
					"可以花金子悬赏玩家，包括自己。\n" 
					"只有在线的玩家才可以被悬赏。\n" + 
					ZJOBACTS2 + "悬赏信息:look_board" + ZJSEP + "悬赏玩家:xuanshang\n",					
	]));

	set("exits", ([
		"northeast" : __DIR__"shengxiantang",
		"northwest" : __DIR__"banghui",
		"southeast" : "/d/migong/migong1",
		"east" : __DIR__"dongdajie1",
		"south" : __DIR__"nandajie1",
		"west" : __DIR__"xidajie1",
		"north" : __DIR__"beidajie1",
		"southwest" : __DIR__"lajichang",
		"up" : __DIR__"shiji",

	]));

	

	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_xuanshang", "xuanshang");
	add_action("do_look_board", "look_board");
	add_action("do_jiebang", "jiebang");
}

#define XUANSHANGD "/adm/daemons/xuanshangd"
#define ORDER "/clone/xuanshang/xuanshang_order"

int do_xuanshang(string arg)
{
	object who = this_player();
	object target;
	int amount;

	if (arg == "" || !arg)
	{
		tell_object(who, INPUTTXT("你要悬赏谁？(输入ID)", "xuanshang $txt#") + "\n");
		return 1;
	}

	if (sscanf(arg, "%s %d", arg, amount) != 2)
	{
		target = find_player(arg);
		if (!target || !userp(target))
		{
			tell_object(who, "这个人目前不在江湖之中。\n");
			return 1;
		}
		else
		{
			tell_object(who, INPUTTXT("你目前有" + (who->query("balance") / 10000) + "两黄金存款，你要悬赏" + target->query("name") + "多少金子?", "xuanshang " + arg + " $txt#") + "\n");
			return 1;
		}
	}
	else
	{
		if (amount <= 0)
		{
			tell_object(who, "请输入大于零的数。\n");
			return 1;
		}

		if (who->query("balance") < amount * 10000)
		{
			tell_object(who, "你的存款不足" + amount + "两黄金。\n");
			return 1;
		}

		target = find_player(arg);
		if (!target || !userp(target))
		{
			tell_object(who, "这个人目前不在江湖之中。\n");
			return 1;
		}
		else
		{
			who->add("balance", -amount * 10000);
			if (XUANSHANGD->add_xuanshang(target->query("id"), amount))
			{
				log_file("xuanshang/pay", ctime(time()) + who->query("name") + "(" + who->query("id") + ")花费" + amount + "金子悬赏" + target->query("name") + 
					"(" + target->query("id") + ")，目前总计" + XUANSHANGD->get_xuanshang()[target->query("id")][1] + "黄金。\n");
				tell_object(who, "你花费" + amount + "金子悬赏" + target->query("name") + "。\n");
				return 1;
			}
			else
			{
				tell_object(who, "悬赏出错，请联系管理员处理。\n");
				return 1;
			}

			return 1;
		}
	}

	return 1;
}

int do_look_board(string arg)
{
	object who = this_player();
	string temp;
	string str = "";
	mapping xuanshang;

	if (!sizeof(xuanshang = XUANSHANGD->get_xuanshang()))
	{
		tell_object(who, "目前江湖中没有被悬赏的人。\n");
		return 1;
	}

	foreach (temp in keys(xuanshang))
	{
		str += xuanshang[temp][0] + "(" + xuanshang[temp][1] + ")" + ":jiebang " + temp + ZJSEP;
	}

	if (str == "")
		tell_object(who, ZJOBLONG + "目前江湖中没有被悬赏的人。\n");
	else
		tell_object(who, ZJOBLONG + "目前江湖中被悬赏的人有：\n" + ZJOBACTS2 + str + "\n");

	return 1;
}

int do_jiebang(string arg)
{
	object who = this_player();

	string id;
	string sign;
	object order;
	mapping xuanshang;

	xuanshang = XUANSHANGD->get_xuanshang();
	
	if (sscanf(arg, "%s %s", id, sign) != 2)
	{
		if (undefinedp(xuanshang[arg]))
		{
			tell_object("目前没有这个悬赏令啊。\n");
			return 1;
		}

		tell_object(who, ZJOBLONG + "你要揭下" + xuanshang[arg][0] + "的悬赏令吗？\n" + ZJOBACTS2 + "确定:jiebang " + arg + " y\n");
		return 1;
	}
	else
	{
		if (sign != "y")
		{
			tell_object(who, "输入参数错误，请重新输入。\n");
			return 1;
		}

		if (undefinedp(xuanshang[id]))
		{
			tell_object("目前没有这个悬赏令啊。\n");
			return 1;
		}

		if (present(id + "-order", who))
		{
			tell_object(who, "你的身上已经有这个悬赏令了。\n");
			return 1;
		}

		if (!objectp(order = new(ORDER)))
		{
			tell_object(who, "出错，请联系管理员处理。\n");
			return 1;
		}

		order->set("xuanshang_id", id);
		order->set("xuanshang_name", xuanshang[id][0]);
		order->set_name(xuanshang[id][0] + "悬赏令", ({ id + "-order" }));
		order->move(who);
		tell_object(who, "你揭下了" + xuanshang[id][0] + "的悬赏令。\n");

		return 1;
	}
}

int do_enter(string arg)
{
	object me;
	me = this_player();

	if (! arg || arg == "")
		return 0;

	if (arg == "dong")
	{
		if (me->is_busy())
			return notify_fail("你的动作还没有完成，不能移动。\n");

		message("vision",
			me->name() + "一弯腰往洞里走了进去。\n",
			environment(me), ({me}) );
		me->move("/d/gaibang/inhole");
		message("vision",
			me->name() + "从洞里走了进来。\n",
			environment(me), ({me}) );
		return 1;
	}
}       
