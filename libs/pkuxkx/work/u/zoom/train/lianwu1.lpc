//lianwu1.c
//by zoom
//2004.3.29

inherit ROOM;

void create()
{
    set("short", "练武场");
    set("long", @LONG
这里是新手学堂的练武场，旁边摆满了十八般兵器，这里设备
齐全，很多年轻弟子正在这里勤修苦练。
LONG
    );
    set("exits", ([
		"north" : __DIR__"lianwu2",
		"east" : __DIR__"bingqi",
		"west" : __DIR__"shitang",
		"south" : __DIR__"road3",
    ]));
    
	set("objects", ([
		__DIR__"npc/trainer" : 1,
		]));

    set("outdoors", "train");
    setup();

}
