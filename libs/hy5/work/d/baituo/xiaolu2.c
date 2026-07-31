//xiaolu2

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long",
	     "这里是一条上山的小路。\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"northup" : __DIR__"xiaolu3",
		"southdown" : __DIR__"xiaolu1",
	]));
	set("objects",([
		__DIR__"npc/man" : 1,
	]));
//        set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
