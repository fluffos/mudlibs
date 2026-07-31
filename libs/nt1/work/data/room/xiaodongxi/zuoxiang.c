// SN:iG>E6jjHZik4TCgW
// File(/data/room/xiaodongxi/zuoxiang.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "×óÏá·¿");
	set ("long", @LONG
°®µÄĞ¡ÎİµÄ¿Í·¿¡£´°ÏÂ,·ÅÖÃ×Å¹ÅÆÓµÄÁú·ï×ÏÌ´Ä¾µñ´²,Æ½ÆÌ×ÅÒ»
Ï®ÒøÉ«ĞåÃ¨µÄÑ©±»,Ã»ÓĞÒ»Ë¿ñŞÖå¡£ÅÔ±ßÓĞÒ»¸ö¾«ÖÂµÄÊá×±Ì¨,Ò»ÃæÍ­
¾µÕıÓ³×ÅÃ¼Ä¿ÇåĞãµÄÄã.....[2;37;0m
LONG );

	set("exits", ([
                "west" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);
        set("outdoors", "playertown");

        create_door("west", "Ä¾ÃÅ", "east", DOOR_CLOSED);

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄĞ¡Îİ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
}
