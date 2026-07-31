// SN:a1^f8m<5jcOO12G9
// File(/data/room/als/houyuan.c) of als's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "后院");
	set ("long", @LONG
这是海德酒店的后院，正中一个假山，傲然而立、非常雄伟。下
有一水池，环山而走，悠然不息。东面乃是练武之处，西面是厨房。
LONG );

	set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
	]));

        set("outdoors", "unknow");
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "灌汤包子");
        set("room_name", "海德酒店");
        set("room_id", "hotl");
        set("room_owner_id", "als");
        set("room_position", "名人堂");
}
