// /clone/armor/guanxue.c   绣花鞋

#include <armor.h>
#include <ansi.h>

inherit BOOTS;
void create()
{
        set_name(HIR"绣花鞋"NOR, ({ "xiuhua xie", "xie","shoes" }));
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","这是一双绣花鞋。\n");
                set("unit", "双");
                set("no_transfer",1);
                set("material", "cloth");
                set("armor_type", "feet");
                set("armor_prop/dodge", 2);
        }
        setup(); 
}
