// SN:`O>6cojd;3]S?AdB
// File(/data/room/thread/lianwu.c) of thread's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是怡红院的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "杜十娘");
        set("room_name", "怡红院");
        set("room_id", "thread");
        set("room_owner_id", "thread");
        set("room_position", "碎石小道");
}
