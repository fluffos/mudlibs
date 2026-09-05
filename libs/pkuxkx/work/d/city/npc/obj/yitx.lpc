// hook.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW"一团雪"NOR, ({ "yituan xue", "hua" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "盆");
                set("long", "猛的一看，这花就象一团洁白的雪花，端是白的让人心动\n");
		set("value", 2000);
		set("material", "wood");
             }
       setup();
}
