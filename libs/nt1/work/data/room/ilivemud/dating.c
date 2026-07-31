// SN:aZ5NO^bR:_6WL]\U
// File(/data/room/ilivemud/dating.c) of ilivemud's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "×íÎÌÍ¥´óÌü");
	set ("long", @LONG
Õâ¶ùÊÇ°®ÂíµÂºÍ°¬ÂíµÂ½Ó´ı¿ÍÈËµÄµØ·½£¬ÕıÖĞ°Ú×ÅÌ´ÏãÄ¾×öµÄ×À
ÒÎ£¬²àÃæÊÇÆÁ·ç£¬ÌüÌÃÖĞ¹Ò×ÅÁ½¸öÌõ·ù¡£ÉÏÃæĞ´×ÅÕÅ·ÉµÄÌâ×Ö£º¡°Ğ¡
í¬×íÎÌÓûÒ÷Ê«£¬±¦½£»¹ÇÊÙ©¶ÔÁª¡±¡£¶«ÃæÊÇÖ÷ÈËµÄÎÔÊÒ¡£[2;37;0m
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
    
        set("room_owner", "°¬ÂíµÂ");
        set("room_name", "×íÎÌÍ¥");
        set("room_id", "zwt");
        set("room_owner_id", "ilivemud");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
}
