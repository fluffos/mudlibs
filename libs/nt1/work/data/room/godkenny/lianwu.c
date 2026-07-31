// SN:JoRaeTDJfnAo=@oL
// File(/data/room/godkenny/lianwu.c) of godkenny's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是糖果点心屋的练武场，人在江湖，武功万万不可荒废。
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
    
        set("room_owner", "云飘之翼");
        set("room_name", "糖果点心屋");
        set("room_id", "candy");
        set("room_owner_id", "godkenny");
        set("room_position", "青石官道");
}
