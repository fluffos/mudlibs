// SN:eC<NR8I<b7LA:LJb
// File(/data/room/moppet/xiaoyuan.c) of moppet's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "烟竹小筑小院");
	set ("long", @LONG
一个雅致的篱笆小院，懒懒散散的随意种着一些翠竹，非常幽静,
风儿一起就能听到叶子沙沙作响。阳光照下来透过竹叶间隙投下斑驳
的影子。北面有一个绿色小竹屋，竹门轻掩着。[2;37;0m
LONG );

        set("room_key", "1 of moppet");
	setup();

	set("exits", ([
                "out"    : "/d/xiakedao/haibin",
	]));

        set("outdoors", "xiakedao");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "琉璃娃娃");
        set("room_name", "烟竹小筑");
        set("room_id", "moppet");
        set("room_owner_id", "moppet");
        set("room_position", "南海之滨");
}
