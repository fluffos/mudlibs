// Room: /data/group/mmu/group.c / mmu
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "±±¾©¶æ [1;32m×Ü¶æ[37;0m");
	set("long", @LONG
×Ü¶æÊÇ°ïÅÉ×îÖØÒªµÄµØ·½£¬Ò²ÊÇ°ïÅÉµÄ¾«ÉñÏóáç£¬Æ½Ê±°ïÖ÷Óë³¤ÀÏÃÇÌ¸ÂÛ
°ïÅÉÖØÒªÕş²ßµÄ×î¼Ñ³¡Ëù£¬×Ü¶æµÄ´æÔÚÓë·ñ¹ØÏµ×Å°ïÅÉÄÜ²»ÄÜ´æÔÚ£¬ËùÎ½¶æÔÚ
°ïÔÚ£¬¶æÍö°ïÍö£¬Ï£ÍûÊôÏÂÄÜºÃºÃ±£»¤ÕâÀï¡£ 
LONG
	);
	set("npc_max", 40);
	set("no_delete", 1);
	set("people", 1);
	set("group", "mmu");
	set("room_max", 80);
	set("valid_startroom", 1);
	set("gold", 1000);
	set("no_clean_up", 0);
	set("item_max", 40);
	set("no_change", 1);
	set("group_name", "±±¾©¶æ");
	set("tax", 5);
	set("master", "kkyy");

	setup();
	replace_program(ROOM);
}
