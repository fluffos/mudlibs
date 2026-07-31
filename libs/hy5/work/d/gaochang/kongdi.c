// Room: /d/gaochang/fzlou.c

inherit ROOM;




void create()
{
	set("short", "空地");
	set("long", @LONG
突然之间，眼前豁然开朗，出现一大片空地，尽头
处又有两扇铁门，嵌在大山岩中。
LONG
	);

	set("exits", ([
		"north" : __DIR__"shulin14",
		"east" : __DIR__"shijie1",
	]));

	setup();
	replace_program(ROOM);
}



