// SN:S;FU>`L5@_WEYoHQ
// File(/data/room/xianliao/xiaoyuan.c) of xianliao's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "超过两个小院");
	set ("long", @LONG
这里是一个不大的院子，角落里栽了几棵树，地上零零散散有一
些碎落叶片。院门虚掩，穿过院子就是一个小屋，非常精致。 
LONG );

        set("room_key", "1 of xianliao");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road17",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "澄超");
        set("room_name", "超过两个");
        set("room_id", "xianliao");
        set("room_owner_id", "xianliao");
        set("room_position", "碎石小道");
}
