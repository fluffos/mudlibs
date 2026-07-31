// SN:ZU6b1aEi__HYfO8@
// File(/data/room/china/houyuan.c) of china's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "后院");
	set ("long", @LONG
这是长乐之家的后院，正中一个假山，傲然而立、非常雄伟。下
有一水池，环山而走，悠然不息。东面乃是练武之处，西面是厨房。
LONG );

	set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
	]));

        set("outdoors", "suzhou");
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "段盛");
        set("room_name", "长乐之家");
        set("room_id", "tomhome");
        set("room_owner_id", "china");
        set("room_position", "青石官道");
}
