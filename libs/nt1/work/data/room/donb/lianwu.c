// SN:A`cNHKKkoAi2P<W0
// File(/data/room/donb/lianwu.c) of donb's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是幽游白书的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "虚藏");
        set("room_name", "幽游白书");
        set("room_id", "donb");
        set("room_owner_id", "donb");
        set("room_position", "碎石小道");
}
