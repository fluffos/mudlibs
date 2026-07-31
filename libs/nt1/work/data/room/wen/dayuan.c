// SN:XhG4b@Ubnhei14Hj
// File(/data/room/wen/dayuan.c) of wen's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "听雨轩大院");
	set ("long", @LONG
[1;34m曾羡雨樵举孤杯，
    而今寂寞可知悔?
    默对夜色凄凉月,
    何日他乡故人归!
    相思鹤侣已分飞,
    惊梦方知泪曾挥!
    [1;31m-----------[1;33m青衣修罗题[2;37;0m
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/room/playtown/road8",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "叶落听风");
        set("room_name", "听雨轩");
        set("room_id", "wen");
        set("room_owner_id", "wen");
        set("room_position", "三岔口");
}
