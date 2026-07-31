// File(/data/room/luoyuna/dayuan.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "小白居大院");
	set("long", "这是一个宽阔的院落，种着各种树木，阳光照下来透过树荫投下
层层影子。一条大路通向里面，踩得非常平滑的，看来是经常有人来
往。
");

	set("exits", ([
		"north"  : __DIR__"qianting",
		"out"    : "/data/hell/4/wulinsi22",
	]));

	set("outdoors", "hell");
	set("no_sleep_room", 1);
	set("valid_startroom", 1);
	setup();

        set("room_owner", "大白");
        set("room_name", "小白居");
        set("room_OWNER_id", "luoyuna");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "武林四街");
}
