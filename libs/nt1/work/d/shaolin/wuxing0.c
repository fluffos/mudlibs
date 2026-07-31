// Room: /d/shaolin/wuxing0.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

string* dirs = ({"east", "south", "west", "north"});

void create()
{
	set("short",HIY "ÎåĞĞ¶´" NOR);
	set("long", @LONG
[1£»33mÕâÊÇÎåĞĞ¶´¡£ËÄÖÜÒ»Æ¬ÁÁ¾§¾§µÄ£¬¶¨¾¦Ï¸¿´£¬È´ÊÇÎŞÊı·æÀû
µÄµ¶¼â´ÓÇ½ÉÏ£¬µØÉÏ£¬¶¥ÉÏ£¬ËÄÃæ°Ë·½ÏòÄãÉì¹ıÀ´£¬ÉÔ²»ÁôÉñ¾Í»á×Ô¼º×²
µ½µ¶¼âÉÏÈ¥¡£µ¶¹âÑ£Ä¿£¬¸üÌí³¹¹Çº®Òâ¡£¼¸¾ßÑªÁÜÁÜµÄ¶ÏÖ«²Ğº¡¹ÒÔÚµ¶¼â
ÉÏ£¬¿´À´ÒÑ¾­ÓĞĞ©Ê±ÈÕÁË¡£Ç½±ÚºÚºõºõµÄ£¬ËÆÊÇ¸ÖÌúÖı³É¡£[2£»37£»0m
LONG );
	set("exits", ([
		"east" : __DIR__"wuxing4",
		"south" : __DIR__"wuxing3",
		"west" : __DIR__"wuxing1",
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
		if (dir == "north")
		{
//			write("*½ğÉúË®*\n");
			count = me->query_temp("wuxing/Ë®");
			count++;
			me->set_temp("wuxing/Ë®", count);
			if (check_out(me))
				return notify_fail("ÄãË³ÀûµØ×ß³öÁËÎåĞĞÃÔ¹¬¡£\n");
		}
		else if (dir == "west")
		{
//			write("*½ğ¿ËÄ¾*\n");
			me->delete_temp("wuxing");
			me->move(__DIR__"jianyu1");
			return notify_fail("Äãµô½ø»ú¹Ø£¬ÂäÈëÉ®¼à¡£\n");
		}
	}
	return ::valid_leave(me, dir);
}

