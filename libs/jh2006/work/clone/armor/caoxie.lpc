// caoxie.c 草鞋
// build by Lklv@SJ 2001.9.28

#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("草鞋", ({ "cao xie", "caoxie", "xie", "shoes" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("material", "boots");
                set("value", 0);
                set("long", "这是一双普通的草鞋，穿在脚上很舒服。\n");
                set("armor_prop/dodge", 2);
        }
        setup();
}
