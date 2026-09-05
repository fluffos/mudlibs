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
密密麻麻把天都遮住了。值得注意的是这里有一棵树(tree)特别粗大。

LONG );

        set("outdoors", "xiakedao");

	set("no_sleep_room",1);

	set("exits", ([
                "north" : __DIR__"shulin3",
		"south" : __DIR__"shulin6",
		"east"  : __DIR__"shulin5",
		"west"  : __DIR__"shulin7",
	]));
   set("item_desc", ([
              "tree": "也许能爬上这棵树看看周围的情况。\n",
   ]) );


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
	if ( ( ! arg ) || (arg != "tree" ) )
		return notify_fail("你想爬什么？\n");
	if ( me->query_skill("dodge",1) > 100 )
	{
		message_vision("$N轻身一跃，跳上树顶，清楚地看到不远南方是一座高耸如云的悬崖。\n",me);
		message_vision("$N随即从树上跳了过去。\n",me);
		me->move(__DIR__"yaxia");
		message_vision("$N从树丛中跳了出来。\n",me);
		return 1;
	}
       message_vision("$N轻身一跃，却没能爬上树顶。\n",me);
	return 1;
}
