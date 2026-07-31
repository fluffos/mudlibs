// Room: /u/jpei/thd/kezhan.c

inherit ROOM;

void create()
{
	set("short", "归来客栈");
	set("long", @LONG
这是一家靠海的小客栈，本来是为想出海游玩的旅人准备的，可是由于经
营不善，生意相当地冷清，柜台旁边放着一个牌子(paizi)。 南面是一条小土
路。
LONG
	);
	set("no_clean_up", 0);
        set("no_sleep_room", 1);
	set("valid_startroom", 1);
	set("objects", ([
		__DIR__"npc/xiaoer.c":1,
	]));

	set("item_desc", ([
		"paizi" : "楼上客房，每夜四两白银。\n",
	]));

	set("exits", ([
		"south": __DIR__"hbroad.c",
		"up" : __DIR__"kezhan2",
	]) );

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("店小二伸手拦住了你：怎么着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "south" )
	return notify_fail("客官已经付了银子，怎么不住店就走了呢！旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
