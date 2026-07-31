// Room: /u/jpei/thd/zoulang1.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
一条连接大厅和内室的回廊。北边通往内室，西边通向练武场。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","桃花岛");

	set("exits", ([
		"east": __DIR__"hall",
		"west": __DIR__"zoulang3",
		"north": __DIR__"zoulang2",
	]) );

	setup();
}

