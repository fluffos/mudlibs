// SN:L2`H^gmUeRNM4bL[
// File(/data/room/death/lianwu.c) of death's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是亡灵神殿的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "死神");
        set("room_name", "亡灵神殿");
        set("room_id", "die");
        set("room_owner_id", "death");
        set("room_position", "碎石小道");
}
