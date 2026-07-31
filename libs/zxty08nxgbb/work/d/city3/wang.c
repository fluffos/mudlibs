// Room: /chengdu/wang.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "梁王府");
	set("long", @LONG
这里是梁王府的大门，两边是两个威武的石狮子，高高的台
阶，中间是正门，两边是边门，几个王府卫士整齐的守卫在两旁，
门口显得很安静，普通百姓是不许逗留的。
LONG
	);

	set("exits", ([
                "east" : __DIR__"nanjie1",
	]));

	setup();
	replace_program(ROOM);
}

