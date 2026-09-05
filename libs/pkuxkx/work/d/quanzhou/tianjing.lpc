// /d/jiaxing/tianjing.c 天井
// by shang 97/6

inherit ROOM;

void create()
{
        set("short", "天井");
	set("long", @LONG
这是陆家庄庄内天井。有一仆人在打扫着。
LONG
	);

	set("exits", ([
                "enter" : __DIR__"dating",
                "out" : __DIR__"luzhuang",
	]));

        set("objects", ([
                __DIR__"npc/puren" : 1,
        ]));
        set("outdoors", "嘉兴");
	setup();
	replace_program(ROOM);
}

