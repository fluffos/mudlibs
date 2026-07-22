// Room: /chengdu/cdkedian.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "高升客栈");
	set("long", @LONG
这里是一家老字号的客栈，崭新的桌椅排得整齐齐，隔着一
层屏风隐隐传来一阵阵锅铲的声音，大概是客栈的厨房，靠南边
的墙壁边上有一道通往二楼的楼梯，门口一个烫金的大牌匾上写
着四个大字“高升客栈”。
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
                "paizi" : "楼上客房，每夜五两白银。\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
                "south" : __DIR__"dongjie1",
                "up" : __DIR__"cdkedian2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{

        if ( me->query_temp("rent_paid") && dir == "south" )
	return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
