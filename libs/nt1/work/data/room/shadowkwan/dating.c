// SN:5>T?1=V5I4oVlEiK
// File(/data/room/shadowkwan/dating.c) of shadowkwan's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "风雨居大厅");
	set ("long", @LONG
这里是[1;36m风雨居[2;37;0m的大厅，屋内除了几张桌椅外，什么都没有了。[2;37;0m
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
    
        set("room_owner", "独孤傲");
        set("room_name", "风雨居");
        set("room_id", "fengyu");
        set("room_owner_id", "shadowkwan");
        set("room_position", "青砖路");
}
