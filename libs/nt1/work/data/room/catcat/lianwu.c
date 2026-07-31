// SN:AEOBc3Q]5>kjDMBm
// File(/data/room/catcat/lianwu.c) of catcat's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是小段的家的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "段吟雪");
        set("room_name", "小段的家");
        set("room_id", "catcathome");
        set("room_owner_id", "catcat");
        set("room_position", "碎石小道");
}
