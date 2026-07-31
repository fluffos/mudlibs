// SN:Q=4gCodQ]k]A[7_Z
// File(/data/room/boa/xiaoyuan.c) of boa's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天堂乐土小院");
	set ("long", @LONG
这里是一个四四方方的院子，院墙都是用红砖砌成，不算高，但
是非常清爽利落。院中几棵古木成荫，隐然有一种世外桃源的感觉。
院子外面隐约是南大街，院子的北面有一扇木门。 
LONG );

        set("room_key", "1 of boa");
	setup();

	set("exits", ([
                "out"    : "/d/suzhou/nandajie2",
	]));

        set("outdoors", "suzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "宝儿");
        set("room_name", "天堂乐土");
        set("room_id", "elysium");
        set("room_owner_id", "boa");
        set("room_position", "南大街");
}
