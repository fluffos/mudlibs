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
    这里摆设十分简陋，一几一塌而已，均以竹制成。几上摆有一具古
琴，用轻纱掩住。透过窗口，隐隐可以看到外面小舍的情况。
LONG
        );

        set("exits", ([
//               "east" : __DIR__"zhuwu",  
               "south" : __DIR__"xiaoshe1", 
               "northwest" : __DIR__"xipu",
               "north" : __DIR__"xiaoxiang_ry",
        ]));
        set("objects", ([

        ]));
//        set("outdoors", "luoyang");
        create_door("south", "小门", "north", DOOR_CLOSED);
        setup();
        replace_program(ROOM);
}

