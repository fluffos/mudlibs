// SN:^:UbAjaILd0T;C:d
// File(/data/room/chinapk/dayuan.c) of chinapk's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "肯德鸡大院");
	set ("long", @LONG
[1;35m泥巴肯德基集团[2;37;0m
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/city/jiaowai2",
	]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "肯德基");
        set("room_name", "肯德鸡");
        set("room_id", "chinapk");
        set("room_owner_id", "chinapk");
        set("room_position", "树林");
}
