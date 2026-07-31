// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","原始森林");
       set("long", 
"这是京都通往东京的一快森林，森林中地下布满了一层厚厚的树叶踩上去
卡卡做响，透过森林的一些阳光洒落下，很是美丽。向南边走可以见到中仙道。\n"
);
        set("exits", ([
                "northwest" : __DIR__"linzi",
//                "northeast" : "",
                "west" : __DIR__"path3",
                "southeast" : __DIR__"zhongxiandao",
        ]));
        
        set("objects", ([
                         __DIR__"npc/bird" : 1,
        ]));

        set("outdoors", "feitian");

        setup();
       replace_program(ROOM);
}