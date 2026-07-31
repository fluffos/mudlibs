// SN:UQFilJ2HDA?m?=cm
// File(/data/room/wship/houyuan.c) of wship's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "后院");
	set ("long", @LONG
这是猪猪海景别墅的后院，正中一个假山，傲然而立、非常雄伟。
下有一水池，环山而走，悠然不息。东面乃是练武之处，西面是厨房。
LONG );

	set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
	]));

        set("outdoors", "xiakedao");
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "溟剑");
        set("room_name", "猪猪海景别墅");
        set("room_id", "villas");
        set("room_owner_id", "wship");
        set("room_position", "南海之滨");
}
