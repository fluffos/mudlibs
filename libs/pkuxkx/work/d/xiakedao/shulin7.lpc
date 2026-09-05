//树林
//for xiakedao
//modified by aiai 98/10/27

inherit ROOM;

void create()
{
	set ("short", "树林");
	set ("long", @LONG

    树林中草木繁多，遍地绿草高可没膝。阵风吹过，草中
发出唏唏唆唆的响声，象是有人自草中穿行。顶上树叶繁茂，
密密麻麻把天都遮住了。在这片树林中，有一棵柏树，树壮
枝长，极为惹人注目。此树树干虽宽，但却是轻斜向一方，
似乎并不难爬。
LONG );

        set("outdoors", "xiakedao");

	set("no_sleep_room",1);

	set("exits", ([
                "north" : __DIR__"shulin8",
		"south" : __DIR__"shulin2",
		"east"  : __DIR__"shulin6",
		"west"  : __DIR__"shulin7",
	]));


	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{

	object me;
	me = this_player();
         if ( (!arg) || (arg != "柏树" && arg != "tree"))
		return notify_fail("你想爬什么？\n");

	if ( me->query_skill("dodge",1) < random(120) )
	{
		message_vision("$N运足力气，向树上爬去。一个不留神跌了下来，顿时晕倒在地。\n",me);
		me->unconcious();
		return 1;
	}
	else{
		message_vision("$N使出轻身功夫，轻轻跃上枝头。\n", me );
		me->move(__DIR__"zhitou");
	}
	return 1;
}

