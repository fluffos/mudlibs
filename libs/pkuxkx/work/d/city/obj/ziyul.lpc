// hook.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(MAG"紫玉莲"NOR, ({ "ziyu lian", "hua" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "盆");
                set("long", "这盆花十分漂亮，绿油油的叶子中绽放着几朵大若莲花的紫色花朵\n");
		set("value", 2000);
		set("material", "wood");
             }
       setup();
}
