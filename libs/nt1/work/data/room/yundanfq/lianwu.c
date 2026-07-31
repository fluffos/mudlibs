// SN:W06coQ:Z:ZI2Q0oe
// File(/data/room/yundanfq/lianwu.c) of yundanfq's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是创世神殿的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "xiakedao");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "渡云");
        set("room_name", "创世神殿");
        set("room_id", "godhall");
        set("room_owner_id", "yundanfq");
        set("room_position", "平原小路");
}
