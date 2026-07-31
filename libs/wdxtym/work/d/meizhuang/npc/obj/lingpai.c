// lingpai.c
#include <ansi.h>

inherit ITEM;

void setup()
{}
void create()
{
	set_name("Ã·»¨ÁîÅÆ", ({"ling pai", "ling"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¿é");
		set("value", 0);
	}
	setup();
}

