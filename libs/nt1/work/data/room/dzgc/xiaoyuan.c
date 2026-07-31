// SN:8W7]4F>?CG4O9gm]
// File(/data/room/dzgc/xiaoyuan.c) of dzgc's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "锻造厂小院");
	set ("long", @LONG
这里是一个四四方方的院子，院墙都是用红砖砌成，不算高，但
是非常清爽利落。院中几棵古木成荫，隐然有一种世外桃源的感觉。
院子外面隐约是三岔口，院子的北面有一扇木门。 
LONG );

        set("room_key", "1 of dzgc");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road8",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "段造厂");
        set("room_name", "锻造厂");
        set("room_id", "fac");
        set("room_owner_id", "dzgc");
        set("room_position", "三岔口");
}
