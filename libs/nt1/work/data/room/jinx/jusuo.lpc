// SN:1`S3_GN7Bo[eWA[K
// File(/data/room/jinx/jusuo.c) of jinx's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是金鳞阁主人蕴龙心境休息、读书的地方。楼上就是主人的
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
    
        set("room_owner", "蕴龙心境");
        set("room_name", "金鳞阁");
        set("room_id", "jinlin");
        set("room_owner_id", "jinx");
        set("room_position", "碎石小道");
}
