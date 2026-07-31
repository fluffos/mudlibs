// SN:VOa<Pfo4Do5bbJe3
// File(/data/room/haolie/xiaoyuan.c) of haolie's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "小马虎小院");
	set ("long", @LONG
这里是一个不大的院子，角落里栽了几棵树，地上零零散散有一
些碎落叶片。院门虚掩，穿过院子就是一个小屋，非常精致。 
LONG );

        set("room_key", "1 of haolie");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road6",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "段星");
        set("room_name", "小马虎");
        set("room_id", "haolie");
        set("room_owner_id", "haolie");
        set("room_position", "碎石小道");
}
