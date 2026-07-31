// SN:P2hT3C^\mWFYCdb0
// File(/data/room/xiaduzhe/xiaoyuan.c) of xiaduzhe's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "小院小院");
	set ("long", @LONG
这里是一个四四方方的院子，院墙都是用红砖砌成，不算高，但
是非常清爽利落。院中几棵古木成荫，隐然有一种世外桃源的感觉。
院子外面隐约是青砖路，院子的北面有一扇木门。 
LONG );

        set("room_key", "1 of xiaduzhe");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road13",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "下毒者");
        set("room_name", "小院");
        set("room_id", "xxy");
        set("room_owner_id", "xiaduzhe");
        set("room_position", "青砖路");
}
