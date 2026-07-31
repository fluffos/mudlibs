// liangong.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是一个不太的院子，是锻炼武功的地方。段家虽然世代皇族，
但是和江湖却有着割不断的联系。因此段家子孙有无数武道高手，这
里就是他们练功的场地。东南就是王府内院，北面则通往另一个练武
场。
LONG );
	set("exits", ([
		"north" : __DIR__"liangong2",
		"southeast" : __DIR__"yongdao1",
	]));
	set("objects", ([
		"/clone/npc/mu-ren": 4,
	]));
	set("for_family", "段氏皇族");
	setup();
}
