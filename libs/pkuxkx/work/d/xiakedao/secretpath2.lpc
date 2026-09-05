
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "秘道口");
        set("long", @LONG
甬道在这里转了几个弯儿，似乎变的稍微宽敞了些，两旁的铜灯闪著黄
色的光，把人影投印在石壁上。迎面一阵微风吹来，风中似乎带有阵阵花香，
令人心旷神移。在往前，甬道已至尽头，一扇铜门半开。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"secretpath1",
]));
        set("objects", ([
          "/kungfu/class/xiakedao/shipotian":1,
]));
        create_door("west", "铜门", "east", DOOR_CLOSED);
        setup();
}

