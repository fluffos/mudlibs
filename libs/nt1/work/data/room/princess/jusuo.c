// SN:5FFC2Va535eCiXTP
// File(/data/room/princess/jusuo.c) of princess's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是天空之城主人新月休息、读书的地方。楼上就是主人的卧
室，西面则是书房。 
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
    
        set("room_owner", "新月");
        set("room_name", "天空之城");
        set("room_id", "skyheaven");
        set("room_owner_id", "princess");
        set("room_position", "南海之滨");
}
