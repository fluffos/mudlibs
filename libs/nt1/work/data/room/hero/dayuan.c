// SN:cS>E]AW;6lJQ1C2O
// File(/data/room/hero/dayuan.c) of hero's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "英雄会馆大院");
	set ("long", @LONG
这是一个宽阔的院落，种着各种树木，阳光照下来透过树荫投下
层层影子。一条大路通向里面，踩得非常平滑的，看来是经常有人来
往。 
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/city/jiaowai2",
	]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "英雄");
        set("room_name", "英雄会馆");
        set("room_id", "hero");
        set("room_owner_id", "hero");
        set("room_position", "树林");
}
