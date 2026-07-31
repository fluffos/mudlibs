// Room:  /dali/nanjie2.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
你走在大理南大街上，这里安静极了，大理百姓走到这里，无不放慢了脚
步，以敬仰的目光向东看去，东边过去就是大理皇宫了。南面是大理的司法机
关定安府，东面紧邻着太和东街。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"nanjie1",
		"east" : __DIR__"nanjie3",
		"south" : __DIR__"dinganfu",
	]));
	set("outdoors", "大理");
	setup();
}
