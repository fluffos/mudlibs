// SN:>bIHJnaeUCFRg;1j
// File(/data/room/ronger/lianwu.c) of ronger's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是蓉儿居的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "黄蓉");
        set("room_name", "蓉儿居");
        set("room_id", "rongerju");
        set("room_owner_id", "ronger");
        set("room_position", "碎石小道");
}
