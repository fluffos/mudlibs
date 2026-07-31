// Room: /open/dt/wanhualou.c

inherit ROOM;

void create()
{
	set("short", "万花楼");
	set("long", @LONG
你站在万花楼的门口。满耳的淫声秽响不绝如缕。布置的绝对精致的
床上地下，突然对你产生莫名的诱惑和冲动。
    几个可怜兮兮的千娇百媚在点手儿招你，你想到她们可能就是昔日
江湖中的眼高于顶，顿时大为开心。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"youfujie1",
]));
        set("objects", ([
            __DIR__"npc/guigong" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
