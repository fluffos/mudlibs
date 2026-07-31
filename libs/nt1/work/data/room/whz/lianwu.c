// SN:Cb`JXG_TneKSBi=K
// File(/data/room/whz/lianwu.c) of whz's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是风丹雅阁的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "给我新鲜");
        set("room_name", "风丹雅阁");
        set("room_id", "ansionyd");
        set("room_owner_id", "whz");
        set("room_position", "碎石小道");
}
