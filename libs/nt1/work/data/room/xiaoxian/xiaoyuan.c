// SN:_BKKRVLUHVQ1eaDA
// File(/data/room/xiaoxian/xiaoyuan.c) of xiaoxian's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "潇潇窝小院");
	set ("long", @LONG
这里是一个四四方方的院子，院墙都是用红砖砌成，不算高，但
是非常清爽利落。院中几棵古木成荫，隐然有一种世外桃源的感觉。
院子外面隐约是碎石小道，院子的北面有一扇木门。 
LONG );

        set("room_key", "1 of xiaoxian");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road6",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "笑仙");
        set("room_name", "潇潇窝");
        set("room_id", "xiaoxian");
        set("room_owner_id", "xiaoxian");
        set("room_position", "碎石小道");
}
