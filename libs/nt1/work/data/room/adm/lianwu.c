// SN:1Bj<Xc2YWXGh5dZS
// File(/data/room/adm/lianwu.c) of adm's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是神仙居的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "神仙");
        set("room_name", "神仙居");
        set("room_id", "roomd");
        set("room_owner_id", "adm");
        set("room_position", "碎石小道");
}
