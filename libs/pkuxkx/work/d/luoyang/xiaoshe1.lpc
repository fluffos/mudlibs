//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", HIG"小舍"NOR);
        set("long", @LONG
小舍的北边有个小门，门轻轻掩住，想是主人不在。门边有窗，
窗悬竹帘，复障轻纱，隐隐可以看到里面。
LONG
        );

        set("exits", ([
               "east" : __DIR__"zhuwu",  
               "north" : __DIR__"xiaoshe2",    
        ]));
        set("objects", ([

        ]));
//        set("outdoors", "luoyang");
        create_door("north", "小门", "south", DOOR_CLOSED);
        setup();
        replace_program(ROOM);
}

