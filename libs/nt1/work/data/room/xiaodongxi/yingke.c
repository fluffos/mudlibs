// SN:3m1hIR6^89DLRZAk
// File(/data/room/xiaodongxi/yingke.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "°®µÄĞ¡ÎİÓ­¿ÍÌü");
	set ("long", @LONG
ÕâÀïÊÇ°®µÄĞ¡ÎİµÄÖ÷ÈËĞ¡Ì«±£½Ó´ıÖª¼ºËÀµ³µÄ³¡Ëù¡£´ó·²ºÃÅóÓÑ
À´Ô¼¼û£¬ÉÙ²»µÃÔÚÕâÀïº®êÑĞğ»°£¬ÁË¾¡ÏàË¼Ö®Çé¡£¶«ÃæÊÇÒ»¸ö²èÊÒ¡ª
¡ª¡´ÜøÏã¡µ£¬ÊÇÅ®Ö÷ÈËÃ¼Ã¼ÅãÍ¬¿ÍÈËÆ·³¢ÌìÏÂÃû²èÖ®´¦¡£[2;37;0m
LONG );

	set("exits", ([
		"north"  : __DIR__"yishiting",
                "south"  : __DIR__"zoudao",
                "east"   : __DIR__"chashi",
	]));

        create_door("east", "Ä¾ÃÅ", "west", DOOR_CLOSED);

        set("objects", ([
                "/d/room/roomnpc/yahuan" : 2,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄĞ¡Îİ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
}
