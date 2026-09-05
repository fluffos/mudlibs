#include <room.h>

inherit ROOM;

void create()
{
        set("short", "秘道");
        set("long", @LONG
这是一条长长的甬道，甬道两旁嵌有铜灯。甬道斜斜地伸如地下，不知
有多长，也不知伸向何处，但两壁铜灯俱都擦得极为光亮，显见此地经常有
人行走。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"secretpath2",
		"west" : __DIR__"secretpath0",
]));
        set("objects", ([
                        ]) );

        create_door("east", "铜门", "west", DOOR_CLOSED);
        setup();
        replace_program(ROOM);
}

