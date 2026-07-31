// SN:hI7?bW>TKP[<Xj_>
// File(/data/room/sana/jusuo.c) of sana's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是青蛙的小窝主人欧阳青蛙休息、读书的地方。楼上就是主
人的卧室，西面则是书房。 
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
    
        set("room_owner", "欧阳青蛙");
        set("room_name", "青蛙的小窝");
        set("room_id", "frog");
        set("room_owner_id", "sana");
        set("room_position", "碎石小道");
}
