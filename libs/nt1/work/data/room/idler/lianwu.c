// SN:2ZB:HCh>hL69>9[R
// File(/data/room/idler/lianwu.c) of idler's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是太虚居的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "元神出窍");
        set("room_name", "太虚居");
        set("room_id", "taixuju");
        set("room_owner_id", "idler");
        set("room_position", "山路");
}
