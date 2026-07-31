// SN:eNkUgO9YM=gcX4X]
// File(/data/room/ada/lianwu.c) of ada's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是大房的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "阿大");
        set("room_name", "大房");
        set("room_id", "prince");
        set("room_owner_id", "ada");
        set("room_position", "碎石小道");
}
