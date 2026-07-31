// SN:=X`ijR0;lID6>TQ[
// File(/data/room/thy/dating.c) of thy's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "平安坊大厅");
	set ("long", @LONG
这是一条宽阔的走廊，很多工人来来往往地忙碌着运输材料和成
品。没人有空理会你，你感到很无聊，还是快[1;31m离开[2;37;0m吧……[2;37;0m
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
    
        set("room_owner", "好人");
        set("room_name", "平安坊");
        set("room_id", "thy");
        set("room_owner_id", "thy");
        set("room_position", "树林");
}
