// SN:W>:?KlZiV`aQd;m7
// File(/data/room/redbird/lianwu.c) of redbird's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是凤凰谷的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "朱雀");
        set("room_name", "凤凰谷");
        set("room_id", "redroom");
        set("room_owner_id", "redbird");
        set("room_position", "碎石小道");
}
