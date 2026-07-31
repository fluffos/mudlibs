// SN:ZD=?SbTSH^2\gPc7
// File(/data/room/lotus/yanwu2.c) of lotus's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "莲花演武厅");
	set ("long", @LONG
这是莲花的演武厅，有时有些江湖朋友来会，想一试身手，就在
这里比武较量。 
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

        set("room_owner", "青莲剑歌");
        set("room_name", "莲花");
        set("room_id", "lotus");
        set("room_owner_id", "lotus");
        set("room_position", "碎石小道");
}
