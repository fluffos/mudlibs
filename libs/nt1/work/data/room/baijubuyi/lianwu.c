// SN:KecGPkf3_IG_a;<X
// File(/data/room/baijubuyi/lianwu.c) of baijubuyi's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是土地庙的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "白居不易");
        set("room_name", "土地庙");
        set("room_id", "baijubuyi");
        set("room_owner_id", "baijubuyi");
        set("room_position", "碎石小道");
}
