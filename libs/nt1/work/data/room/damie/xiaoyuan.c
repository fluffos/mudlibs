// SN:2HDZbNm3F]oK@jGP
// File(/data/room/damie/xiaoyuan.c) of damie's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "米仓五号小院");
	set ("long", @LONG
这里是一个不大的院子，角落里栽了几棵树，地上零零散散有一
些碎落叶片。院门虚掩，穿过院子就是一个小屋，非常精致。 
LONG );

        set("room_key", "1 of damie");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road12",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "米五");
        set("room_name", "米仓五号");
        set("room_id", "damie");
        set("room_owner_id", "damie");
        set("room_position", "青砖路");
}
