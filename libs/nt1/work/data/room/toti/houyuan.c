// SN:X\AD<;U\>^9\oT^J
// File(/data/room/toti/houyuan.c) of toti's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "后院");
	set ("long", @LONG
这是盘龙居的后院，正中一个假山，傲然而立、非常雄伟。下有
一水池，环山而走，悠然不息。东面乃是练武之处，西面是厨房。 
LONG );

	set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "一笑挥刀");
        set("room_name", "盘龙居");
        set("room_id", "panlongju");
        set("room_owner_id", "toti");
        set("room_position", "碎石小道");
}
