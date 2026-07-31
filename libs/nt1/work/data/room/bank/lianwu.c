// SN:JUbG8gB[1BmVgY2Q
// File(/data/room/bank/lianwu.c) of bank's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是中国银行金库的练武场，人在江湖，武功万万不可荒废。
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
    
        set("room_owner", "中国银行");
        set("room_name", "中国银行金库");
        set("room_id", "bank");
        set("room_owner_id", "bank");
        set("room_position", "碎石小道");
}
