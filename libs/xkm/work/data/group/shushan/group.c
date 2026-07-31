// Room: /data/group/shushan/group.c / shushan
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ÊñÉ½ÅÉ [1;32m×Ü¶æ[37;0m");
	set("long", @LONG
×Ü¶æÊÇ°ïÅÉ×îÖØÒªµÄµØ·½£¬Ò²ÊÇ°ïÅÉµÄ¾«ÉñÏóáç£¬Æ½Ê±°ïÖ÷Óë³¤ÀÏÃÇÌ¸ÂÛ
°ïÅÉÖØÒªÕş²ßµÄ×î¼Ñ³¡Ëù£¬×Ü¶æµÄ´æÔÚÓë·ñ¹ØÏµ×Å°ïÅÉÄÜ²»ÄÜ´æÔÚ£¬ËùÎ½¶æÔÚ
°ïÔÚ£¬¶æÍö°ïÍö£¬Ï£ÍûÊôÏÂÄÜºÃºÃ±£»¤ÕâÀï¡£ 
LONG
	);
	set("tax", 5);
	set("people", 1);
	set("no_clean_up", 0);
	set("no_delete", 1);
	set("group", "shushan");
	set("master", "badsword");
	set("gold", 1000);
	set("group_name", "ÊñÉ½ÅÉ");
	set("valid_startroom", 1);
	set("npc_max", 40);
	set("item_max", 40);
	set("no_change", 1);
	set("room_max", 80);

	setup();
	replace_program(ROOM);
}
