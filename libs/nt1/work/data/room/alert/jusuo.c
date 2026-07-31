// SN::ObWQSPe622<21Ii
// File(/data/room/alert/jusuo.c) of alert's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "居所");
	set ("long", @LONG
这就是猪猪山中别墅主人朱云休息、读书的地方。楼上就是主人
的卧室，西面则是书房。 
LONG );

	set("exits", ([
		"up"   : __DIR__"woshi",
                "west" : __DIR__"shufang",
	]));

        set("no_sleep_room", 1);
        setup();

        set("KEY_DOOR", ([
                "exit" : "east",
                "room" : __DIR__"huayuan",
        ]));
    
        set("room_owner", "朱云");
        set("room_name", "猪猪山中别墅");
        set("room_id", "piggm");
        set("room_owner_id", "alert");
        set("room_position", "山路");
}
