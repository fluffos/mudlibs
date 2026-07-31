// SN:^Idm_AR8BXKYk4b3
// File(/data/room/mhyj/lianwu.c) of mhyj's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是千枝花坞的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "梦幻妖精");
        set("room_name", "千枝花坞");
        set("room_id", "mhyj");
        set("room_owner_id", "mhyj");
        set("room_position", "名人堂");
}
