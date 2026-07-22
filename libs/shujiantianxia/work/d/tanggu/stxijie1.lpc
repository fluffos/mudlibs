inherit ROOM;
void create()
{
        set("short", "西街");
        set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。东边的就是塘沽城最繁华
的城中心了。西边有不少外乡的过客。北边是塘沽大药房，半月形的大门上方
写着“妙手回春”四个烫金大字，里面出来飘出浓重的药味。南边是本城有名
的喜发客栈。
LONG );
        set("exits", ([
                "north" : __DIR__"yaofang",
		"south" : __DIR__"kedian",
		"east" : __DIR__"center",
		"west" : __DIR__"stxijie2",
	]));

	set("objects", ([
                CLASS_D("gaibang/qigai") : 1,
        ]));

	set("outdoors", "塘沽");
	setup();
}
