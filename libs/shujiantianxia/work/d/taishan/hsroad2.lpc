// hsroad2.c

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，南边隐约可见到扬州城的城墙。东面是通往京城
的驿道，西面一条土路通向黄河区域。
LONG
	);
        set("outdoors", "泰山");

	set("objects", ([
		NPC_D("dadao") : 1,
	]) );
	set("exits", ([
		"west" : "/d/huanghe/tiandi4",
		"east" : __DIR__"yidao2",
	]));
	setup();
}
