// Room: /data/group/xjp/group.c / xjp
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ÏÉ½£ÅÉ [1;32m×Ü¶æ[37;0m");
	set("long", @LONG
×Ü¶æÊÇ°ïÅÉ×îÖØÒªµÄµØ·½£¬Ò²ÊÇ°ïÅÉµÄ¾«ÉñÏóáç£¬Æ½Ê±°ïÖ÷Óë³¤ÀÏÃÇÌ¸ÂÛ
°ïÅÉÖØÒªÕş²ßµÄ×î¼Ñ³¡Ëù£¬×Ü¶æµÄ´æÔÚÓë·ñ¹ØÏµ×Å°ïÅÉÄÜ²»ÄÜ´æÔÚ£¬ËùÎ½¶æÔÚ
°ïÔÚ£¬¶æÍö°ïÍö£¬Ï£ÍûÊôÏÂÄÜºÃºÃ±£»¤ÕâÀï¡£ 
LONG
	);
	set("tax", 5);
	set("people", 5);
	set("no_clean_up", 0);
	set("no_delete", 1);
	set("group", "xjp");
	set("master", "londe");
	set("gold", 1501);
	set("group_name", "ÏÉ½£ÅÉ");
	set("valid_startroom", 1);
	set("item_max", 40);
	set("npc_max", 40);
	set("no_change", 1);
	set("room_max", 80);

	setup();
	replace_program(ROOM);
}
