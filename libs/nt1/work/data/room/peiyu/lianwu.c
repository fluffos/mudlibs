// SN:lRl`[W1GJ3hXhDea
// File(/data/room/peiyu/lianwu.c) of peiyu's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是杀人山庄的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "俞佩玉");
        set("room_name", "杀人山庄");
        set("room_id", "peiyu");
        set("room_owner_id", "peiyu");
        set("room_position", "南海之滨");
}
