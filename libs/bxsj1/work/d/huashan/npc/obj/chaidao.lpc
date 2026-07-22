// chaidao.c
// Creat for hs job

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("柴刀", ({ "chai dao", "chaidao", "dao" }));
        set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
                  set("long", "这是一把柴刀，砍柴必备。\n");
                set("value", 300);
		set("material", "steel");
                  set("wield_msg", "$N「唰」地抽出一把$n握在手中。\n");
                  set("unwield_msg", "$N将手中的$n别在腰间。\n");
	}
        init_blade(4);
	setup();
}
