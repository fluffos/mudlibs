// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "班房");
	set("long", @LONG
这里是衙门的班房，是扬州府巡捕办案和休息的地方。东厢墙上挂着一些
脏兮兮的套具，锁具，刑具。北首靠墙放有一个八仙桌，几张椅子，几个面孔
阴森的捕头坐在那里。有几个衙役站在旁边，不知道在说着什么。
LONG
	);

	set("exits", ([
		"west" : __DIR__"menlang",
	]));
	set("objects", ([
        	__DIR__"npc/yayi" : 2,
	]));

	set("incity",1);
	setup();
}
