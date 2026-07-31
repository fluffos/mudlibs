// SN:agCM`m7mASUe2Rj]
// File(/data/room/monster/lianwu.c) of monster's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是魔物大本营的练武场，人在江湖，武功万万不可荒废。
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
    
        set("room_owner", "魔物");
        set("room_name", "魔物大本营");
        set("room_id", "hell");
        set("room_owner_id", "monster");
        set("room_position", "碎石小道");
}
