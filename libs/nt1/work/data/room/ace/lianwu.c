// SN:=VLH_8iHhBBPKPHP
// File(/data/room/ace/lianwu.c) of ace's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是真爱居的练武场，人在江湖，武功万万不可荒废。 
LONG );

	set("exits", ([
                "west" : __DIR__"houyuan",
	]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "unknow");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "千王之王");
        set("room_name", "真爱居");
        set("room_id", "ace");
        set("room_owner_id", "ace");
        set("room_position", "名人堂");
}
