// SN:[[kL?<hDWl[VI@@9
// File(/data/room/yangkang/lianwu.c) of yangkang's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是北京城的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "杨康");
        set("room_name", "北京城");
        set("room_id", "beijing");
        set("room_owner_id", "yangkang");
        set("room_position", "碎石小道");
}
