// SN:U9W]UXY;k\_;EGDA
// File(/data/room/dajiana/houyuan.c) of dajiana's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "后院");
	set ("long", @LONG
这是盘龙山庄的后院，正中一个假山，傲然而立、非常雄伟。下
有一水池，环山而走，悠然不息。东面乃是练武之处，西面是厨房。
LONG );

	set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
	]));

        set("outdoors", "hangzhou");
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "何济公");
        set("room_name", "盘龙山庄");
        set("room_id", "panglong");
        set("room_owner_id", "dajiana");
        set("room_position", "山路");
}
