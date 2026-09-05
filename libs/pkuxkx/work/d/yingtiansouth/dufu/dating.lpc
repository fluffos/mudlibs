inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "大厅");
        set("long", 
"这里是建康府都府主人孟珙接待客人的大厅，几个丫鬟正在给客人上茶。\n"

        );
        set("exits", ([
                
                "north" : __DIR__"lianwu",
                "west" : __DIR__"huilang2",
                "east" : __DIR__"huilang3",
                "south" : __DIR__"guangchang",
                
        ]));
        set("objects", ([
		__DIR__"npc/yahuan" : 2,
        __DIR__"npc/meng" : 1,
        
        ]));
        //set("outdoors", "yingtianfu");
        setup();
   
}
