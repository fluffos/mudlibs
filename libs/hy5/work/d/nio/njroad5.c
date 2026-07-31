// Room: /u/jpei/thd/njroad5.c

inherit ROOM;

void create()
{
	set("short", "村中小路");
	set("long", @LONG
一条村中的小路。南边就是钱塘江了，那边的树下聚集着一些村民。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"north": __DIR__"njroad4.c",
		"south": __DIR__"jiangpan1.c",
	]) );

	setup();
	replace_program(ROOM);
}

