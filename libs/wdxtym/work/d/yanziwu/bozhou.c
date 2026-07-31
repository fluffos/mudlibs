//ROOM: /d/yanziwu/bozhou.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "泊舟坞");
	set("long",@LONG
一片芦苇，茭白丛中现出一座船坞，大小船只依次排开。菱花荷叶
丛中条条水道四通八达，由此可乘船离开燕子坞。湖面正系着一尾小舟
(zhou)。北面远远望过去有一个梯子。
LONG );
	set("outdoors", "yanziwu");

	set("exits", ([
	    "east"  : __DIR__"pindi",
	    "northdown" : __DIR__"muti",
	]));

	set("item_desc", ([
	    "【小舟】" : "这是燕子坞和湖外联系的小舟。舟上一个绿衫少女。岛上的客人只要登舟(enter)就可以出湖了。\n"
		ZJOBACTS2+ZJMENUF(3,3,9,30)+"登船:enter zhou"ZJSEP"一苇渡江:cross\n",
	]));

	set("objects", ([
	    __DIR__"npc/chuanfu" : 1,
	]));

	set("resource/fish", ({ "/clone/fish/liyu",
				"/clone/fish/jiyu",
				"/clone/fish/qingyu",
				"/clone/fish/caoyu", }));

	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_cross", "cross");
}

int do_enter(string arg)
{
	object ob ;
	string dir;

	if (! arg || arg != "zhou")
	{
		tell_object(this_player() , "你要投水？\n" );
		return 1;
	}
	ob = this_player();
	message_vision("船上一个秀美温柔的江南少女看到$N登舟，竹"
		       "篙轻点，舟已离岸，\n燕子坞渐渐在视野里远"
		       "去。\n", ob);
	ob->move(__DIR__"taihu");
	tell_object(ob, HIG "你在湖上飘流，四周看不尽的江南美景。"NOR"\n");
	call_out("home", 10, ob);
	return 1;
}

void home(object ob)
{
	if (! objectp(ob))
		return;

	tell_object(ob, "小舟终于恋恋不舍地靠岸了，你走下小"
		    "舟来，少女挥手道别。\n");
	ob->move(__DIR__"hupan");
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
	me->move(__DIR__"hupan");
	return 1;
}

