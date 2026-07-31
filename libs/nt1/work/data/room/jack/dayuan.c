// SN:WTP:HdZGCNi@BUJZ
// File(/data/room/jack/dayuan.c) of jack's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "胖子的家大院");
	set ("long", @LONG
这是一个宽阔的院落，种着各种树木，阳光照下来透过树荫投下
层层影子。一条大路通向里面，踩得非常平滑的，看来是经常有人来
往。 
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/room/playtown/road2",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "段胖子");
        set("room_name", "胖子的家");
        set("room_id", "jack");
        set("room_owner_id", "jack");
        set("room_position", "碎石小道");
}
