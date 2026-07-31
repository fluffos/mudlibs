// SN:MFJ7X\6fnkC42P]l
// File(/data/room/huhu/lianwu.c) of huhu's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是关外小屋的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "胡归真");
        set("room_name", "关外小屋");
        set("room_id", "huhu");
        set("room_owner_id", "huhu");
        set("room_position", "碎石小道");
}
