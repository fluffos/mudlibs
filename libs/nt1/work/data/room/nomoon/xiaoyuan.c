// SN:4l_CC_V]0iTHK1GG
// File(/data/room/nomoon/xiaoyuan.c) of nomoon's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "月光宝盒小院");
	set ("long", @LONG
这里是一个不大的院子，角落里栽了几棵树，地上零零散散有一
些碎落叶片。院门虚掩，穿过院子就是一个小屋，非常精致。 
LONG );

        set("room_key", "1 of nomoon");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road1",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "小月光");
        set("room_name", "月光宝盒");
        set("room_id", "nomoon");
        set("room_owner_id", "nomoon");
        set("room_position", "碎石小道");
}
