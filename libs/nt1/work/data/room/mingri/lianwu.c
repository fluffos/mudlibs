// SN:_D;G:7Ac9\Q@PALA
// File(/data/room/mingri/lianwu.c) of mingri's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是天下会总舵的练武场，人在江湖，武功万万不可荒废。
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
    
        set("room_owner", "天涯涯");
        set("room_name", "天下会总舵");
        set("room_id", "ming");
        set("room_owner_id", "mingri");
        set("room_position", "碎石小道");
}
