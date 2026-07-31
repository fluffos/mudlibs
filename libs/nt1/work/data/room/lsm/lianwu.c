// SN:jb4h^N;o]If>Nh^R
// File(/data/room/lsm/lianwu.c) of lsm's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是雷神之殿的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "雷斯魔");
        set("room_name", "雷神之殿");
        set("room_id", "lsm");
        set("room_owner_id", "lsm");
        set("room_position", "平原小路");
}
