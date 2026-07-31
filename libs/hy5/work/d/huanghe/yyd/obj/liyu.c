// liyu.c ÌÇ´×ÀğÓã

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "ÌÇ´×ÀğÓã" NOR, ({"tangcu liyu", "liyu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÒ»ÅÌÍâ½¹ÀïÄÛ£¬ËáÌğÊÊ¿ÚµÄÌÇ´×ÀğÓã¡£\n");
		set("unit", "ÅÌ");
		set("value", 250);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}