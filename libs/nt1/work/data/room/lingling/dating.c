// SN:EbgIeZb<EJEW@V_:
// File(/data/room/lingling/dating.c) of lingling's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "ôáÇä¾Ó´óÌü");
	set ("long", @LONG
[1;36mÄã×ß½øÁËÒ»¼äÊæÊÊµÄÄ¾Îİ£¬Õâ¾ÍÊÇôáÇä¾ÓÖ÷ÈËÄ½ÈİôáÓ­ËÍ¿Í
    ÈËµÄµØ·½¡£×ĞÏ¸µÄ¹Û²ìÎİÀïµÄ»·¾³£¬°ÚÉèÖø¼¸ÕÅÒÎ×ÓºÍ¼òµ¥
    µÄ¼ÒÊÎ£¬Ç½±ßµÄ»ğÂ¯Àï»¹ÓĞÄ¾²ÄÔÚÈ¼ÉÕÖø£¬ÈÃÕâÀïµÄ¸Ğ¾õÎÂ
    Å¯²»ÉÙ£¬Í¸¹ı´°»§ÏòÎİºóÍûÈ¥£¬¿ÉÒÔ¿´µ½Ò»Æ¬ÖÖÂúÆæÒì»¨¶ä
    µÄºóÔº£¬ÈÃÈË°ÑÂ·ÉÏµÄÆ£±¹ÍüµÄÒ»Ç¬¶ş¾»¡£[2;37;0m
LONG );

	setup();

	set("exits", ([
                "east"   : __DIR__"woshi",
		"north"  : __DIR__"houyuan",
	]));

        create_door("east", "Ä¾ÃÅ", "west", DOOR_CLOSED);

        set("no_sleep_room", 1);

        set("KEY_DOOR", ([
                "exit" : "south",
                "room" : __DIR__"xiaoyuan",
        ]));
    
        set("room_owner", "Ä½Èİôá");
        set("room_name", "ôáÇä¾Ó");
        set("room_id", "ling");
        set("room_owner_id", "lingling");
        set("room_position", "É½Â·");
}
