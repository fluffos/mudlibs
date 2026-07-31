// SN:AaEa\7Z3:lYXPocX
// File(/data/room/depravity/dayuan.c) of depravity's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "禁入魔界大院");
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

        set("room_owner", "堕落天使");
        set("room_name", "禁入魔界");
        set("room_id", "devil");
        set("room_owner_id", "depravity");
        set("room_position", "树林");
}
