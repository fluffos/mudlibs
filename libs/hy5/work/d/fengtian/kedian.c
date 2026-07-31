// Room: /d/fengtian/kedian.c

inherit ROOM;

void create()
{
	set("short", "有间客店");
	set("long", @LONG
这里就是盛京最有名的客栈，由于盛京地处要道，再加上这
里价格便宜、服务周到，生意着实不错。门口挂着一块木牌(pai)。
LONG
	);

	set("item_desc", ([
		"pai" : "楼上客房，每晚一两白银。\n",
	]));
        

	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"kd4",
	"up"   : __DIR__"kezhan2",
]));
	set("objects", ([
		__DIR__"npc/waiter" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二伸手拦住你说道：您老还没赏小的店钱呢。\n");
	if( me->query_temp("on_rided") && dir == "up")
		return notify_fail("店小二挡在楼梯前说道：您老的坐骑还是留在楼下吧。\n");

	if ( me->query_temp("rent_paid") && dir == "north" )
		me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
