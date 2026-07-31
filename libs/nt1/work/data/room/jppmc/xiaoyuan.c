// SN:AAM1A4062>83Y:4o
// File(/data/room/jppmc/xiaoyuan.c) of jppmc's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "药店小院");
	set ("long", @LONG
这里是一个不大的院子，角落里栽了几棵树，地上零零散散有一
些碎落叶片。院门虚掩，穿过院子就是一个小屋，非常精致。 
LONG );

        set("room_key", "1 of jppmc");
	setup();

	set("exits", ([
                "out"    : "/d/city/jiaowai2",
	]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "傻蛋药三");
        set("room_name", "药店");
        set("room_id", "jppmch");
        set("room_owner_id", "jppmc");
        set("room_position", "树林");
}
