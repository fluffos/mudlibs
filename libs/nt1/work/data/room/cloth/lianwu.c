// SN:Z?a4IHM6g9b;oZOi
// File(/data/room/cloth/lianwu.c) of cloth's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是布衣之家的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "布衣");
        set("room_name", "布衣之家");
        set("room_id", "cloth");
        set("room_owner_id", "cloth");
        set("room_position", "碎石小道");
}
