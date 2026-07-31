// SN:iPQJSl_<;CXQ@TDZ
// File(/data/room/shirley/xiaoyuan.c) of shirley's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "ÐÖµÜÐ¡Ôº");
	set ("long", @LONG
ÕâÀïÊÇÒ»¼ä±ðÖÂµÄÐ¡Ôº[2;37;0m
LONG );

        set("room_key", "1 of shirley");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road5",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "Ñ©Àò");
        set("room_name", "ÐÖµÜ");
        set("room_id", "shirley");
        set("room_owner_id", "shirley");
        set("room_position", "ËéÊ¯Ð¡µÀ");
}
