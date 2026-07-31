// niurou.c Ô­Áı·ÛÕôÅ£Èâ

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "Ô­Áı·ÛÕôÅ£Èâ" NOR, ({"niurou"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÁıÈÈÆøÌÚÌÚ£¬´ĞÈâÏãÆøÆË±Ç£¬ÈâÖÊÏ¸ÄÛËÖÀÃµÄ·ÛÕôÅ£Èâ\n");
		set("unit", "Áı");
		set("value", 190);
		set("food_remaining", 2);
		set("food_supply", 50);
	}
}