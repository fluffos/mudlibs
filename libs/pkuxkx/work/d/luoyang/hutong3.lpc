//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"小胡同"NOR);
        set("long", @LONG
一条寂静的胡同，刚下雨，路面看起来还满干净的．一些乡下人挑着
自己种的蔬菜到城里来卖，人不是很多，吆喝声传出很远。路中央有一两
个乞丐正在行乞，无家可归的人正四处游荡，从这里可以看出洛阳的另一
面。路的两边都是当地的一些民宅。
LONG
        );

        set("item_desc", ([
        ]) );

        set("exits", ([    
               "east" : __DIR__"hutong2",  
               "west" : __DIR__"nandajie3",  
			   "north": "/d/ruyang-wangfu/wangfu-fumen",
   			   "south": "/d/xinfang/bieshuqu2",

        ]));
        set("objects", ([
                __DIR__"npc/randomnpc2" : 1,
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}


