// SN:f\c:T@T94Ve50jHm
// File(/data/room/sakura/lianwu.c) of sakura's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是樱花大战的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "真宫寺樱");
        set("room_name", "樱花大战");
        set("room_id", "sakura");
        set("room_owner_id", "sakura");
        set("room_position", "碎石小道");
}
