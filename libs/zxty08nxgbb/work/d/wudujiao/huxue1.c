// by mayue


inherit ROOM;

void create()
{
	set("short", "虎穴");
	set("long", @LONG
这里是个隐藏在密林里的岩洞，里面腥味扑鼻，随处都是吃剩的
兽骨。几只威风凛凛的大老虎正躺在洞口懒懒的晒太阳。
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"langwo",
		"south" : __DIR__"huxue2",
		"out" : __DIR__"milin7",
//		"north" : __DIR__"milin3",
	]));
        set("objects", ([
                __DIR__"npc/laohu": 2,
	]));

	setup();
	replace_program(ROOM);
}

