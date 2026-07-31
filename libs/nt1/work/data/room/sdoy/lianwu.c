// SN:2f<naMf8F7<cj3Zg
// File(/data/room/sdoy/lianwu.c) of sdoy's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是村居的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "无名");
        set("room_name", "村居");
        set("room_id", "sdoy");
        set("room_owner_id", "sdoy");
        set("room_position", "青砖路");
}
