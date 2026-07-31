// Room: /d/shaolin/wuxing2.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

string* dirs = ({"east", "south", "west", "north"});

void create()
{
	set("short", HIB "ÎåĞĞ¶´" NOR);
	set("long", @LONG
[1£»34mÕâÊÇÎåĞĞ¶´¡£Ò»½øÕâÀï£¬Äã¾ÍÏİÔÚÆëÑüÉîµÄË®Àï£¬½Åµ×ÊÇºñ
ºñµÄÓÙÄà£¬Ò»²ÈÉÏÈ¥¾ÍËÉËÉµØÉ¢¿ª£¬»¹´ø³öÒ»´ó´®ÆøÅİÃ°³öË®Ãæ¡£×î¿É²À
µÄÊÇË®ÃæÉÏ²»Ê±Æ®¹ıÀ´Ò»Á½¾ß½şµÃ·¢Ö×µÄ¸¡Ê¬£¬¼¸Ö»ÀÏÊóÔÚÉÏÃæÅÀÉÏÅÀÏÂ£¬
°ÑÊ¬ÌåÒ§µÃÃæÄ¾È«·Ç¡£ËÄ±ÚÓÃ´Ö²ÚµÄÆ¬ÑÒÀİ¶â¶ø³É£¬Ò»¿Å¿ÅË®ÖéÑØ×ÅÇ½±Ú
¹öÏÂÀ´£¬½¦ÔÚË®ÖĞ£®[2£»37£»0m
LONG );
	set("exits", ([
		"east" : __DIR__"wuxing1",
		"south" : __DIR__"wuxing4",
		"west" : __DIR__"wuxing0",
		"north" : __DIR__"wuxing3",
	]));
	set("no_clean_up", 0);
	setup();
}

int check_out(object me)
{
	int metal, wood, water, fire, earth;

	metal = me->query_temp("wuxing/½ğ");
	wood = me->query_temp("wuxing/Ä¾");
	water = me->query_temp("wuxing/Ë®");
	fire = me->query_temp("wuxing/»ğ");
	earth = me->query_temp("wuxing/ÍÁ");

	if ( metal > 0 &&
		metal == wood && metal == water &&
		metal == fire && metal == earth )
	{
		me->delete_temp("wuxing");
		me->move(__DIR__"andao2");
		return (1);
	}
	return (0);
}

int valid_leave(object me, string dir)
{
	int count;

	if (member_array(dir, dirs) != -1)
	{
		if (dir == "east")
		{
//			write("*Ë®ÉúÄ¾*\n");
			count = me->query_temp("wuxing/Ä¾");
			count++;
			me->set_temp("wuxing/Ä¾", count);
			if (check_out(me))
				return notify_fail("ÄãË³ÀûµØ×ß³öÁËÎåĞĞÃÔ¹¬¡£\n");
		}
		else if (dir == "north")
		{
//			write("*Ë®¿Ë»ğ*\n");
			me->delete_temp("wuxing");
			me->move(__DIR__"jianyu1");
			return notify_fail("Äãµô½ø»ú¹Ø£¬ÂäÈëÉ®¼à¡£\n");
		}
	}
	return ::valid_leave(me, dir);
}

