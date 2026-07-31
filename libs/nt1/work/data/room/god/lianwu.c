// SN:jQA6E8\7K<mbiBk8
// File(/data/room/god/lianwu.c) of god's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是云海的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "上帝");
        set("room_name", "云海");
        set("room_id", "god");
        set("room_owner_id", "god");
        set("room_position", "名人堂");
}
