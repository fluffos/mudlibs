//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", HIG"小院"NOR);
        set("long", @LONG
推开竹门，走进篱笆围成的小院，才发现竹子掩盖之下，这里别有洞天。
左侧有两间小舍，右侧有三间，均以粗竹子架成。
LONG
        );

        set("exits", ([
               "south" : __DIR__"xiaoxiangjintou",  
               "west" : __DIR__"xiaoshe1",     
               "east" : __DIR__"xiaoshe3",        
        ]));
        set("objects", ([
//              __DIR__"npc/randomnpc" : 1,
        ]));
        create_door("south", "竹门", "north", DOOR_CLOSED);
        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
