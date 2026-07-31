// SN:G>L7TaO3P9fFnEoK
// File(/data/room/fireice/houyuan.c) of fireice's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "后院");
	set ("long", @LONG
这是云闲居的后院，正中一个假山，傲然而立、非常雄伟。下有
一水池，环山而走，悠然不息。东面乃是练武之处，西面是厨房。 
LONG );

	set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
	]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "水灵");
        set("room_name", "云闲居");
        set("room_id", "king");
        set("room_owner_id", "fireice");
        set("room_position", "树林");
}
