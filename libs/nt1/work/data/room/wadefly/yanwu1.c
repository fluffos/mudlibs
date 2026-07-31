// SN:ff4m6Y]=UgmAJ6jU
// File(/data/room/wadefly/yanwu1.c) of wadefly's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "黯幽灵演武厅");
	set ("long", @LONG
这是黯幽灵的演武厅，有时有些江湖朋友来会，想一试身手，就
在这里比武较量。 
LONG );

	set("exits", ([
                "west" : __DIR__"yishiting",
	]));

        set("objects", ([
                "/clone/weapon/zhubang" : 1,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/mudao"   : 1,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "黯幽灵");
        set("room_name", "黯幽灵");
        set("room_id", "wadefly");
        set("room_owner_id", "wadefly");
        set("room_position", "碎石小道");
}
