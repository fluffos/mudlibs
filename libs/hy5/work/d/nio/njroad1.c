// Room: /u/jpei/thd/njroad1.c

inherit ROOM;

void create()
{
	set("short", "村中小路");
	set("long", @LONG
一条村中的小路。路边是一家破旧的小酒店，好象已经很久没人来过了的
样子。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"west": __DIR__"njwest.c",
		"east": __DIR__"njroad2.c",
		"south": __DIR__"xiaodian.c",
	]) );

	setup();
	replace_program(ROOM);
}

