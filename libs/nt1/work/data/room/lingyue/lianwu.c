// SN:[XNCI`l6MS<GBLQ1
// File(/data/room/lingyue/lianwu.c) of lingyue's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "练武场");
	set ("long", @LONG
此处便是雪月楼的练武场，人在江湖，武功万万不可荒废。 
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
    
        set("room_owner", "灵月");
        set("room_name", "雪月楼");
        set("room_id", "xueyue");
        set("room_owner_id", "lingyue");
        set("room_position", "青砖路");
}
