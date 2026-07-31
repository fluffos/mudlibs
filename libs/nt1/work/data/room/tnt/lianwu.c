// SN:eZAOKRAjMjUW[^j^
// File(/data/room/tnt/lianwu.c) of tnt's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是阳光华庭的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "重庆");
        set("room_name", "阳光华庭");
        set("room_id", "tnt");
        set("room_owner_id", "tnt");
        set("room_position", "树林");
}
