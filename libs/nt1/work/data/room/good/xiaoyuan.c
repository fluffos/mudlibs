// SN:b;WOcG3Yj>PVndlS
// File(/data/room/good/xiaoyuan.c) of good's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "中升雅园小院");
	set ("long", @LONG
这里是一个不大的院子，角落里栽了几棵树，地上零零散散有一
些碎落叶片。院门虚掩，穿过院子就是一个小屋，非常精致。 
LONG );

        set("room_key", "1 of good");
	setup();

	set("exits", ([
                "out"    : "/d/hangzhou/shanlu4",
	]));

        set("outdoors", "hangzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "树上飞");
        set("room_name", "中升雅园");
        set("room_id", "goodroom");
        set("room_owner_id", "good");
        set("room_position", "山路");
}
