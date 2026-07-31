// SN:VPMU2<1l>b[H9hHQ
// File(/data/room/newguy/lianwu.c) of newguy's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是小房子的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "飞人");
        set("room_name", "小房子");
        set("room_id", "king");
        set("room_owner_id", "newguy");
        set("room_position", "碎石小道");
}
