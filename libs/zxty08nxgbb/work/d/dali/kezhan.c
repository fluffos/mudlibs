// Room: /d/dali/kezhan.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月19日，北京时间：21时42分22秒。

inherit ROOM;

void create()
{
	set("short", "客栈");
	set("long", @LONG
这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选
择这里落脚，你可以在这里打听到各地的风土人情。店小二里
里外外忙得团团转，接待着南腔北调的客人。
LONG
	);
        set("valid_startroom", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xidajie1",
  "up" : __DIR__"kedian2",
]));

	set("objects", ([
		__DIR__"npc/dingsan" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
        if(objectp(present("ding san", environment(me))))
	return notify_fail("丁三一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "north" )
        if(objectp(present("ding san", environment(me))))
	return notify_fail("丁三跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
