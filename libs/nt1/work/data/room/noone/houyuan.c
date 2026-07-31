// SN:E[I>R94SmoA;`DhZ
// File(/data/room/noone/houyuan.c) of noone's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "后院");
	set ("long", @LONG
这是神话传说的后院，正中一个假山，傲然而立、非常雄伟。下
有一水池，环山而走，悠然不息。东面乃是练武之处，西面是厨房。
LONG );

	set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
	]));

        set("outdoors", "huashan");
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "决不拜师");
        set("room_name", "神话传说");
        set("room_id", "legend");
        set("room_owner_id", "noone");
        set("room_position", "山洪瀑布");
}
