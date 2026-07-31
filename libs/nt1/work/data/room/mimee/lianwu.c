// SN:\7h:RPlYejd^`b6c
// File(/data/room/mimee/lianwu.c) of mimee's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是东厂的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "小达子");
        set("room_name", "东厂");
        set("room_id", "easthome");
        set("room_owner_id", "mimee");
        set("room_position", "碎石小道");
}
