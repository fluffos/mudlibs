// female1-cloth.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIM"比基尼"NOR, ({ "pink cloth", "cloth" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
              set("long", "这件粉红色的比基尼是最新材料设计，穿着舒适，而且吸引眼球，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
	}
	setup();
}

