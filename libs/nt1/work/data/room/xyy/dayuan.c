// SN:kR[dNc=^Z<LoR@A9
// File(/data/room/xyy/dayuan.c) of xyy's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "歪歪居大院");
	set ("long", @LONG
这是一个宽阔的院落，种着各种树木，阳光照下来透过树荫投下
层层影子。一条大路通向里面，踩得非常平滑的，看来是经常有人来
往。 
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/city/jiaowai3",
	]));

        set("outdoors", "yangzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "段歪歪");
        set("room_name", "歪歪居");
        set("room_id", "xyy");
        set("room_owner_id", "xyy");
        set("room_position", "树林");
}
