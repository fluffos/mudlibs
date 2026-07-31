// SN:eGZEYOOL;99DQVOU
// File(/data/room/array/jusuo.c) of array's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是天龙阵主人艾汀休息、读书的地方。楼上就是主人的卧室，
西面则是书房。 
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
    
        set("room_owner", "艾汀");
        set("room_name", "天龙阵");
        set("room_id", "array");
        set("room_owner_id", "array");
        set("room_position", "名人堂");
}
