// Room: /data/group/ppker/group.c / ppker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "É±ÊÖÂ¥ [1;32m×Ü¶æ[37;0m");
	set("long", @LONG
×Ü¶æÊÇ°ïÅÉ×îÖØÒªµÄµØ·½£¬Ò²ÊÇ°ïÅÉµÄ¾«ÉñÏóáç£¬Æ½Ê±°ïÖ÷Óë³¤ÀÏÃÇÌ¸ÂÛ
°ïÅÉÖØÒªÕş²ßµÄ×î¼Ñ³¡Ëù£¬×Ü¶æµÄ´æÔÚÓë·ñ¹ØÏµ×Å°ïÅÉÄÜ²»ÄÜ´æÔÚ£¬ËùÎ½¶æÔÚ
°ïÔÚ£¬¶æÍö°ïÍö£¬Ï£ÍûÊôÏÂÄÜºÃºÃ±£»¤ÕâÀï¡£ 
LONG
	);
	set("exits", ([ /* sizeof() == 6 */
  "east" : "/data/group/ppker/3",
  "south" : "/data/group/ppker/6",
  "north" : "/data/group/ppker/4",
  "down" : "/data/group/ppker/1",
  "up" : "/data/group/ppker/5",
  "west" : "/data/group/ppker/2",
]));
	set("people", 1);
	set("gold", 402);
	set("room_num", 6);
	set("valid_startroom", 1);
	set("tax", 5);
	set("group", "ppker");
	set("group_name", "É±ÊÖÂ¥");
	set("no_change", 1);
	set("master", "program");
	set("item_max", 40);
	set("room_max", 80);
	set("no_delete", 1);
	set("room", 6);
	set("npc_max", 40);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
