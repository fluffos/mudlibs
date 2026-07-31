// SN:nPZWEO^9nN3:a6AA
// File(/data/room/smzz/lianwu.c) of smzz's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是光明顶的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "张无忌");
        set("room_name", "光明顶");
        set("room_id", "smzz");
        set("room_owner_id", "smzz");
        set("room_position", "碎石小道");
}
