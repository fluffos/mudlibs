// SN:MDd=oAbB]0emEc=J
// File(/data/room/grass/lianwu.c) of grass's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是草堂的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "hangzhou");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "小草");
        set("room_name", "草堂");
        set("room_id", "grass");
        set("room_owner_id", "grass");
        set("room_position", "山路");
}
