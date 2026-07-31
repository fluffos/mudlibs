// SN:gCemAM?TRh5DDL?G
// File(/data/room/xnx/yanwu1.c) of xnx's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "霍格沃茨演武厅");
	set ("long", @LONG
一间病房里，几张张铺着白色被单的床，旁边有一张桌子，上面
堆的糖果高得够开一间糖果店了。靠墙的柜子里摆满了各式各样的药
瓶子。[2;37;0m
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

        set("room_owner", "绛珠草");
        set("room_name", "霍格沃茨");
        set("room_id", "hgwc");
        set("room_owner_id", "xnx");
        set("room_position", "碎石小道");
}
