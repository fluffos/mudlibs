// Room: /data/group/loveangel/group.c / loveangel
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "°®ÉñÅÉ [1;32m×Ü¶æ[37;0m");
	set("long", @LONG
×Ü¶æÊÇ°ïÅÉ×îÖØÒªµÄµØ·½£¬Ò²ÊÇ°ïÅÉµÄ¾«ÉñÏóáç£¬Æ½Ê±°ïÖ÷Óë³¤ÀÏÃÇÌ¸ÂÛ
°ïÅÉÖØÒªÕş²ßµÄ×î¼Ñ³¡Ëù£¬×Ü¶æµÄ´æÔÚÓë·ñ¹ØÏµ×Å°ïÅÉÄÜ²»ÄÜ´æÔÚ£¬ËùÎ½¶æÔÚ
°ïÔÚ£¬¶æÍö°ïÍö£¬Ï£ÍûÊôÏÂÄÜºÃºÃ±£»¤ÕâÀï¡£ 
LONG
	);
	set("room_max", 80);
	set("valid_startroom", 1);
	set("group", "loveangel");
	set("master", "poke");
	set("gold", 1000);
	set("group_name", "°®ÉñÅÉ");
	set("tax", 5);
	set("story", 1);
	set("no_clean_up", 0);
	set("no_delete", 1);
	set("item_max", 40);
	set("no_change", 1);
	set("npc_max", 40);
	set("people", 2);

	setup();
	replace_program(ROOM);
}
