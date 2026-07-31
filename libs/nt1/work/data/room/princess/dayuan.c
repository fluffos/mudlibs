// SN:j=H4bT2_<GcNGj8A
// File(/data/room/princess/dayuan.c) of princess's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天空之城大院");
	set ("long", @LONG
这是一个宽阔的院落，种着各种树木，阳光照下来透过树荫投下
层层影子。一条大路通向里面，踩得非常平滑的，看来是经常有人来
往。 
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/xiakedao/haibin",
	]));

        set("outdoors", "xiakedao");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "新月");
        set("room_name", "天空之城");
        set("room_id", "skyheaven");
        set("room_owner_id", "princess");
        set("room_position", "南海之滨");
}
