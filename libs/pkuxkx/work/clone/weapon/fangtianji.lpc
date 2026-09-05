// fangtianji.c 方天画戟

#include <weapon.h>
#include <ansi.h>
inherit HALBERD;

void create()
{
        set_name(GRN "方天画戟" NOR, ({ "fangtian ji", "ji","halberd" }));
	set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "这是一杆方天画戟。\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声拎起$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_halberd(30);
        setup();
}
