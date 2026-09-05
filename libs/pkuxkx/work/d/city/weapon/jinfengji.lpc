// fangtianji.c 方天画戟

#include <weapon.h>
#include <ansi.h>
inherit HALBERD;

void create()
{
        set_name(HIM "金凤紫电戟" NOR, ({ "zidian ji", "ji" }));
	set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "此戟长约一丈二寸，重六十六斤。戟端造型优美，形如飞凤，外镀金粉，端庄华丽，戟身闪烁紫电星芒，挥舞之时有风鸣雷烁、紫电闪灼之威。\n");
                set("value", 100000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声拎起$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_halberd(100);
        setup();
}
