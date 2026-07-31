// ganjiangsword.c
// by dicky

#include <weapon.h>
#include <ansi.h>
inherit SWORD;


void create()
{
        set_name(HIB"莫邪"NOR, ({ "moxie sword","sword" }) );
        set_weight(1400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("no_get", 1);
		set("no_give", 1);

		set("long", "此剑长三尺有半，黝黑黝黑由万年玄铁所铸，沉重无比，
剑光内敛，却隐含杀机，实乃天下第一利器。\n");
		set("value", 2000);
		set("material", "blacksteel");
		set("wield_msg", HIY"$N只听见「嗡」地一声，壁光闪现，$N从背后抽出莫邪，
顿觉寒气扑面，正气凛然。\n"NOR);             
                set("unwield_msg", BLU "$N将莫邪收起，莫邪幻作一道紫光，「唰」地飞入剑鞘。\n" NOR);
		set("wield_skill",([
			"sword" : 100,
		]));
		set("wield_ability",([
			"combat_exp" : 50000,
		]));
	}
        init_sword(920);
        setup();
}
