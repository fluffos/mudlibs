// SN:C`d5XA\IeF?ik[V2
// File(/data/room/yundanfq/houyuan.c) of yundanfq's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "后院");
	set ("long", @LONG
这是创世神殿的后院，正中一个假山，傲然而立、非常雄伟。下
有一水池，环山而走，悠然不息。东面乃是练武之处，西面是厨房。
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

        set("room_owner", "渡云");
        set("room_name", "创世神殿");
        set("room_id", "godhall");
        set("room_owner_id", "yundanfq");
        set("room_position", "平原小路");
}
