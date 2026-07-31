// SN:NR?HTW1?>lDamHCI
// File(/data/room/jkt/lianwu.c) of jkt's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是和尚居士的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "渡独");
        set("room_name", "和尚居士");
        set("room_id", "shaolin");
        set("room_owner_id", "jkt");
        set("room_position", "碎石小道");
}
