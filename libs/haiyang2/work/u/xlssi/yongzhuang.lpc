// jingang-zhao.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name("性感泳装", ({ "xinggan yongzhuang", "yongzhuang" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "这是一件性感的泳装，仅仅能遮住几点最重要的部位。\n");
		set("material", "cloth");
		set("unit", "件");
        set("value",1);
                set("wear_msg", HIY "$N迅速的脱光的全身的衣服，顿时春光无限。。。。。
$N笑了笑，拿出一件性感泳装穿了上去\n" NOR);
                set("remove_msg", HIY "$N缓缓得将泳装从身上脱了下来，折叠成小小的一团。又身无寸缕\n" NOR);
                set("armor_prop/armor", 100);
	}
	setup();
}
