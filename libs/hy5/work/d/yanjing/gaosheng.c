// Room: /d/yanjing/gaosheng.c

inherit ROOM;

void create()
{
	set("short", "高升客栈");
	set("long", @LONG
两盏大红灯笼高挂在檐头两侧,正中的门檐下"高升客栈"的牌匾黑底
金字,牌匾下两扇黑漆大门边伙计站着迎客.一边的角门直接通向后院的
车马棚.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"street2",
  "west" : __DIR__"zoudao",
]));
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("no_clean_up", 0);
	set("outdoors", "yanjing");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer.c" : 1,
]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "east" )
	return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}