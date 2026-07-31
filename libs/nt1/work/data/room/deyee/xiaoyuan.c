// SN:Aa02XVEM@EVR40AF
// File(/data/room/deyee/xiaoyuan.c) of deyee's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "无影门小院");
	set ("long", @LONG
一个雅致的篱笆小院，这里懒懒散散的随意种着一些翠竹，非常
幽静。阳光照下来透过竹叶间隙投下斑驳的影子。北面有一个绿色小
竹屋，竹门轻掩着。[2;37;0m
LONG );

        set("room_key", "1 of deyee");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road2",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "止水");
        set("room_name", "无影门");
        set("room_id", "deyee");
        set("room_owner_id", "deyee");
        set("room_position", "碎石小道");
}
