// Room: yingmen.c

inherit ROOM;

void create()
{
	set("short", "营门");
	set("long", @LONG
眼前草原上出现一片蒙古帐篷，四周用鹿角丫杈围成了营寨，耳边传来隐隐
的号角声。不远处有个营门，一队队的蒙古骑兵进进出出。看来营门守卫已经注
意到你了，你最好还是赶快离开为妙。
LONG
	);

	set("exits", ([
		"north" : __DIR__"jifeng",
		"south" : __DIR__"caohai1",
	]));
	set("outdoor","大草原");
        
	set("objects", ([
		__DIR__"../npc/jqbing" : 2,
	]));

	setup();
}
