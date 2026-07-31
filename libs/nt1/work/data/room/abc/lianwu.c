// SN:HN`7e:kTkU?iH;_O
// File(/data/room/abc/lianwu.c) of abc's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是农业银行金库的练武场，人在江湖，武功万万不可荒废。
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
    
        set("room_owner", "农业银行");
        set("room_name", "农业银行金库");
        set("room_id", "abc");
        set("room_owner_id", "abc");
        set("room_position", "碎石小道");
}
