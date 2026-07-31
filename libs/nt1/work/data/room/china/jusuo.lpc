// SN:`Z]IUW^ic0_MiXL^
// File(/data/room/china/jusuo.c) of china's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是长乐之家主人段盛休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "段盛");
        set("room_name", "长乐之家");
        set("room_id", "tomhome");
        set("room_owner_id", "china");
        set("room_position", "青石官道");
}
