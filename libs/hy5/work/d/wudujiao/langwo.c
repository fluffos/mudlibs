// by mayue

inherit ROOM;

void create()
{
	set("short", "狼窝");
	set("long", @LONG
这里是密林中的一个大树洞，里面腥味扑鼻，随处都是吃剩的
兽骨。几只瘦得皮包骨头的饿狼正抖擞精神，似乎要出去觅食了。
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"langwo",
//		"south" : __DIR__"milin5",
		"out" : __DIR__"milin4",
//		"north" : __DIR__"milin3",
	]));
        set("objects", ([
                __DIR__"npc/wolf1": 2,
                __DIR__"npc/wolf2": 1,
	]));

	setup();
	replace_program(ROOM);
}

