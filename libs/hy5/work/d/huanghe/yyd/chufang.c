// 厨房 chufang.c
// zly 1999.06.10
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "厨房");
        set("long", @LONG
这里是萧府的厨房，刚一进门，一股香气扑鼻而来，熏得你直流口
水。灶台上满是油烟，好象今天客人来的不少，厨师们正忙碌着。
LONG
        );

        set("exits", ([ 
            "east" : __DIR__"dating",
]));

        set("objects", ([
                    __DIR__"obj/niurou" : 1,
             __DIR__"obj/liyu" : 1,        
             __DIR__"obj/sansi" : 1,
           __DIR__"obj/fan" : 1,
                   ]));

        setup();
}

