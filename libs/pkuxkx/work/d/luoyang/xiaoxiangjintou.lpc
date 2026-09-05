//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "小巷尽头");
        set("long", @LONG
小巷尽头是几间竹子搭建的小屋，用篱笆围住，四周都是竹子，小屋
尽在树荫之中，一片清凉。
LONG
        );

        set("exits", ([
               "south" : __DIR__"xiaoxiang",  
               "north" : __DIR__"zhuwu",         
        ]));
        set("objects", ([
//              __DIR__"npc/randomnpc" : 1,
        ]));
        create_door("north", "竹门", "south", DOOR_CLOSED);
        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

