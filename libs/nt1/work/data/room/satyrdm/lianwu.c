// SN:d3GhlFHj==m;>j7g
// File(/data/room/satyrdm/lianwu.c) of satyrdm's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是蚂蚁二号的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "训练专家");
        set("room_name", "蚂蚁二号");
        set("room_id", "antstwo");
        set("room_owner_id", "satyrdm");
        set("room_position", "碎石小道");
}
