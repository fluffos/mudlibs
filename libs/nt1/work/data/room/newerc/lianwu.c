// SN:hILI6U@@FaE49QFe
// File(/data/room/newerc/lianwu.c) of newerc's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是小乞丐的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "小乞丐");
        set("room_name", "小乞丐");
        set("room_id", "newerc");
        set("room_owner_id", "newerc");
        set("room_position", "碎石小道");
}
