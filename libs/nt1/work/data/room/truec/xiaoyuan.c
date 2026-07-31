// SN:FWXP^WYcA8l4Wo:?
// File(/data/room/truec/xiaoyuan.c) of truec's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "桃花小筑小院");
	set ("long", @LONG
这里是一个植满[1;35m桃花[2;37;0m的小院子。[2;37;0m
LONG );

        set("room_key", "1 of truec");
	setup();

	set("exits", ([
                "out"    : "/d/suzhou/nandajie2",
	]));

        set("outdoors", "suzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "萧米");
        set("room_name", "桃花小筑");
        set("room_id", "thxz");
        set("room_owner_id", "truec");
        set("room_position", "南大街");
}
