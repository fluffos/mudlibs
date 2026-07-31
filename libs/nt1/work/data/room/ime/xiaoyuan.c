// SN:^Fc]i=g>4?mDGb6X
// File(/data/room/ime/xiaoyuan.c) of ime's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "演武堂小院");
	set ("long", @LONG
这里是一个四四方方的院子，院墙都是用红砖砌成，不算高，但
是非常清爽利落。院中几棵古木成荫，隐然有一种世外桃源的感觉。
院子外面隐约是山路，院子的北面有一扇木门。 
LONG );

        set("room_key", "1 of ime");
	setup();

	set("exits", ([
                "out"    : "/d/hangzhou/shanlu5",
	]));

        set("outdoors", "hangzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "闯越");
        set("room_name", "演武堂");
        set("room_id", "ime");
        set("room_owner_id", "ime");
        set("room_position", "山路");
}
