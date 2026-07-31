// SN:6lm?`O05Dj?M7;Ue
// File(/data/room/xiaodongxi/yishiting.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "ÒéÊÂÌü");
	set ("long", @LONG
Ğ¡Ì«±£ºÍÉñÃØµÄÖØÒªÈËÎïÉÌÁ¿´óÊÂÖ®´¦¡£ÕıÃæÓĞÒ»ÕÅÌ´Ä¾°ËÏÉ×À,
Á½±ßÓĞ´ÎĞòµÄ°Ú·Å×ÅÁ½ÅÅÁúÒÎ,ËÄ±ÚĞü¹Ò×ÅÃ¼Ã¼Ç×ÊÖ»æÖÆµÄÊËÅ®Í¼¡£Ìü
ÌÃÖĞ¹Ò×ÅÁ½¸öÌõ·ù¡°º®·¼ÁôÕÕ»êÓ¦×¤¡±*_*¡°ËªÓ¡´«ÉñÃÎÒ²¿Õ¡±£¬¶«Î÷
Í¨ÍùÑİÎäÌü¡£[2;37;0m
LONG );

	set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
		"north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
	]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄĞ¡Îİ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
}
