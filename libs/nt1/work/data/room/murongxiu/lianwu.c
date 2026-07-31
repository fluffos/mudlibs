// SN::Fk_Y2Q0T\2g@T8S
// File(/data/room/murongxiu/lianwu.c) of murongxiu's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是参合居的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "慕容修");
        set("room_name", "参合居");
        set("room_id", "murongxiu");
        set("room_owner_id", "murongxiu");
        set("room_position", "碎石小道");
}
