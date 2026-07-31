// Room: /d/shaolin/wuxing4.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

string* dirs = ({"east", "south", "west", "north"});

void create()
{
	set("short", HIW "ÎåĞĞ¶´" NOR);
	set("long", @LONG
[1£»37mÕâÊÇÎåĞĞ¶´¡£µØÃæÊÇÄàÍİµØ£¬²ÈÉÏÈ¥°¼Í¹²»Æ½¡£ËÄ±ÚÒ²¶¼ÊÇ
ÍÁÇ½Öş³É£¬ÃşÉÏÈ¥Ïàµ±¸ÉÔï£¬Ê±¶ø»¹»áµôÏÂÒ»´ó¿é»ÒÍÁÀ´¡£´ÓÇ½½Ç»¹ÄÜ¿´
µ½Ò»Ğ©ÀÏÊó¶´¡£µØÃæÓĞÊ±»áÂ¡ÆğÒ»³¤Ìõ£¬ËÆºõÓĞÊ²Ã´¶«Î÷´ÓÍÁÏÂ×êÁË¹ıÈ¥¡£
[2£»37£»0m
LONG );
	set("exits", ([
		"east" : __DIR__"wuxing1",
		"south" : __DIR__"wuxing3",
		"west" : __DIR__"wuxing0",
		"north" : __DIR__"wuxing2",
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
		if (dir == "west")
		{
//			write("*ÍÁÉú½ğ*\n");
			count =  me->query_temp("wuxing/½ğ");
			count++;
			me->set_temp("wuxing/½ğ", count);
			if (check_out(me))
				return notify_fail("ÄãË³ÀûµØ×ß³öÁËÎåĞĞÃÔ¹¬¡£\n");
		}
		else if (dir == "north")
		{
//			write("*ÍÁ¿ËË®*\n");
			me->delete_temp("wuxing");
			me->move(__DIR__"jianyu1");
			return notify_fail("Äãµô½ø»ú¹Ø£¬ÂäÈëÉ®¼à¡£\n");
		}
	}
	return ::valid_leave(me, dir);
}

