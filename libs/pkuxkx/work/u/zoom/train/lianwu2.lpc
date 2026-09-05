//lianwu2.c
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
		"east" : __DIR__"xiuxi",
		"west" : __DIR__"sishu",
		"south" : __DIR__"lianwu1",
    ]));
    
	set("objects", ([
		__DIR__"npc/trainer2" : 1,
		]));

    set("outdoors", "train");
    setup();

}
