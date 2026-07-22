//bye enter

inherit ROOM;

void create()
{
        set("short", "山道");
	set("long", @LONG
这是一条崎岖不平的山道，人迹罕至，听说这里不是很太平。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "southeast" : __DIR__"guandao2",
                "northup" : __DIR__"shandao2",
	]));
        set("objects", ([
                __DIR__"npc/tufei2" : 2,
            ]));

	setup();
	replace_program(ROOM);
}

