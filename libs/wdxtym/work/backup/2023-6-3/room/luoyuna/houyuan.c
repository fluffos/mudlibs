// File(/data/room/luoyuna/houyuan.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "后院");
	set("long", "这是小白居的后院，正中一个假山，傲然而立、非常雄伟。下有
一水池，环山而走，悠然不息。东面乃是练武之处，西面是厨房。
");

	set("exits", ([
		"south" : __DIR__"zhongting",
		"north" : __DIR__"huayuan",
		"east"  : __DIR__"lianwu",
		"west"  : __DIR__"chufang",
	]));

	set("outdoors", "hell");
	set("no_sleep_room", 1);
	setup();

        set("room_owner", "大白");
        set("room_name", "小白居");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "武林四街");
}
