// SN:18R^\HElPi[9_EH:
// File(/data/room/uriel/dayuan.c) of uriel's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天堂大院");
	set ("long", @LONG
这是一个宽阔的院落，种着各种树木，阳光照下来透过树荫投下
层层影子。一条大路通向里面，踩得非常平滑的，看来是经常有人来
往。 
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/room/playtown/road10",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "乌里叶");
        set("room_name", "天堂");
        set("room_id", "heaven");
        set("room_owner_id", "uriel");
        set("room_position", "青砖路");
}
