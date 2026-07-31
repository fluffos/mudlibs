// SN:eci3i?0mL0@GJD3l
// File(/data/room/longjia/xiaoyuan.c) of longjia's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "龙甲楼小院");
	set ("long", @LONG
这里是一个不大的院子，角落里栽了几棵树，地上零零散散有一
些碎落叶片。院门虚掩，穿过院子就是一个小屋，非常精致。 
LONG );

        set("room_key", "1 of longjia");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road3",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "龙甲");
        set("room_name", "龙甲楼");
        set("room_id", "longjia");
        set("room_owner_id", "longjia");
        set("room_position", "碎石小道");
}
