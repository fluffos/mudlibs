// SN:Qeo9bBj1o8G60Z5C
// File(/data/room/cun/lianwu.c) of cun's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是贵宾房的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "银行啊");
        set("room_name", "贵宾房");
        set("room_id", "princess");
        set("room_owner_id", "cun");
        set("room_position", "碎石小道");
}
