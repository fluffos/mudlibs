// SN:mcaT<kZFg]Xnn:6N
// File(/data/room/alert/lianwu.c) of alert's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是猪猪山中别墅的练武场，人在江湖，武功万万不可荒废。
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
    
        set("room_owner", "朱云");
        set("room_name", "猪猪山中别墅");
        set("room_id", "piggm");
        set("room_owner_id", "alert");
        set("room_position", "山路");
}
