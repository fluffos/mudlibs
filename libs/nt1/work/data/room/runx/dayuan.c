// SN:=m9Mdh@]kg^C6fhQ
// File(/data/room/runx/dayuan.c) of runx's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "魔神宫大院");
	set ("long", @LONG
这是一个宽阔的院落，种着各种树木，阳光照下来透过树荫投下
层层影子。一条大路通向里面，踩得非常平滑的，看来是经常有人来
往。 
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/xiakedao/xkroad3",
	]));

        set("outdoors", "xiakedao");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "魔神");
        set("room_name", "魔神宫");
        set("room_id", "runx");
        set("room_owner_id", "runx");
        set("room_position", "平原小路");
}
