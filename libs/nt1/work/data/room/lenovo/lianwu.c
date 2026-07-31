// SN:U4V\genQTkiQ[QU`
// File(/data/room/lenovo/lianwu.c) of lenovo's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是叹息谷的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "huashan");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "联想");
        set("room_name", "叹息谷");
        set("room_id", "sighh");
        set("room_owner_id", "lenovo");
        set("room_position", "山洪瀑布");
}
