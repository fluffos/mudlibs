// Room: /city/kedian3.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "睡房");
	set("long", @LONG
这是绝情谷女弟子的睡房，没有值守责任的女弟子正在休息。
LONG);

	set("sleep_room", "1");
	set("no_fight", "1");
//        set("hotel",1);

	set("exits", ([
		"south" : __DIR__"zoudao2",
	]));
    set("objects", ([
        __DIR__"npc/nv-dizi" : 2,
        ]));
	setup();
}

