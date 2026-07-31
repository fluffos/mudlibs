// Room: /u/xiaozhen/linlu4.c

inherit ROOM;

void create()
{
	set("short", "土坡");
	set("long", @LONG
你正走在一个不小的土坡上，往下看是一片小树林，地下有
一块很大的青石板。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"linlu3",
]));
	set("no_clean_up", 0);
	set("objects",([
	__DIR__"npc/xia" : 1,
	__DIR__"npc/toumu" : 1,
	__DIR__"obj/stone" : 1,
]));
	setup();
}

void init()
{
	add_action("do_za","za");
}

int do_za(string arg)
{
	object me = this_player(), obj;

	if(!objectp(obj = present("stone",me)))
		return 0;

	if(!arg)
		return notify_fail("你要拿石块砸什么？\n");

	if((arg != "石板") && (arg != "青石板"))
		return notify_fail("你要拿石块砸什么？\n");

	if(!query("exits/down"))
	{
		set("exits/down" , __DIR__"didong1");
		message_vision("你拿起石块用力向石板砸去，一下把石板砸碎了。\n",me);
		destruct(obj);
	}

	return 1;
}
