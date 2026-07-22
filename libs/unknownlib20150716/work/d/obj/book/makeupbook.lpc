//Cracked by Roath
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() 
{
        set_name(HIM"檀香扇"NOR, ({"tanxiang shan","shan","book"}));
	set("long","一把香气扑鼻的檀香扇，扇面上密密麻麻写满了一笔娟秀的蝇头小楷。");
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100000);
        	set("material", "paper");
        	set("wield_msg","$N从怀中拿出一把香气扑鼻的扇子，攥在手中舞了舞。\n");
        	set("unwield_msg","$N收回了$n。\n");
	}
	init_sword(15);
	setup();
}
