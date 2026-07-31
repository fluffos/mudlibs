// SN:9<7W[6dI0@8TfFW=
// File(/data/room/thread/dayuan.c) of thread's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "怡红院大院");
	set ("long", @LONG
这是一个宽阔的院落，种着各种树木，阳光照下来透过树荫投下
层层影子。一条大路通向里面，踩得非常平滑的，看来是经常有人来
往。 
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/room/playtown/road1",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "杜十娘");
        set("room_name", "怡红院");
        set("room_id", "thread");
        set("room_owner_id", "thread");
        set("room_position", "碎石小道");
}
