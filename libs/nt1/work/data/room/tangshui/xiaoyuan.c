// SN:^I=k=>3B4cTa[7VG
// File(/data/room/tangshui/xiaoyuan.c) of tangshui's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "糖糖水水小院");
	set ("long", @LONG
糖糖水水的小小院[2;37;0m
LONG );

        set("room_key", "1 of tangshui");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road1",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "糖水");
        set("room_name", "糖糖水水");
        set("room_id", "tangs");
        set("room_owner_id", "tangshui");
        set("room_position", "碎石小道");
}
