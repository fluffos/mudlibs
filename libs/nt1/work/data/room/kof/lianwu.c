// SN:ei20n]S16fH5n_`<
// File(/data/room/kof/lianwu.c) of kof's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是断情居的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "段不了");
        set("room_name", "断情居");
        set("room_id", "kof");
        set("room_owner_id", "kof");
        set("room_position", "碎石小道");
}
