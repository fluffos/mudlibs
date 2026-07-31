// longsword.c 方天画戟

#include <weapon.h>
#include <ansi.h>
inherit HALBERD;

void create()
{
	set_name(GRN "方天画戟" NOR, ({ "fangtian huaji", "ji","huaji" }));
        set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long","一柄方天画戟,冒着寒气令人不寒而栗!\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入背後的长囊间。\n");
                set("value", 500);
                set("material", "steel");
        }
        init_halberd(40);
        setup();
}
