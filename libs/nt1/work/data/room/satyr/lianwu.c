// SN:C:`>V`KIkHjjUC7F
// File(/data/room/satyr/lianwu.c) of satyr's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是蚂蚁之家的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "蚂蚁");
        set("room_name", "蚂蚁之家");
        set("room_id", "ants");
        set("room_owner_id", "satyr");
        set("room_position", "山路");
}
