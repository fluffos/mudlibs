// SN:_VMgb7VigJL][Pmk
// File(/data/room/save/lianwu.c) of save's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是存盘的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "段档");
        set("room_name", "存盘");
        set("room_id", "save");
        set("room_owner_id", "save");
        set("room_position", "碎石小道");
}
