// SN:C>dL:bf2HR6BPgEE
// File(/data/room/worker/dating.c) of worker's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "泥潭丹药制造大厅");
	set ("long", @LONG
这就是泥潭丹药制造主人桃花工人迎送客人的地方。正中有些桌
椅，侧面是两扇屏风。东首是主人桃花工人的房间，有一扇木门虚掩
着。南边是大门，出去就是院子。 
LONG );

	setup();

	set("exits", ([
                "east"   : __DIR__"woshi",
		"north"  : __DIR__"houyuan",
	]));

        create_door("east", "木门", "west", DOOR_CLOSED);

        set("no_sleep_room", 1);

        set("KEY_DOOR", ([
                "exit" : "south",
                "room" : __DIR__"xiaoyuan",
        ]));
    
        set("room_owner", "桃花工人");
        set("room_name", "泥潭丹药制造");
        set("room_id", "wkone");
        set("room_owner_id", "worker");
        set("room_position", "碎石小道");
}
