// SN:3BN>_5N[01d:R7Tg
// File(/data/room/stray/lianwu.c) of stray's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是米米米米的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "我是米");
        set("room_name", "米米米米");
        set("room_id", "rice");
        set("room_owner_id", "stray");
        set("room_position", "青砖路");
}
