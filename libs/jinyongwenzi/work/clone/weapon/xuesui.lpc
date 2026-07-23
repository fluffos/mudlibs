#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(WHT"雪碎"NOR,({ "xue sui", "blade", "dao", "sui","xue" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("rigidity", 1);
                set("material", "steel");
                set("wield_neili", 10);
                set("wield_maxneili", 100);
                set("wield_str", 20);                
                set("long", "这种刀背厚刃薄，用百淬精钢作刃口锋利无比，可以轻而易举把一个人不
论从什么方位劈成两半。刀法纯熟的人，在下雪夭舞刀时，一刀劈出，能
把轻飘飘落下来的雪花劈成两半，所以才有了这样的名称。\n"); 
                set("wield_msg", "$N一阵狞笑，“唰”的一声从腰间抽出一把闪亮的钢刀来。\n");
                set("unwield_msg", "$N扯下一块布条，摸干了$n上的血迹，将$n放回腰间。\n");
        }
        init_blade(70);
        setup();
}
