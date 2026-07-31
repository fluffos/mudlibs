// SN:^IfQKJF_M47DQOiH
// File(/data/room/dajiana/jusuo.c) of dajiana's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是盘龙山庄主人何济公休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "何济公");
        set("room_name", "盘龙山庄");
        set("room_id", "panglong");
        set("room_owner_id", "dajiana");
        set("room_position", "山路");
}
