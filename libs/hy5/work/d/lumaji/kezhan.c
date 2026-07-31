// Room: /d/lumaji/kezhan.c

inherit ROOM;

void create()
{
	set("short", "客马店");
	set("long", @LONG
这是一家小客栈，店主人就是杜六儿。据说是为了往来的马
友们方便才开的这家客栈。通常情况下他在马市而不在这里看管，
这里只有一个伙计在帮他打里。门口的木牌(pai)上都是尘土。
LONG
	);
	set("item_desc", ([
		"pai" : "楼上高间，每晚五两白银。\n本小利微，请付现银。\n",
	]));

	set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"lu7",
	"up" : __DIR__"kezhan2",
]));

	set("valid_startroom",1);


	set("objects",([
		__DIR__"npc/waiter" : 1,
]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");
	if( me->query_temp("on_rided") && dir == "up")  // 判断是否骑着坐骑
		return notify_fail("店小二挡在楼梯前说道：您老的坐骑还是留在楼下吧。\n");

	return ::valid_leave(me, dir);
}

