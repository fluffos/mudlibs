// SN:;SOUWZ<m6DcSkal_
// File(/data/room/hhhhh/xiaoyuan.c) of hhhhh's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "我的家小院");
	set ("long", @LONG
这里是一个不大的院子，角落里栽了几棵树，地上零零散散有一
些碎落叶片。院门虚掩，穿过院子就是一个小屋，非常精致。 
LONG );

        set("room_key", "1 of hhhhh");
	setup();

	set("exits", ([
                "out"    : "/d/city/mingren",
	]));

        set("outdoors", "unknow");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "二锅头");
        set("room_name", "我的家");
        set("room_id", "hhhhh");
        set("room_owner_id", "hhhhh");
        set("room_position", "名人堂");
}
