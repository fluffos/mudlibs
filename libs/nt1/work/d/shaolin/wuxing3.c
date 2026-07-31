// Room: /d/shaolin/wuxing3.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

string* dirs = ({"east", "south", "west", "north"});

void create()
{
	set("short", HIR "ÎåĞĞ¶´" NOR);
	set("long", @LONG
[1£»31mÕâÊÇÎåĞĞ¶´¡£½øÀ´¶Ù¾õÒ»¹ÉÈÈÀËÆËÃæ¶øÀ´£¬³åµÃÄã²îµãÔÎÁË
¹ıÈ¥¡£ËÄÖÜÒ»Æ¬Í¨ºì£¬µØÃæÉÏÃ°×ÅË¿Ë¿°×Æø£¬½Åµ×¾çÁÒµÄÖËÍ´Ê¹Äã¼¸ºõÁ¢
½Å²»×¡¡£ÈÈ·ç´ø×ÅÂ¡Â¡¾ŞÏì³å»÷×Å¶ú¹Ä£¬ÁîÄã¾õµÃÖÃÉíºéÂ¯Ö®ÖĞ£¬È«ÉíµÄ
Ë®·Ö¶¼ÔÚ±»Ò»µÎµÎµØ¿¾¸É¡£Ç½½ÇÉÏ¼¸¾ß¿İ²ñ°ãµÄ¸ÉÊ¬¾ÍÖ¤Ã÷ÁËÕâÒ»µã¡£[
2£»37£»0m
LONG );
	set("exits", ([
		"east" : __DIR__"wuxing1",
		"south" : __DIR__"wuxing2",
		"west" : __DIR__"wuxing0",
		"north" : __DIR__"wuxing4",
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
		if (dir == "north")
		{
//			write("*»ğÉúÍÁ*\n");
			count = me->query_temp("wuxing/ÍÁ");
			count++;
			me->set_temp("wuxing/ÍÁ", count);
			if (check_out(me))
				return notify_fail("ÄãË³ÀûµØ×ß³öÁËÎåĞĞÃÔ¹¬¡£\n");
		}
		else if (dir == "west")
		{
//			write("*»ğ¿Ë½ğ*\n");
			me->delete_temp("wuxing");
			me->move(__DIR__"jianyu1");
			return notify_fail("Äãµô½ø»ú¹Ø£¬ÂäÈëÉ®¼à¡£\n");
		}
	}
	return ::valid_leave(me, dir);
}

