// SN:H9h0NS?SNZaKnG=B
// File(/data/room/ppbrother/lianwu.c) of ppbrother's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是倚王府的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "倚碧鸳");
        set("room_name", "倚王府");
        set("room_id", "ywf");
        set("room_owner_id", "ppbrother");
        set("room_position", "碎石小道");
}
