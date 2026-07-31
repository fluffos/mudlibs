// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "副本入口");
	set("long", @LONG

LONG
	);
	set("fuben2",1);	
	set("exits", ([
		"east" : __DIR__"bingying",
	
	]));
	set("no_clean_up", 1);
	set("objects", ([
	]));
	setup();
}
int no_reset() {return 1;}


