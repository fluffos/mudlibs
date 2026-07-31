// Room: /d/jinghai/wm9.c

inherit ROOM;

void create()
{
	set("short", "中央空地");
	set("long", @LONG
这是无名堡的中心广场。广场竖立着一座高高的钟楼，气势
磅礴。每到清晨，响亮的钟声便会伴着淡淡雾气传向无名堡的各
个角落。这里人多喧哗，经常挤挤挨挨，许多靖海弟子喜欢聚集
在这儿。往西遥遥可见无名堡水寨大门。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wm14",
  "east" : __DIR__"wm8",
  "south" : __DIR__"wm15",
  "west" : __DIR__"wm10",
]));
        set("outdoors","jinghai");

	setup();
}

int valid_leave(object me,string arg)
{
	if( (arg =="south" || arg =="s")
	&& !wizardp(me)
	&& (me->query("class") != "jinghai" ) )
		return notify_fail("突然旁边窜出几个兵丁拦住你说道：书房重地外人不得人内！”\n");

	else
		return ::valid_leave(me,arg);
}
