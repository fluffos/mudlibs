// SN:LFN`C[5FAfmZJ1\_
// File(/data/room/mingming/xiaoyuan.c) of mingming's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "飞翔鸟小院");
	set ("long", @LONG
这里是一个不大的院子，角落里栽了几棵树，地上零零散散有一
些碎落叶片。院门虚掩，穿过院子就是一个小屋，非常精致。 
LONG );

        set("room_key", "1 of mingming");
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
    
        set("room_owner", "虚小");
        set("room_name", "飞翔鸟");
        set("room_id", "mingming");
        set("room_owner_id", "mingming");
        set("room_position", "碎石小道");
}
