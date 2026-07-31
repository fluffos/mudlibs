// SN:eFKdlEn^9:kj>;^7
// File(/data/room/hzy/lianwu.c) of hzy's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是小楼听风雨的练武场，人在江湖，武功万万不可荒废。
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
    
        set("room_owner", "日啊");
        set("room_name", "小楼听风雨");
        set("room_id", "hzy");
        set("room_owner_id", "hzy");
        set("room_position", "碎石小道");
}
