// Room: /d/shaolin/shijie1.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "石阶");
	set("long", @LONG
这里是嵩山南麓的少室山山脚。一条长长的石阶如同巨龙般
蜿蜒而上，直没云端。嵩山群峰壁立，翠色满山，令人俯仰间顿
生渺小之意。边上有几个叫卖的小贩和挑夫，似乎在嚷嚷着争吵
些什么。
LONG
	);

	set("exits", ([
		"east" : __DIR__"rjdtoly1",
		"west" : __DIR__"rjdtoly3",
		"northup" : "/d/shaolin/shijie2",
	]));

	set("objects",([
		"/d/shaolin/npc/xiao-fan" : 1,
		"/d/shaolin/npc/tiao-fu" : 2,
	]));

	set("outdoors", "shaolin");
	setup();replace_program(ROOM);
	replace_program(ROOM);
}



void init() {
	return;
}
