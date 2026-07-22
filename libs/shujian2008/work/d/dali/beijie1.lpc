// Room: 北大街/dali/beijie1.c
// bbb 1997/06/11
inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是大理北大街，西边茶馆的旗帜迎风轻轻的在飘，一些茶客在里面边喝
茶，边聊着天。北边是大理国机要府衙的前厅，极少有人进出。南面就是西大
街了。东边喧闹的声音不停的传了过来，快到大理城中心广场了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"beijie2",
		"west" : __DIR__"chaguan",
		"south" : __DIR__"xijie1",
		"north" : __DIR__"yamen",
	]));
	set("objects", ([ 
		__DIR__"npc/biaotou" : 1, 
	]));

	set("outdoors", "大理");
	setup();
}
