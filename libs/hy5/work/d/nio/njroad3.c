// Room: /u/jpei/thd/njroad3.c

inherit ROOM;

void create()
{
	set("short", "村中小路");
	set("long", @LONG
一条村中的小路。路边是一家民房，好象很久没有人住的样子。南边有条
小路通向江边。
LONG
	);
	set("outdoors","nio");

	set("exits", ([
		"west": __DIR__"njroad2.c",
		"east": __DIR__"njeast.c",
		"north": __DIR__"yangjia.c",
		"south": __DIR__"njroad4.c",
	]) );

	setup();
	replace_program(ROOM);
}

