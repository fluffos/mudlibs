// SN:nW9FeMS25aiHQcFM
// File(/data/room/djs/lianwu.c) of djs's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是流氓窝的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "很无耻");
        set("room_name", "流氓窝");
        set("room_id", "djs");
        set("room_owner_id", "djs");
        set("room_position", "名人堂");
}
