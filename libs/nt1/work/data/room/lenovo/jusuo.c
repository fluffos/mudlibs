// SN:IJ\]`c;Fh_CUG`SK
// File(/data/room/lenovo/jusuo.c) of lenovo's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是叹息谷主人联想休息、读书的地方。楼上就是主人的卧室，
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
    
        set("room_owner", "联想");
        set("room_name", "叹息谷");
        set("room_id", "sighh");
        set("room_owner_id", "lenovo");
        set("room_position", "山洪瀑布");
}
