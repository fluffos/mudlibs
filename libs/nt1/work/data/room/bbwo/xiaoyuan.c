// SN:;ge9@h3ao?H`h?AI
// File(/data/room/bbwo/xiaoyuan.c) of bbwo's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "风雨小院");
	set ("long", @LONG
这里是一个四四方方的院子，院墙都是用红砖砌成，不算高，但
是非常清爽利落。院中几棵古木成荫，隐然有一种世外桃源的感觉。
院子外面隐约是碎石小道，院子的北面有一扇木门。 
LONG );

        set("room_key", "1 of bbwo");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road5",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "小波");
        set("room_name", "风雨");
        set("room_id", "bbwo");
        set("room_owner_id", "bbwo");
        set("room_position", "碎石小道");
}
