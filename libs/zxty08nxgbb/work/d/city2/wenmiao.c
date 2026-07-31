#include <room.h>
inherit ROOM;
void create()
{
	set("short", "ÎÄÃí");
	set("long", @LONG
ÕâÀïÊÇÎÄÃíÕıµî£¬ÄÚÓĞ¿×·ò×ÓÏñ¡£Àú´ú»ÊµÛ¶¼¶®µÃÀûÓÃÈå½ÌË¼ÏëÀ´¹®¹Ì
×Ô¼ºµÄ½­É½Éçğ¢£¬µ±³¯»ÊµÛ×ÔÈ»Ò²²»ÀıÍâ¡£²»ÂÛºÎÈËµ½´Ë£¬¶¼±Ï¹§±Ï¾´µØÉÏ
ÏãÀñ°İ¡£

               [1;31mÒ»ÈëÄàÌ¶ÉîËÆº£[2;37;0m

LONG
	);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("objects", ([
		"/d/city/obj/box" : 1,
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"xisi",
	]));
	setup();
	replace_program(ROOM);
}
