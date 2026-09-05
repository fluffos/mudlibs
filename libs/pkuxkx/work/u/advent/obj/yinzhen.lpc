#include <weapon.h>
#include <ansi.h>
inherit THROWING;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"银针"NOR, ({ "yin zhen", "zhen", "yinzhen"}));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", HIG"这是一枚银针，长约一寸，尖端锋利无比。\n"NOR);
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N从怀里拿出一根$n，捏在手中。\n");
                set("unwield_msg", "$N将手中的$n揣入怀中。\n");
                set("preorder",1);
                set("robinterval",30);  
        }
        init_throwing(50);
        setup();
}

