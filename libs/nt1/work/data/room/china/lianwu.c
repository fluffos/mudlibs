// SN:jR[hE<HX2[S:HWf;
// File(/data/room/china/lianwu.c) of china's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是长乐之家的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "suzhou");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "段盛");
        set("room_name", "长乐之家");
        set("room_id", "tomhome");
        set("room_owner_id", "china");
        set("room_position", "青石官道");
}
