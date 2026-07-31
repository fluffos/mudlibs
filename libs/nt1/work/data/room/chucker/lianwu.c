// SN:T:AYf_7LCol2eKoD
// File(/data/room/chucker/lianwu.c) of chucker's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是嘎嘎居的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "段嘎嘎");
        set("room_name", "嘎嘎居");
        set("room_id", "chucker");
        set("room_owner_id", "chucker");
        set("room_position", "树林");
}
