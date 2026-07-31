// SN:RRbQ2U2>f`lBSOXE
// File(/data/room/xiaodongxi/zhongting.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        object ob;

        set("short", "°®µÄĞ¡ÎİÖĞÍ¥");
	set ("long", @LONG
°®µÄĞ¡ÎİÖ®Ñü£ºÖĞÍ¥¡£×óÅÔÊÇ¿ÍÈË¾Ó×¡µÄÏá·¿£¬ÓÒ±ßÊÇÖ÷ÈËµÄº®
±ùÊÒ£¬ºóÃæÍ¨Íùºó»¨Ô°ºÍÎÔ·¿£¬Ç°ÃæÔòÊÇÒéÊÂÌü£¬Ò»Ö±Í¨ÍùÍ¥Ôº¡£[2;37;0m
LONG );

	set("exits", ([
		"north"  : __DIR__"houyuan",
                "south"  : __DIR__"yishiting",
                "east"   : __DIR__"zuoxiang",
                "west"   : __DIR__"youxiang",
	]));

        set("outdoors", "playertown");

        set("objects", ([
                "/d/room/roomnpc/shouwei" : 1,
        ]));

        create_door("east", "Ä¾ÃÅ", "west", DOOR_CLOSED);
        create_door("west", "Ä¾ÃÅ", "east", DOOR_CLOSED);

        set("no_sleep_room", 1);
        setup();

        ob = present("shou wei", this_object());
        ob->set("coagents", ({
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 1" ]),
                ([ "startroom" : __DIR__"zuowei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 2" ]),
                ([ "startroom" : __DIR__"youwei",
                   "id"        : "shou wei 1" ]),
        }));

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄĞ¡Îİ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ğ¡µÀ");
}

int valid_leave(object me, string dir)
{
        object ob;

        ob = present("shou wei", this_object());
        if (dir != "north" || ! objectp(ob) || ! living(ob))
                return ::valid_leave(me, dir);

        if (ob->is_owner(me))
        {
                message_vision("$NÍäÑü¶Ô$nµÀ£º¡°Çë½ø£¡¡±\n", ob, me);
                return ::valid_leave(me, dir);
        }

        if (present(query("room_owner_id") + " pass", me))
        {
                message_vision("$N¶Ô$nµÀ£º¡°¼´È»ÓĞÖ÷ÈËµÄÊÖÚÍ£¬¾ÍÇë½ø°É¡£¡±\n",
                               ob, me);
                return ::valid_leave(me, dir);
        }

        message_vision("$NÉìÊÖÀ¹×¡$n£¬µÀ£º¡°¶Ô²»Æğ£¬Ã»ÓĞ" +
                       query("room_owner") + "µÄÊÖÚÍ£¬²»¿ÉÉÃ×Ô´³Èë£¡¡±\n", ob, me);
        return 0;
}
