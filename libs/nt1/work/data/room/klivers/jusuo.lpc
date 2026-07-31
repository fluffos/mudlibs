// SN:S=gYK5T=F`dCbJPD
// File(/data/room/klivers/jusuo.c) of klivers's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是看看之家主人逍遥一剑休息、读书的地方。楼上就是主人
的卧室，西面则是书房。 
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
    
        set("room_owner", "逍遥一剑");
        set("room_name", "看看之家");
        set("room_id", "kkroom");
        set("room_owner_id", "klivers");
        set("room_position", "南大街");
}
