// SN:j:]D[4m`mK=k=kO]
// File(/data/room/cjbb/lianwu.c) of cjbb's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是小花猪的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "小花猪");
        set("room_name", "小花猪");
        set("room_id", "cjbb");
        set("room_owner_id", "cjbb");
        set("room_position", "名人堂");
}
