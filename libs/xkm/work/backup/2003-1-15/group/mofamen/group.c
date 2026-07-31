// Room: /data/group/mofamen/group.c / mofamen
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "Ä§·¨ÃÅ [1;32m×Ü¶æ[37;0m");
	set("long", @LONG
×Ü¶æÊÇ°ïÅÉ×îÖØÒªµÄµØ·½£¬Ò²ÊÇ°ïÅÉµÄ¾«ÉñÏóáç£¬Æ½Ê±°ïÖ÷Óë³¤ÀÏÃÇÌ¸ÂÛ
°ïÅÉÖØÒªÕş²ßµÄ×î¼Ñ³¡Ëù£¬×Ü¶æµÄ´æÔÚÓë·ñ¹ØÏµ×Å°ïÅÉÄÜ²»ÄÜ´æÔÚ£¬ËùÎ½¶æÔÚ
°ïÔÚ£¬¶æÍö°ïÍö£¬Ï£ÍûÊôÏÂÄÜºÃºÃ±£»¤ÕâÀï¡£ 
LONG
	);
	set("npc_max", 40);
	set("no_clean_up", 0);
	set("no_change", 1);
	set("gold", 1000);
	set("group", "mofamen");
	set("tax", 5);
	set("group_name", "Ä§·¨ÃÅ");
	set("item_max", 40);
	set("no_delete", 1);
	set("valid_startroom", 1);
	set("room_max", 80);
	set("master", "wsq");
	set("people", 4);

	setup();
	replace_program(ROOM);
}
