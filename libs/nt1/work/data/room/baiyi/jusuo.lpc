// SN:?d>R[1ho0GQZSSIo
// File(/data/room/baiyi/jusuo.c) of baiyi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是藏心阁主人白衣人休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "白衣人");
        set("room_name", "藏心阁");
        set("room_id", "zyq");
        set("room_owner_id", "baiyi");
        set("room_position", "名人堂");
}
