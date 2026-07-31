// SN:bZ9_=H[Z2:K9bK2b
// File(/data/room/lsm/dayuan.c) of lsm's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "雷神之殿大院");
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

        set("room_owner", "雷斯魔");
        set("room_name", "雷神之殿");
        set("room_id", "lsm");
        set("room_owner_id", "lsm");
        set("room_position", "平原小路");
}
