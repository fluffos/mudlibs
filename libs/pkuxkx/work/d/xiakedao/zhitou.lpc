//枝头
//for xiakedao
//modified by aiai 98/10/27

inherit ROOM;

void create()
{
	set ("short", "枝头");
	set ("long", @LONG

     这里是柏树的枝头。在你面前，有一根长长的树枝(shuzhi)，
看起来极为结实，而且足足有五尺那么长。
LONG );

	set("exits", ([
		"down"  :__DIR__"shulin7",
	]));

   set("item_desc", ([
              "树枝": "不知道能不能摘(pick)下来。\n",
              "shuzhi": "不知道能不能摘(pick)下来。\n",
   ]) );

	setup();
}

void init()
{
	add_action("do_pick","pick");
}

int do_pick(string arg)
{

	object me,zhi;

	me = this_player();
         if ( (!arg) || (arg != "树枝" && arg != "shuzhi"))
		return notify_fail("你想摘什么？\n");
	if ( present("shu zhi",me) )
		return notify_fail("你不是已经摘到那根树枝了吗？\n");
	if ( me->query_skill("force",1) < random(120) )
	{
		message_vision("$N运足力气，想摘下那根树枝。一个不留神跌了下来，顿时晕倒在地。\n",me);
		me->move(__DIR__"shulin7");
		me->unconcious();
		return 1;
	}
	else{
		message_vision("$N气沉丹田，用力一拽，很轻松地将树枝摘了下来。\n", me );
		zhi = new(__DIR__"obj/shuzhi");
		zhi->move(me);
				
	}
	return 1;
}

