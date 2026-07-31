// SN:5V6n?o0ST;7J=_kX
// File(/data/room/kfcc/houyuan.c) of kfcc's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "后院");
	set ("long", @LONG
这是小肯的家的后院，正中一个假山，傲然而立、非常雄伟。下
有一水池，环山而走，悠然不息。东面乃是练武之处，西面是厨房。
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

        set("room_owner", "肯德氏");
        set("room_name", "小肯的家");
        set("room_id", "kfcc");
        set("room_owner_id", "kfcc");
        set("room_position", "碎石小道");
}
