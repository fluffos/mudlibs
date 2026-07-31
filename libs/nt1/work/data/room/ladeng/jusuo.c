// SN:XIS<oIl?G=C8LnX1
// File(/data/room/ladeng/jusuo.c) of ladeng's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是基地总部主人本拉灯休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "本拉灯");
        set("room_name", "基地总部");
        set("room_id", "jdzb");
        set("room_owner_id", "ladeng");
        set("room_position", "碎石小道");
}
