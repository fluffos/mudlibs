// SN:eG[1hho=gec>Q3OI
// File(/data/room/aoa/lianwu.c) of aoa's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是幽宅的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "unknow");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "死囚");
        set("room_name", "幽宅");
        set("room_id", "you");
        set("room_owner_id", "aoa");
        set("room_position", "名人堂");
}
