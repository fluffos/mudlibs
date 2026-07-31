// SN:nm2j::QgZ@KkoNiO
// File(/data/room/deyee/dating.c) of deyee's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "无影门大厅");
	set ("long", @LONG
这里是无影门的猫儿接待知己死党的场所。大凡好朋友来约见猫
儿，少不得在这里寒暄叙话，了尽相思之情。厅堂中挂着两个条幅“
寒芳留照魂应驻”*_*“霜印传神梦也空”。[2;37;0m
LONG );

	setup();

	set("exits", ([
                "east"   : __DIR__"woshi",
		"north"  : __DIR__"houyuan",
	]));

        create_door("east", "木门", "west", DOOR_CLOSED);

        set("no_sleep_room", 1);

        set("KEY_DOOR", ([
                "exit" : "south",
                "room" : __DIR__"xiaoyuan",
        ]));
    
        set("room_owner", "止水");
        set("room_name", "无影门");
        set("room_id", "deyee");
        set("room_owner_id", "deyee");
        set("room_position", "碎石小道");
}
