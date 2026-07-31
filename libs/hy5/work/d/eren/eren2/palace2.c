#include <room.h>
inherit ROOM;
void create()
{
        set("short", "走道");
        set("long", @LONG
外面竟又是条地道，两旁是雕刻精致的石壁，壁上嵌着发亮的铜灯。
地道并不长，尽头处有一扇门，门上面也雕刻着一些人物花草，看来，单
只建这条地道，就不知花了多少人力物力，这里的主人肯花这么大的人力
物力在地下建造条走道，当真不知是个什么样的怪物。
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"palace3",
                "south" : __DIR__"palace1",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        create_door("south","石门","north",DOOR_CLOSED);
}      
