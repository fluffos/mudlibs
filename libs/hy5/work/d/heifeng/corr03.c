// /d/heifeng/corr03.c

inherit ROOM;

void create()
{
        set("short", "过道");
        set("long", @LONG
道路变得宽些了。一道长阶通向北面一间大屋子。从你右手
边不时传来一阵呼喝声，像是有人在练功。左边是不条小路。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"corr02",
            "north"  : __DIR__"heifengrm",
            "east"   : __DIR__"wuchang",
            "west"   : __DIR__"corr04",
]));
        set("outdoors", "heifeng");

	set("objects",([
	__DIR__"npc/xunzhai" : 2,
        __DIR__"npc/cleaner" : 1,
]));

        setup();
        replace_program(ROOM);
}

