// Room: /data/group/lovezxl/group.c / lovezxl
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ĞÄËéÎŞºÛ¹¬ [1;32m×Ü¶æ[37;0m");
	set("long", @LONG
×Ü¶æÊÇ°ïÅÉ×îÖØÒªµÄµØ·½£¬Ò²ÊÇ°ïÅÉµÄ¾«ÉñÏóáç£¬Æ½Ê±°ïÖ÷Óë³¤ÀÏÃÇÌ¸ÂÛ
°ïÅÉÖØÒªÕş²ßµÄ×î¼Ñ³¡Ëù£¬×Ü¶æµÄ´æÔÚÓë·ñ¹ØÏµ×Å°ïÅÉÄÜ²»ÄÜ´æÔÚ£¬ËùÎ½¶æÔÚ
°ïÔÚ£¬¶æÍö°ïÍö£¬Ï£ÍûÊôÏÂÄÜºÃºÃ±£»¤ÕâÀï¡£ 
LONG
	);
	set("story", 1);
	set("no_clean_up", 0);
	set("room_max", 80);
	set("valid_startroom", 1);
	set("no_delete", 1);
	set("group", "lovezxl");
	set("npc_max", 40);
	set("master", "ysis");
	set("item_max", 40);
	set("no_change", 1);
	set("tax", 5);
	set("gold", 1000);
	set("group_name", "ĞÄËéÎŞºÛ¹¬");
	set("people", 5);

	setup();
	replace_program(ROOM);
}
