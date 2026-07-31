// SN:]HMPX56?Y?ATA4i=
// File(/data/room/xiaodongxi/chashi.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "²èÊÒ");
	set ("long", @LONG
Ò»¸öÁáççĞ¡ÇÉµÄ²èÊÒ£¬ºÜÊÇÏÔµÃ¾«ÖÂ¡£ÕıÖĞÓĞÒ»×ÏÌ´Ä¾²è¼¸£¬±ß
ÉÏÕ¾×ÅÁ½¸öÃ¼Ä¿ÇåĞãµÄĞ¡Ñ¾»·£¬Ğ¦Ó¯Ó¯µÄ¿´×ÅÄã£¬µÈ×ÅÖ÷ÈËµÄ´«»½¡£[2;37;0m
LONG );

	set("exits", ([
		"west"  : __DIR__"yingke",
	]));

        set("objects", ([
                "/d/room/roomnpc/teagirl" : 2,
        ]));

        create_door("west", "Ä¾ÃÅ", "east", DOOR_CLOSED);

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄĞ¡Îİ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
}
