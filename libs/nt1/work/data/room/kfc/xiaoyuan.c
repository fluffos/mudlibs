// SN:4LdcK\@R3BWeJ_MO
// File(/data/room/kfc/xiaoyuan.c) of kfc's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "肯德基小院");
	set ("long", @LONG
[1;32m这是肯德基总部，金壁辉煌![2;37;0m
LONG );

        set("room_key", "1 of kfc");
	setup();

	set("exits", ([
                "out"    : "/d/city/jiaowai2",
	]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "肯德鸡");
        set("room_name", "肯德基");
        set("room_id", "kfc");
        set("room_owner_id", "kfc");
        set("room_position", "树林");
}
