// SN:=Y2:N>\]RTLGj:77
// File(/data/room/gabriel/yanwu1.c) of gabriel's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "伊甸园演武厅");
	set ("long", @LONG
这是伊甸园的演武厅，有时有些江湖朋友来会，想一试身手，就
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

        set("room_owner", "加百列");
        set("room_name", "伊甸园");
        set("room_id", "eden");
        set("room_owner_id", "gabriel");
        set("room_position", "青砖路");
}
