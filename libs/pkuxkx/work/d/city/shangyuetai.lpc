// Room: /d/city/shangyuetai.c
// By Eric 97.9.15

#include <ansi.h>
inherit ROOM;

void init();
//int do_tap();
//int do_sit();
//int do_jump();
//void delete_served();

void create()
{
	set("short","赏月台");
	set("long", @LONG
当头一轮明月(moon)，月光如水一样洒下来，月亮好大好圆的，映照着月下
的人们婆娑的影子。周围多是成对成双的人们在赏月，偶尔也可以听到情侣们在
喁喁私语着。这里是赏月的地方，台上整整齐齐地摆着些桌子(table)和椅子(chair)，
四周是制作精巧的雕花栏杆(rail)，只见人头涌动，热闹非凡。再向上是新手学
堂，有一些初入江湖的人儿在那里。
LONG);

	set("exits", ([
		// "up" : "/d/newbie/entrance",
		 "down" : __DIR__"guangchang",
	]));

	set("item_desc", ([
	"moon" : 
"那圆圆的月亮似乎比往日大了许多，你开始思念起那与你在同一个月亮下的
远方的父母和那个令你想起就会心动的人，爱人在身边该多好啊！\n",
	"table" : "一张典雅的桃木小桌，上面放着水果盘和饮茶器具。\n",
	"chair" : "一只青竹打制的靠椅，躺上去摇摇晃晃，好舒服耶！\n",
	"rail" : "可以看得见东南远处桃花一片，直似彩云盖地，让人神往。栏杆下面就是广场。\n",
	]));


	set("objects",([
		__DIR__"npc/lver" : 1,
//		"/clone/food/15food" : 4,
	]));

	set("no_fight", 1);

	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_tap", "tap");
	add_action("do_tap", "knock");
	add_action("do_sit", "sit");
}

int do_jump(string arg)
{

	object me = this_player();
	int dex = this_player()->query_dex();
	object ob;

	if (arg != "rail" && arg != "down")
		return command("jump "+arg);

	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");

	message_vision("$N「嗖」地一声从栏杆边跳了下去。\n", me);

	if ((dex <= 23)&&(random(3)<2) || (dex > 23)&&(dex <= 26)&&random(2) )
	{
		message_vision("结果「啪」地一声$N在下面的广场上摔了个结结实实。\n", me);
		if ( objectp(ob=present("shatian you", this_player())) )
		{
			message_vision("柚子砸烂了，溅了$N一屁股柚子。\n", me);
			destruct(ob);
		}
		if ( objectp(ob=present("xiang cha", this_player())) )
		{
			message_vision("怀里的香茶翻了，湿了$N一裤子茶水。\n", me);
			destruct(ob);
		}

		me->receive_damage("qi", 60, me, "跳下赏月台摔");
		me->receive_wound("qi", 40, me, "跳下赏月台摔");
		me->improve_skill("dodge", random(3));
	}
	else if(dex <= 26)
	{
		message_vision("$N摇摇晃晃地落在下面的广场上，差点摔倒！\n", me);
		me->improve_skill("dodge", random(2));
	}
	else
	{
		message_vision("$N提一口气，姿态潇洒地飘落在下面广场上！\n", me);
	}

	me->move(__DIR__"guangchang");

	return 1;
}

int do_tap(string arg)
{

	object me;
	object cui;

	if (!arg || (arg != "desk" && arg != "table"))
	{
		return notify_fail("你要敲什么？\n");
	}

	me = this_player();
	if( !objectp(cui = present("lver", environment(me))) )
		return notify_fail("你敲了敲桌子，却还是没人理你。你突然感觉自己很无聊。\n");

	if( !me->query_temp("marks/sit") )
		return notify_fail("你敲了敲桌子，却没想到有对年轻人从桌底下钻出来，愕然地看着你，"
			+"\n你突然感觉自己很愚蠢。\n");

	if( me->query_temp("marks/served") )
	{
		message_vision("绿萼不耐烦地对$N说道：刚给你上过茶你接着就要，"+
				"你是个Ｒｏｂｏｔ我可不是啊！\n", me);
		return notify_fail("");
	}

	message_vision("$N端坐在桌前，轻轻扣了下桌面，绿萼莞尔一笑，过来招呼。\n", me);

	cui->serve_tea(me);

	me->set_temp("marks/served", 1);
//	remove_call_out("delete_served");
	call_out("delete_served", 10, me);

	return 1;
}

void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}

int do_sit(string arg)
{

	if ( !arg || (arg != "chair") )
		return notify_fail("你要坐什么上面？\n");

	if (this_player()->query_temp("marks/sit"))
		return notify_fail("你已经有了个座位了。\n");

	this_player()->set_temp("marks/sit", 1);
	return notify_fail("你找了个空位坐下，等着上茶。\n");
}

int valid_leave(object me, string dir)
{
	if (  (dir == "up")&&this_player()->query("combat_exp")>10000&&!wizardp(me))
		return notify_fail ("绿萼看了你一眼说道：阁下还是请回吧，这里只是给新手练习用的！\n");
//加入负重限制，以防背人上去，产生bug  -advent 060723
	if (  (dir == "up")&& me->query_encumbrance() * 100 / me->query_max_encumbrance() > 30&&!wizardp(me))
		return notify_fail("你背这么多东西想上去干吗？\n");
	if (  (dir == "down")
		&& ( present("shangyueshipin", this_player())
		|| present("shangyueyinliao", this_player())
                || present("mi tao", this_player()))
		|| present("xiang cha", this_player())
		&& objectp(present("lver", environment(me))) )
	switch ( random(2) )
	{
	case 0:
		return notify_fail
		("绿萼把嘴一撇：吃饱了喝足了还不够，临走怀里还揣上一些，我也替您脸红呢！\n");
		break;
	case 1:
		message_vision("绿萼对$N道了个万福：叶开大侠吩咐，饮食不得带出赏月台。\n",me);
		return 0;
		break;
	}

	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}
