// SN:\;X:JIiWOROO=QE[
// File(/data/room/kyjh/yanwu1.c) of kyjh's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "爱巢演武厅");
	set ("long", @LONG
这是爱巢的演武厅，有时有些江湖朋友来会，想一试身手，就在
这里比武较量。 
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

        set("room_owner", "快意江湖");
        set("room_name", "爱巢");
        set("room_id", "home");
        set("room_owner_id", "kyjh");
        set("room_position", "三岔口");
}
