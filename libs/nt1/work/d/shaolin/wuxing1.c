// Room: /d/shaolin/wuxing1.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

string* dirs = ({"east", "south", "west", "north"});

void create()
{
	set("short", HIG "ÎåĞĞ¶´" NOR);
	set("long", @LONG
[1£»32mÕâÊÇÎåĞĞ¶´¡£ÕâÀïµØÃæÏà¶Ô±È½Ï¸ÉÔïĞ©£¬ËÄ±ÚÓÉ¿íºñµÄÄ¾°å
ÑÏÑÏÊµÊµµÄµØ·âÁËÆğÀ´£¬ßµÉÏÈ¥·¢³ö³ÁÃÆµÄóÆóÆÉù£¬¿´À´²»ÊÇÊµĞÄµÄ¾ÍÊÇ
ÓĞ¼¸³ßºñ£¬Ã»ÓĞ¸«ÔäµÈÀûÆ÷ĞİÏëÅü¿ªËüÃÇ¡£²»¹ıÄã»¹ÊÇÏëÏÂÊÖÊÔÒ»ÊÔ£¬Ï£
ÍûÄÜ´ÓÕâÀï´ò¿ªÈ±¿Ú¡£[2£»37£»0m
LONG );
	set("exits", ([
		"east" : __DIR__"wuxing0",
		"south" : __DIR__"wuxing3",
		"west" : __DIR__"wuxing4",
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
		if (dir == "south")
		{
//			write("*Ä¾Éú»ğ*\n");
			count = me->query_temp("wuxing/»ğ");
			count++;
			me->set_temp("wuxing/»ğ", count);
			if (check_out(me))
				return notify_fail("ÄãË³ÀûµØ×ß³öÁËÎåĞĞÃÔ¹¬¡£\n");
		}
		else if (dir == "west")
		{
//			write("*Ä¾¿ËÍÁ*\n");
			me->delete_temp("wuxing");
			me->move(__DIR__"jianyu1");
			return notify_fail("Äãµô½ø»ú¹Ø£¬ÂäÈëÉ®¼à¡£\n");
		}
	}
	return ::valid_leave(me, dir);
}

