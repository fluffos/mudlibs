// SN:cb=e\n10TYE5Wd3k
// File(/data/room/xiaodongxi/shufang.c) of xiaodongxi's room
// Create by LUBAN written by Doing Lu

#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "Êé·¿");
	set ("long", @LONG
Ê×ÏÈÓ³ÈëÑÛÁ±µÄÊÇÊé·¿µÄØÒ¶î¡´Ìì¾»É³¡µ¡£ÕâÀïÊÇÐ¡Ì«±£¶ÁÊéÏ°
×ÖµÄµØ·½£¬¸É¾»Õû½à£¬Ä«ÂÌÉ«µÄË®¾§µØ°åÃ÷ÁÁ¿É¼ø¡£ÎÄ·¿ËÄ±¦ÕûÕûÆë
ÆëµÄ°ÚÔÚ×À×ÓÉÏÃæ£¬ÓÐÊ±Ö÷ÈËÒ²»áÔÚÕâÀïÇ©·¢Ò»Ð©ÑûÇëÅóÓÑµÄÇë¼í¡£[2;37;0m
LONG );

	set("exits", ([
		"east" : __DIR__"jusuo",
	]));

        set("sleep_room", 1);
        setup();

        set("room_owner", "Ã¼Ã¼");
        set("room_name", "°®µÄÐ¡ÎÝ");
        set("room_id", "loveer");
        set("room_owner_id", "xiaodongxi");
        set("room_position", "ËéÊ¯Ð¡µÀ");
}

void init()
{
        add_action("do_sign", "sign");
}

int do_sign()
{
        object ob;
        object me;

        me = this_player();

            if (! is_room_owner(me))
                    return notify_fail("ÄãÓÖ²»ÊÇÕâ¶ùµÄÖ÷ÈË£¬ÂÒ¸ã"
                                       "Ê²Ã´£¿\n");

        if (me->is_busy())
                return notify_fail("ÄãÏÖÔÚ»¹Ã¦×ÅÄØ¡£\n");

        message_vision("$N³é¹ýÒ»ÕÅÖ½£¬ÄÃÆð±ÊÀ´£¬ÔÚÉÏÃæ»­·ûËÆ"
                       "µÄÐ´ÁËÐ©¶«Î÷¡£\n", me);
        tell_object(me, "ÄãÐ´ºÃÒ»·ÝÊÖÚÍ¡£\n");

        ob = new("/d/room/roomobj/pass");
        ob->set_name(HIW + me->query("name") + "ÊÖÚÍ" NOR,
                     ({ "pass", query("room_owner_id") + " pass" }));
        ob->set("long", "Ò»ÕÅÓÉ" + me->query("name") + "Ç×±ÊÇ©·¢µÄ" +
                     "ÊÖÚÍ£¬Æ¾½èËüÄã¿ÉÒÔ½ø³ö" + query("room_name") +
                     "¡£\n");
        ob->move(me);
        me->start_busy(4 + random(4));
        return 1;
}
