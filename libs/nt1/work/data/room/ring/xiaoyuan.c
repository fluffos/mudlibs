// SN:ZTSFmhlo8hDTKmT9
// File(/data/room/ring/xiaoyuan.c) of ring's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "静心斋小院");
	set ("long", @LONG
这里是一个四四方方的院子，院墙都是用红砖砌成，不算高，但
是非常清爽利落。院中几棵古木成荫，隐然有一种世外桃源的感觉。
院子外面隐约是名人堂，院子的北面有一扇木门。 
LONG );

        set("room_key", "1 of ring");
	setup();

	set("exits", ([
                "out"    : "/d/city/mingren",
	]));

        set("outdoors", "unknow");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "白莲");
        set("room_name", "静心斋");
        set("room_id", "jxz");
        set("room_owner_id", "ring");
        set("room_position", "名人堂");
}
