// SN:J4OG[B:Io3H2]4U2
// File(/data/room/tinger/lianwu.c) of tinger's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是黎苑小筑的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "婷儿");
        set("room_name", "黎苑小筑");
        set("room_id", "liyuan");
        set("room_owner_id", "tinger");
        set("room_position", "碎石小道");
}
