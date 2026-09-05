#include <weapon.h>

inherit DAGGER;
#include <ansi.h>

void create()
{
        set_name("铁令", ({ "tie ling","ling" }) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把铁制的令牌。\n");
                set("value", 200);
                set("material", "iron");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回鞘中。\n");

           }
         init_dagger(40);
        setup();
}
