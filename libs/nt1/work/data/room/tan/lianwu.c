// SN:a]oRVEUTo3]hP9GA
// File(/data/room/tan/lianwu.c) of tan's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是似水年华的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "huashan");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "明柳");
        set("room_name", "似水年华");
        set("room_id", "times");
        set("room_owner_id", "tan");
        set("room_position", "山洪瀑布");
}
