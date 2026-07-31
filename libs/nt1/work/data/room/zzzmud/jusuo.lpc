// SN:UQ@0R1`>4`DfKB4i
// File(/data/room/zzzmud/jusuo.c) of zzzmud's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是满天星主人月落无双休息、读书的地方。楼上就是主人的
卧室，西面则是书房。 
LONG );

	set("exits", ([
		"up"   : __DIR__"woshi",
                "west" : __DIR__"shufang",
	]));

        set("no_sleep_room", 1);
        setup();

        set("KEY_DOOR", ([
                "exit" : "east",
                "room" : __DIR__"huayuan",
        ]));
    
        set("room_owner", "月落无双");
        set("room_name", "满天星");
        set("room_id", "zzzmud");
        set("room_owner_id", "zzzmud");
        set("room_position", "碎石小道");
}
