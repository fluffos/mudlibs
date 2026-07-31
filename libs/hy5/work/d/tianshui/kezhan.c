// Room: /d/tianshui/kezhan.c

inherit ROOM;

void create()
{
	set("short", "天水客栈");
	set("long", @LONG
这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选择
这里落脚，店小二里里外外忙得团团转，接待着南腔北调的客人。
客店的主人从不露面，他究竟是谁，有各种各样的猜测。墙上挂
着一个牌子(paizi)。
LONG
	);

	
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "楼上客房，每晚二两白银。\n",
	]));

	set("objects", ([
		__DIR__"npc/waiter" : 1,
	]));

	set("exits", ([
		"south" : __DIR__"eroad1",
		"up" : __DIR__"kezhan2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");
	if( me->query_temp("on_rided") && dir == "up")  // 判断是否骑着坐骑
		return notify_fail("店小二挡在楼梯前说道：您老的坐骑还是留在楼下吧。\n");

	if ( me->query_temp("rent_paid") && dir == "south" )
		me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
