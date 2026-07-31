// Room: kedian.c
// congw 980830
inherit ROOM;

void create()
{
	set("short", "客店");
	set("long", @LONG
这是一家价钱低廉的客栈，生意很是清淡。外地游客偶尔选择这里落脚，你在这里
住可要小心，听说荆州有黑店。。。。。
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五十两白银。\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
                "east" : __DIR__"majiu",
		"west" : __DIR__"beidajie1",
		"up" : __DIR__"kedian2",
	]));

	setup();

}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
