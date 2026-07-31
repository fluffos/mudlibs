// y_rose.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY"»ÆÃµ¹å"NOR, ({ "yellow rose" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "ÕâÊÇÒ»Ö¦ÑÞÀöµÄ»ÆÃµ¹å»¨¡£\n");
		set("unit", "Ö¦");
		set("value", 100);
	}
}
