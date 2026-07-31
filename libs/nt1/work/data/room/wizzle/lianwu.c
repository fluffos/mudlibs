// SN:o[Y:lno`YBD`0E=k
// File(/data/room/wizzle/lianwu.c) of wizzle's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是听音阁的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "辛弃疾");
        set("room_name", "听音阁");
        set("room_id", "wizzle");
        set("room_owner_id", "wizzle");
        set("room_position", "碎石小道");
}
