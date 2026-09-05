#include <weapon.h>

inherit DAGGER;
#include <ansi.h>

void create()
{
        set_name(HIR"鱼肠刺"NOR, ({ "yuchang ci","dagger" }) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把镶着无数宝石的短剑.\n");
                set("value", 20000);
                set("material", "silver");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回鞘中。\n");

           }
         init_dagger(80);
        setup();
}
