// whip
// created by zine

#include <weapon.h>
inherit WHIP;

void create()
{
	string * pre=({"十三节亮银","十三节竹节钢","驼骨阴风","十三节人骨",});
	set_name(pre[random(sizeof(pre))]+"鞭", ({ "whip","bian"}));
    set_weight(1300);
	if( clonep() )
		set_default_object(__FILE__);
	else 
		{
			set("unit", "根");
			set("long", "这是一根暗沉沉的钢索。\n");
			set("value", 1);
			set("material", "steel");
			init_whip(55+random(15));
		}
	setup();
}
