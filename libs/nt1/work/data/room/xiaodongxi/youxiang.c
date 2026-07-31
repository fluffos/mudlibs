// SN:=iP=ci4YbFifPXh1
// File(/data/room/xiaodongxi/youxiang.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "ÓÒÏá·¿");
	set ("long", @LONG
ÆËÃæÆËÀ´Ò»¹ÉÀä³¹´Ì¹ÇµÄº®Æø,Õû¼äÎİ×ÓÊÇÒ»¿é¾ŞĞÍÍ¸Ã÷º®±ùµñÔä
¶ø³É,ÊÇĞ¡Ì«±£ÍÂÄÉ´ò×øµÄµØ·½,¾İËµÔÚ´Ë±ù¿ßÖĞ,ÓĞÊÂ°ë¹¦±¶µÄ¹îÒìĞ§
¹û¡£[2;37;0m
LONG );

	set("exits", ([
                "east" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);

        create_door("east", "Ä¾ÃÅ", "west", DOOR_CLOSED);

        setup();

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄĞ¡Îİ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
}
