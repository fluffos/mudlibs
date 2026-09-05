// Room: menggubao.c
// created by Zine 30 Aug 2010

inherit ROOM;

void create()
{
	set("short", "蒙古包");
	set("long", @LONG
这是一顶蒙古包，牧人们的住家。
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"shuchi_bao",
		"northeast" : __DIR__"menggubao5",
		"south" : __DIR__"menggubaoexit",
		"north" : __DIR__"menggubao7",
	]));
	set("sleep_room", "1");
	set("objects", ([
        	__DIR__"npc/muyangren" : random(2),
	]));
	set("no_robber",1);
	set("outdoors", "menggu_e");
    setup();
}
