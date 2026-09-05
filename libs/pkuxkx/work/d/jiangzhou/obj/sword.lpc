#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIM"桃木剑"NOR, ({ "taomu jian","jian","sword" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄桃花木的宝剑，据说可以驱鬼。\n");
                set("value", 800);
                set("material", "wood");
                set("wield_msg", HIM "$N紧紧的握住了桃木剑 ! \n" NOR );
                set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }
        init_sword(1);
        setup();
}

