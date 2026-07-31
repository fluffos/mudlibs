// SN:0@KjOTGldaRHh;R^
// File(/data/room/shuiwh/xiaoyuan.c) of shuiwh's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "玉清宫小院");
	set ("long", @LONG
这里是一个四四方方的院子，院墙都是用红砖砌成，不算高，但
是非常清爽利落。院中几棵古木成荫，隐然有一种世外桃源的感觉。
院子外面隐约是碎石小道，院子的北面有一扇木门。 
LONG );

        set("room_key", "1 of shuiwh");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road1",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "水无恨");
        set("room_name", "玉清宫");
        set("room_id", "shuiwh");
        set("room_owner_id", "shuiwh");
        set("room_position", "碎石小道");
}
