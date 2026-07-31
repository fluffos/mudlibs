// yitian-jian 倚天剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIC"快刃剑"NOR,({ "kuai jian", "kuaitian", "sword", "jian" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 2000);

 
                set("material", "steel");
        }
         init_sword(300);
        setup();
}
