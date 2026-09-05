// 新手用sword
// By Kiden@pkuxkx

#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("青锋剑", ({ "qingfeng sword", "jian", "sword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("material", "steel");
                set("long", "这是一把又细又长的剑，剑身锐利。\n");
        }
        init_sword(60);
        setup();
}

