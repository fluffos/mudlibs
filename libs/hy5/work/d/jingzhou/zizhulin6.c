// Room: zizhulin
// congw 980829
inherit ROOM;

void create()
{
	set("short", "紫竹林");
	set("long", @LONG
你来到一片翠绿的包围之中，仿似迷失了方向。
LONG
	);
        set("outdoors", "jingzhou");

	set("exits", ([
	"west" : __DIR__"zizhulin5",
	"east" : __DIR__"zizhulin1",
	"south"	: __DIR__"zizhulin7",
	"north" : __DIR__"zizhulin2",
]));
	setup();
	replace_program(ROOM);
}

