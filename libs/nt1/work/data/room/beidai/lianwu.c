// SN:lQ9h2c:_GH3;>Vek
// File(/data/room/beidai/lianwu.c) of beidai's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是背篼的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "背带");
        set("room_name", "背篼");
        set("room_id", "beidai");
        set("room_owner_id", "beidai");
        set("room_position", "碎石小道");
}
