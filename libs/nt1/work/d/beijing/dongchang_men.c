inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",RED "¶«³§´óÃÅ");
	set("long", @LONG
ÕâÀï¾ÍÊÇ¾©³ÇµÄÌØÎñ»ú¹¹¡ª¡ª¶«³§µÄ´óÃÅ¡£ÕâÀï¾¯±¸ÉîÑÏ£¬²»Ê±ÓĞ´©
×ÅÖÆ·şµÄ¶«³§¹Ù±ø½ø½ø³ö³ö£¬Íû´óÃÅÀïÍûÈ¥£¬¿ÉÒÔÍû¼û´óÃÅÀïÃæÓĞĞí¶àÌ«
¼à¡£´óÃÅÁ½ÅÔµÄ¶«³§¹Ù±øÕıÈçÀÇËÆ»¢µÄ¶¢×ÅÄã¿´£¬Èç¹ûÄã²»ÏëÕÒËÀµÄ»°£¬
×îºÃ»¹ÊÇ¸Ï¿ìÀë¿ªµÄºÃ¡£[2£»37£»0m
LONG );
	set("exits", ([
		"south" : __DIR__"dongchang",
		"north" : __DIR__"dong_1",
	]));
	set("objects", ([
		__DIR__"npc/bing2" : 2,
		__DIR__"npc/taijian" : 1,
	]));
	set("no_fight", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("guan bing", environment(me))) && dir == "south")
		return notify_fail("¶«³§¹Ù±øÉìÊÖ½«ÄãÀ¹×¡¡£\n\n");
	return ::valid_leave(me, dir);
}
