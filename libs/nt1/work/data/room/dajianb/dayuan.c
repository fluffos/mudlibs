// SN:DPA8g4Ie5I=eAdF]
// File(/data/room/dajianb/dayuan.c) of dajianb's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "风之居大院");
	set ("long", @LONG
这是一个宽阔的院落，种着各种树木，阳光照下来透过树荫投下
层层影子。一条大路通向里面，踩得非常平滑的，看来是经常有人来
往。 
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/hangzhou/shanlu1",
	]));

        set("outdoors", "hangzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "风二中");
        set("room_name", "风之居");
        set("room_id", "wind");
        set("room_owner_id", "dajianb");
        set("room_position", "山路");
}
