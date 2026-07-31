// SN:OMI5Eg;N6DTj=E\0
// File(/data/room/michael/lianwu.c) of michael's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是武陵春的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "hangzhou");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "行香子");
        set("room_name", "武陵春");
        set("room_id", "ethan");
        set("room_owner_id", "michael");
        set("room_position", "山路");
}
