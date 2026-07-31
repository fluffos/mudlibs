// SN:[H5jIcmYUB@E9:Uf
// File(/data/room/kwantc/dating.c) of kwantc's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "水月楼大厅");
	set ("long", @LONG
这就是水月楼主人独孤灵月迎送客人的地方。正中有些桌椅，侧
面是两扇屏风。东首是主人独孤灵月的房间，有一扇木门虚掩著。南
边是大门，出去就是院子。[2;37;0m
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
    
        set("room_owner", "独孤灵月");
        set("room_name", "水月楼");
        set("room_id", "shuiyue");
        set("room_owner_id", "kwantc");
        set("room_position", "青砖路");
}
