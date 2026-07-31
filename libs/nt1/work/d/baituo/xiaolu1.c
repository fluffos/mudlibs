//xiaolu1

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是一条上山的小路。
LONG );
	set("outdoors", "baituo");
	set("exits", ([
		"northup" : __DIR__"xiaolu2",
		"southwest" : __DIR__"dongjie",
                "northeast" : __DIR__"fende",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
