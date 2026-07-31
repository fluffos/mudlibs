// SN:N9<8K0glYmem^TU[
// File(/data/room/xiaodongxi/zoudao.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "×ßµÀ");
	set ("long", @LONG
Á¬½ÓÕýÌüºÍ´óÃÅµÄÒ»Ìõ¾«ÇÉµÄ³¤ÀÈ£¬Á½ÅÔ¶¼ÊÇ·ÉÎèµÄÜ·Ü·ÓñÅ®ÔÆ
µñÇ½°å£¬×ÐÏ¸¿´¾¹È»ÊÇÒ»Ð©ÈáÖÐÓÐ¸ÕµÄÎä¹¦ÕÐÊ½¡£[2;37;0m
LONG );

	set("exits", ([
		"north"  : __DIR__"yingke",
                "south"  : __DIR__"qianting",
	]));

        set("gate", "close");

        set("objects", ([
                "/d/room/roomnpc/yahuan" : 1,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄÐ¡ÎÝ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ð¡µÀ");
}

void init()
{
        add_action("do_push", "push");
        add_action("do_close", "close");
}

int do_push(string arg)
{
        object me;
        object room;

        if (query("gate") == "open")
                return notify_fail("´óÃÅ¿ª×ÅÄØ£¬Äã»¹ÍÆÊ²Ã´£¿\n");

        me = this_player();
        message("vision",  "ÄãÓÃÁ¦ÍÆÁËÍÆ´óÃÅ£¬¾ÍÌý´óÃÅ¡°Ö¨Ñ½Ñ½¡±µÄ±»ÈËÍÆ¿ªÁË¡£\n",
                           this_object());
    
        room = get_object(__DIR__"qianting");
        message("vision", "´óÃÅ¡°Ö¨Ñ½Ñ½¡±µÄ±»ÈËÍÆ¿ªÁË¡£\n", room);
        set("gate", "open");
        set("exits/south", __DIR__"qianting");
        room->set("exits/north", __FILE__);
        room->set("gate", "open");
        remove_call_out("do_close");
        call_out("do_close", 10, 0, 1);
        return 1;
}

int do_close(string arg, int n)
{
        object me;
        object room;

        if (query("gate") == "close")
                return notify_fail("´óÃÅ¹Ø×ÅÄØ£¬Äã»¹ÔÙ¹ØÒ»±é£¿\n");

        if (! n)
        {
                me = this_player();
                message("vision", me->name() + "×ßÉÏÇ°È¥£¬ÓÃÁ¦ºÏÉÏ´óÃÅ¡£\n",
                        this_object());
        } else
        {
                message("vision", "´óÃÅ¡°Ö¨Ñ½Ñ½¡±µÄ±»ÈË¹ØÉÏÁË¡£\n",
                        this_object());
        }

        room = get_object(__DIR__"qianting");
        message("vision", "´óÃÅ¡°Ö¨Ñ½Ñ½¡±µÄ±»ÈË¹ØÉÏÁË¡£\n", room);
        set("gate", "close");
        delete("exits/south");
        room->set("gate", "close");
        room->delete("exits/north");
        return 1;
}

