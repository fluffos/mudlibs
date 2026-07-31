// SN:QdaiQII;^Y7]o89J
// File(/data/room/remiel/houyuan.c) of remiel's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "后院");
	set ("long", @LONG
这是天使禁猎区的后院，正中一个假山，傲然而立、非常雄伟。
下有一水池，环山而走，悠然不息。东面乃是练武之处，西面是厨房。
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

        set("room_owner", "雷米尔");
        set("room_name", "天使禁猎区");
        set("room_id", "angelcage");
        set("room_owner_id", "remiel");
        set("room_position", "青砖路");
}
