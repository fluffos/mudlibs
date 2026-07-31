// SN:;UIT[>ei\eZeW2^V
// File(/data/room/dajianb/lianwu.c) of dajianb's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是风之居的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "风二中");
        set("room_name", "风之居");
        set("room_id", "wind");
        set("room_owner_id", "dajianb");
        set("room_position", "山路");
}
