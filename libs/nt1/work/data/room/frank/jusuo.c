// SN:U_C28@GR=T8A@T\Q
// File(/data/room/frank/jusuo.c) of frank's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是哥们的家主人哥们你好休息、读书的地方。楼上就是主人
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
    
        set("room_owner", "哥们你好");
        set("room_name", "哥们的家");
        set("room_id", "frank");
        set("room_owner_id", "frank");
        set("room_position", "碎石小道");
}
