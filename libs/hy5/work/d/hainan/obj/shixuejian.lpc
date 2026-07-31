#include <ansi.h>;
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIR"嗜血剑"NOR, ({ "shixue sword","sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把沾满了无数人鲜血的宝剑。\n");
                set("value", 400);
                set("material", "steel");
        }
        init_sword(555);

        set("wield_msg", HIR"$N「唰」地一声抽出一把$n握在手中,顿时杀气逼人.\n");
        set("unwield_msg", YEL"$N将手中的$n插入腰间的剑鞘,杀气渐渐的消失了。\n");


        setup();
}

