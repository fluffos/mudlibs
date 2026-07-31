// SN:2R50kiHXeah_KHXl
// File(/data/room/lastlord/lianwu.c) of lastlord's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是乞丐窝的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "摩诃流星");
        set("room_name", "乞丐窝");
        set("room_id", "lord");
        set("room_owner_id", "lastlord");
        set("room_position", "树林");
}
