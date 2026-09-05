// Room: /d/diaoyudao/junying1.c 军营
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "军营");
	set("long", @LONG
你壮了壮胆走过来，见到四周只是一些残败不堪的帐篷，不象有人
居住的样子，倒象是大军弃留在这里的军营。不知里面有没有人，还是
小心一些。
LONG
	);

	set("exits", ([
                 "east" : __DIR__"zhang2",
                 "west" : __DIR__"zhang1",
                  "north" : __DIR__"junying2",
                   "south" : __DIR__"caodi1",
	]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

