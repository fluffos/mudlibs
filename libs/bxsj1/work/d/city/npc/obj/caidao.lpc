// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("菜刀", ({ "caidao", "dao" }));
        set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
                set("long", "这是一柄亮晃晃的菜刀，普通百姓的日常用品。\n");
                set("value", 300);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
        init_blade(4);
	setup();
}
