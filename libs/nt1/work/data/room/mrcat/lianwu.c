// SN:AF]276B7dM3hgA1N
// File(/data/room/mrcat/lianwu.c) of mrcat's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是一品居的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "慕容覆水");
        set("room_name", "一品居");
        set("room_id", "mrcat");
        set("room_owner_id", "mrcat");
        set("room_position", "碎石小道");
}
