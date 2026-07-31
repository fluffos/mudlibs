// SN:MGm6iK__bjU7_LHL
// File(/data/room/depravity/lianwu.c) of depravity's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是禁入魔界的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "堕落天使");
        set("room_name", "禁入魔界");
        set("room_id", "devil");
        set("room_owner_id", "depravity");
        set("room_position", "树林");
}
