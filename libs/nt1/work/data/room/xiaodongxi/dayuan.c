// SN:A^C6<k0gm3hCm\gP
// File(/data/room/xiaodongxi/dayuan.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "°®µÄÐ¡ÎÝ´óÔº");
	set ("long", @LONG
Ò»¸ö¿íÀ«µÄÔºÂä£¬ËæÒâµÄÖÖ×Å¼¸¸öÒøÐÓÊ÷£¬Ñô¹âÕÕÏÂÀ´Í¸¹ýÊ÷Òñ
Í¶ÏÂ°ß²µµÄÓ°×Ó¡£ºÚÉ«Ë®¾§ÆÌÉèµÄÂ·Í¨ÏòÉî´¦[2;37;0m
LONG );

	set("exits", ([
		"north"  : __DIR__"qianting",
                "out"    : "/d/room/playtown/road15",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄÐ¡ÎÝ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ð¡µÀ");
}
