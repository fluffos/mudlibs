// SN:<_mdGkG66IG\mZ3b
// File(/data/room/asd/lianwu.c) of asd's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是快活林的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "逗你玩");
        set("room_name", "快活林");
        set("room_id", "asd");
        set("room_owner_id", "asd");
        set("room_position", "碎石小道");
}
