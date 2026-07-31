// SN:\=\?jLjKN7hTF:T;
// File(/data/room/hongdou/dating.c) of hongdou's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "²Ğ°®¾Ó´óÌü");
	set ("long", @LONG
´óÌüÓ­ÃæÓĞÒ»ÕÅÌ´Ä¾°ËÏÉ×À,Á½±ßÓĞ´ÎĞòµÄ°Ú·Å×ÅÁ½ÅÅÁúÒÎ,ËÄ±Ú
Ğü¹Ò×ÅÃ¨¶ùÇ×ÊÖ»æÖÆµÄÕòÊŞÍ¼¡£ÌüÌÃÖĞ¹Ò×ÅÁ½¸öÌõ·ù¡°Ôø¾­²×º£ÄÑÎª
Ë®¡±¡°³ıÈ´Î×É½²»ÊÇÔÆ¡±¡£[2;37;0m
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
    
        set("room_owner", "ºì¶¹");
        set("room_name", "²Ğ°®¾Ó");
        set("room_id", "xiaohan");
        set("room_owner_id", "hongdou");
        set("room_position", "º®Ë®Ì¶");
}
