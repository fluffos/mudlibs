// Room: /open/dt/ylinn.c

inherit ROOM;

void create()
{
	set("short", "悦来客栈");
	set("long", @LONG
悦来客栈是城里仅有的两家客栈之一，因为靠近北门，而且
房价非常便宜，所以这里是南来北往的苦哈哈们和关外牧民们经
常光顾的地方。虽然外面的风沙很大，可是这里却打扫的干干净
净，一个长着黑乎乎的圆脸的店小二正在里里外外的忙活着。墙
上挂着一个牌子(paizi)。
LONG
	);

	
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "楼上客房，每晚一两白银。\n",
	]));

	set("valid_startroom", 1);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hongchanglu3",
  "up" : __DIR__"ylinn2",
]));

	set("objects",([
	__DIR__"npc/waiter" : 1,
]));
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎么着，想白住啊！\n");
	if( me->query_temp("on_rided") && dir == "up")  // 判断是否骑着坐骑
		return notify_fail("店小二挡在楼梯前说道：您老的坐骑还是留在楼下吧。\n");

	if ( me->query_temp("rent_paid") && dir == "south" )
	return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎么不住店就走了呢！
旁人还以为小店伺候不周呢！以后谁还敢来？\n");

	return ::valid_leave(me, dir);
}
