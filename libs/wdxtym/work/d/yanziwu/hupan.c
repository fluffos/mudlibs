// Room: /d/yanziwu/hupan.c
inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
	 set("short", "太湖湖畔");
	 set("long", @LONG
太湖(hu)处江浙之间。她襟带三江，东南之水尽汇于此，周行五百
里，古称五湖。矗立湖岸，唯见长天远波，放眼皆碧，七十二峰苍翠挺
立在三万六千顷波涛之中，使人心襟大开，直欲仰天长啸，方能表此喜
乐。
LONG );
	set("exits", ([
		"northeast" : "/d/suzhou/road5",
		"north" : __DIR__"jingji/enter",
	]));

	set("item_desc", ([
		"【太湖】":"近湖畔处有一叶小舟，舟上一个绿衫姑娘正在戏水。喊(yell)一声试试吧。\n"
			ZJOBACTS2+ZJMENUF(3,3,9,30)+"叫船:yell boat"ZJSEP"一苇渡江:cross\n",
	]));

	set("resource/fish", ({ "/clone/fish/liyu",
				"/clone/fish/jiyu",
				"/clone/fish/qingyu",
				"/clone/fish/caoyu", }));

	set("outdoors", "yanziwu");
	setup();
}

void init()
{
	add_action("do_yell", "yell");
	add_action("do_cross", "cross");
}

void check_trigger()
{
	object room;

	if (! query("exits/enter"))
	{
		if (!(room = find_object(__DIR__"xiaozhou")))
			room = load_object(__DIR__"xiaozhou");
		if (room = find_object(__DIR__"xiaozhou"))
		{
			if ((int)room->query("yell_trigger") == 0)
			{
				room->set("yell_trigger", 1);
				set("exits/enter", __DIR__"xiaozhou");
				room->set("exits/out", __FILE__);
				message("vision", "一尾小舟缓缓地驶了过来，一个采"
					"莲少女招手让你登舟。\n", this_object() );
				remove_call_out("on_board");
				call_out("on_board", 15);
			} else
				message("vision", "只听得湖面上隐隐传来：“就"
					"来了啦……”\n", this_object());
		} else
			message("vision", "ERROR: boat not found\n", this_object());
	} else 
		message("vision", "湖畔一尾小舟上一个绿衫少女细声说到：侬"
			"有啥事体。\n", this_object());
}

void on_board()
{
	object room;

	if (! query("exits/enter")) return;

	message("vision", "少女竹篙一点，小舟离岸向湖心滑去。\n",
		this_object());

	if (room = find_object(__DIR__"xiaozhou"))
	{
		room->delete("exits/out");
		message("vision",
"\n少女说了一声“坐稳喽”，声音极甜极清，令人一听之下，说不出的舒
适。然后竹篙一点，扁舟向湖心滑去。\n", room);
	}
	delete("exits/enter");

	remove_call_out("arrive");
	call_out("arrive", 20);
}

void arrive()
{
	object room;
	if (room = find_object(__DIR__"xiaozhou"))
	{
		room->set("exits/out", __DIR__"muti");
message("vision","少女说: “到啦，上岸吧。”，随即一点竹篙，把舟泊好。\n",room);
	}
	remove_call_out("close_passage");
	call_out("close_passage", 20);
}

void close_passage()
{
	object room;
	if (room = find_object(__DIR__"xiaozhou"))
	{
		room->delete("exits/out");
		message("vision","少女竹篙一点，撑了小舟到湖中采莲戏水。\n", room);
		room->delete("yell_trigger"); 
	}
}

int do_yell(string arg)
{
	string dir;

	if (! arg || arg == "" )
		return notify_fail("你要喊什么？\n");

	if (arg == "boat" || arg == "girl") arg = "姑娘";
	if ((int) this_player()->query("age") < 16)
		message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",
			       this_player());
	else
	if ((int)this_player()->query("neili") > 500)
		message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传"
			       "了出去。\n", this_player());
	else
		message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",
			       this_player());
	if (arg == "姑娘")
	{
		check_trigger();
		return 1;
	} else
		message_vision("湖面上远远传来一阵回声：“" + arg +
			       "～～～”\n",this_player());
	return 1;
}


int do_cross()
{
	object me;

	me = this_player();
	if (me->query_skill("dodge") < 100)
	{
		tell_object(me, random(2) ? "你觉得湖面太宽，没有十足的把握跃过去。\n"
					  : "你看着浩瀚的太湖，心里不禁打了个突，没敢乱来。\n");
		return 1;
	}

	if (me->query("neili") < 100)
	{
		tell_object(me, "你的内力不够，还是休息一下再说吧。\n");
		return 1;
	}

	me->add("neili", -50);
	message_vision("$N身形一晃，已然跃进太湖，只见$P脚踏清波，渐渐远去。\n", me);
	tell_object(me, "你顺利的到达了彼岸！\n");
	me->move(__DIR__"bozhou");
	return 1;
}

void reset()
{
	object room;

	::reset();
	if (room = find_object(__DIR__"xiaozhou"))
		room->delete("yell_trigger"); 
}

