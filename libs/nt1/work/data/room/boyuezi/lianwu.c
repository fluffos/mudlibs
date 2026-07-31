// SN:[eJggL>FYgk6A3GU
// File(/data/room/boyuezi/lianwu.c) of boyuezi's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是蓬莱仙山的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "xiakedao");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "伯约");
        set("room_name", "蓬莱仙山");
        set("room_id", "plge");
        set("room_owner_id", "boyuezi");
        set("room_position", "南海之滨");
}
