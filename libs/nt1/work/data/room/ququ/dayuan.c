// SN:WZ3>O[DZX3RO\IBI
// File(/data/room/ququ/dayuan.c) of ququ's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天之蛆巢大院");
	set ("long", @LONG
这是一个宽阔的院落，种着各种树木，阳光照下来透过树荫投下
层层影子。一条大路通向里面，踩得非常平滑的，看来是经常有人来
往。 
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/city/mingren",
	]));

        set("outdoors", "unknow");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "天蛆");
        set("room_name", "天之蛆巢");
        set("room_id", "quququ");
        set("room_owner_id", "ququ");
        set("room_position", "名人堂");
}
