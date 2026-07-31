// SN:nWiKYb0FegN3aHm6
// File(/data/room/xnx/dayuan.c) of xnx's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "霍格沃茨大院");
	set ("long", @LONG
铁栏门上面标着“九又四分之三站台”。一辆鲜红的蒸汽机车正
在一个人山人海的站台静待启程。
    车头正中一块标志鲜明地写着“霍格瓦彻号特快列车，十一点正
发车几个大字。
    蒸汽机车喷出的汽雾在谈天说地的人群的头上聚集起来，而各色
的猫儿在人们的脚旁鞋边转来转去。
    猫头鹰们则以一种令人不快的方式相互叫嚣着。[2;37;0m
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/room/playtown/road3",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "绛珠草");
        set("room_name", "霍格沃茨");
        set("room_id", "hgwc");
        set("room_owner_id", "xnx");
        set("room_position", "碎石小道");
}
