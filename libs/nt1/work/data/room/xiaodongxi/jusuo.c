// SN:3ZXhGOn`9>E[8<Yd
// File(/data/room/xiaodongxi/jusuo.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "¾ÓËù");
	set ("long", @LONG
°®µÄĞ¡ÎİÖ÷ÈËĞİÏ¢£¬¶ÁÊéµÄµØ·½¡£Ë³×ÅÍÖÔ²ĞÎµÄºìÄ¾Â¥ÌİÉÏÈ¥¾Í
ÊÇÎÂÜ°µÄĞ¡ÎÑ£¬Î÷ÃæÔòÊÇÊé·¿¡£[2;37;0m
LONG );

	set("exits", ([
		"up"   : __DIR__"woshi",
                "west" : __DIR__"shufang",
	]));

        set("no_sleep_room", 1);
        setup();

        set("KEY_DOOR", ([
                "exit" : "east",
                "room" : __DIR__"huayuan",
        ]));
    
        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄĞ¡Îİ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
}
