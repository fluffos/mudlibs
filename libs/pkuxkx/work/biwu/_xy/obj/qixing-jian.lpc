// 七星鎏虹剑
// created by zine 25 Aug 2010
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIM"七星鎏虹剑"NOR,({ "qixing jian", "jian", "sword" }) );
        set_weight(1200);
		if( clonep() )
			set_default_object(__FILE__);
        else 
			{
				set("unit", "柄");
				set("value", 1);
				set("material", "steel");
				set("long", "这是柄七星鎏虹剑，剑身上隐隐散发出七色光辉，锋利无比。\n");
				init_sword(55);
			}
        setup();
}
