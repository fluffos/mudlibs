// Room: /u/jpei/thd/njroad4.c

inherit ROOM;

void create()
{
	set("short", "村中小路");
	set("long", @LONG
一条村中的小路。往南边看已经可以看到大江了，江水的咆哮声不时地敲
击着你的耳鼓。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"north": __DIR__"njroad3.c",
		"south": __DIR__"njroad5.c",
	]) );
	set("objects", ([
         "/d/xiangyang/npc/boy" : 1,
	]) );

	setup();
	replace_program(ROOM);
}

