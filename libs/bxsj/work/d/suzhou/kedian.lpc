// modify by Lklv 2001.12.31

inherit ROOM;

void create()
{
	set("short", "客店");
	set("long", @LONG
这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选择这里落脚，
你可以在这里打听到各地的风土人情。店小二里里外外忙得团团转，接待着
南腔北调的客人。客店的主人从不露面，他究竟是谁，有各种各样的猜测。
墙上挂着一个牌子(paizi)。
LONG);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五两白银。\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"beidajie1",
		"up" : __DIR__"kedian2",
	]));
	set("incity",1);
	setup();
	"/clone/board/kedian_b"->foo();
}

int valid_leave(object me, string dir)
{
	if ((string)me->query_temp("rent_paid")!="苏州客栈" && dir == "up" )
		return notify_fail("怎么着，想白住啊！\n");
	if ((string)me->query_temp("rent_paid")=="苏州客栈" && dir == "west" )
		return notify_fail("客官已经付了银子，怎么不住店就走了呢！旁人还以为小店伺候不周呢！\n");
	return ::valid_leave(me, dir);
}
