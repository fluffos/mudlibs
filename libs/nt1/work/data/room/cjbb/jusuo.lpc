// SN:MYaoCmW<67G>^nAa
// File(/data/room/cjbb/jusuo.c) of cjbb's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是小花猪主人小花猪休息、读书的地方。楼上就是主人的卧
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
    
        set("room_owner", "小花猪");
        set("room_name", "小花猪");
        set("room_id", "cjbb");
        set("room_owner_id", "cjbb");
        set("room_position", "名人堂");
}
