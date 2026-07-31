// SN:i1eA1FfIOXjRZ8T[
// File(/data/room/skysword/xiaoyuan.c) of skysword's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "绝剑山庄小院");
	set ("long", @LONG
这里是一个四四方方的院子，院墙都是用红砖砌成，不算高，但
是非常清爽利落。院中几棵古木成荫，隐然有一种世外桃源的感觉。
院子外面隐约是青砖路，院子的北面有一扇木门。 
LONG );

        set("room_key", "1 of skysword");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road10",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "无天绝剑");
        set("room_name", "绝剑山庄");
        set("room_id", "skysword");
        set("room_owner_id", "skysword");
        set("room_position", "青砖路");
}
