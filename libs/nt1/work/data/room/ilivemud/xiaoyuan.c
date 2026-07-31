// SN:dmbGhAWlTnkO8c1j
// File(/data/room/ilivemud/xiaoyuan.c) of ilivemud's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "×íÎÌÍ¥Ğ¡Ôº");
	set ("long", @LONG
ÕâÀïÊÇÒ»¸ö°²¾²µÄÔº×Ó£¬Ò»½øÃÅ£¬Ö÷ÈËµÄğĞğÄÏòÄã¸ßĞËµÄÎÊºÃ¡°;
ÄãºÃ£¬ÄãºÃ¡±£¬Ê¹ÄãĞÄÇéÀ«È»¿ªÀÊ¡£ÔºÇ½¶¼ÊÇÓÃºì×©Æö³É£¬²»Ëã¸ß£¬;
µ«ÊÇ·Ç³£ÇåË¬ÀûÂä¡£ÔºÖĞ¼¸¿Ã´¹Ö±µÄ°×Ñî£¬ÒşÒşÍ¸³öÖ÷ÈË¸ÕÕı²»°¢µÄ;
ĞÔ¸ñ¡£Ê¹ÄãÓĞÒ»ÖÖËàÈ»Æğ¾´µÄ¸Ğ¾õ¡£´óÌüÃÅ¿ÚµÄÊ÷ÏÂ°Ú·Å×ÅÒ»ÕÅÊ¯ÖÆ
µÄÆåÅÌºÍ¼¸¸öÔ²Ô²µÄÊ¯µÊ£¬ÉÏÃæ°ÚÕßÒ»¾Ö¡°ÕäÁú¡±¡£´©¹ıÔº×Ó;ÓĞÒ»ÉÈ
µñ»¨µÄ²£Á§ÃÅ£¬Í¸¹ıÃÅ¿ÉÒÔ¿´µ½Ö÷ÈË´óÌüÀïÃæµÄÈı¸öò°¾¢ÓĞÁ¦µÄ´ó×Ö
¡°×íÎÌÍ¥¡±¡£[2;37;0m
LONG );

        set("room_key", "1 of ilivemud");
	setup();

	set("exits", ([
                "out"    : "/d/room/playtown/road17",
	]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "°¬ÂíµÂ");
        set("room_name", "×íÎÌÍ¥");
        set("room_id", "zwt");
        set("room_owner_id", "ilivemud");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
}
