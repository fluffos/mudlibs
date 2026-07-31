// SN:]MfaDR3>eg13m\Kc
// File(/data/room/tanger/yanwu1.c) of tanger's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "唐二居演武厅");
	set ("long", @LONG
这是唐二居的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "唐二");
        set("room_name", "唐二居");
        set("room_id", "tangr");
        set("room_owner_id", "tanger");
        set("room_position", "碎石小道");
}
