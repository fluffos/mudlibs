// SN:1R0FhIiRa953Q`4c
// File(/data/room/kfcc/yanwu2.c) of kfcc's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "小肯的家演武厅");
	set ("long", @LONG
这是小肯的家的演武厅，有时有些江湖朋友来会，想一试身手，
就在这里比武较量。 
LONG );

	set("exits", ([
                "east" : __DIR__"yishiting",
	]));

        set("objects", ([
                "/clone/weapon/zhubang" : 1,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/mudao"   : 1,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "肯德氏");
        set("room_name", "小肯的家");
        set("room_id", "kfcc");
        set("room_owner_id", "kfcc");
        set("room_position", "碎石小道");
}
