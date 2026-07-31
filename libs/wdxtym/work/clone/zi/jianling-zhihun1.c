#include <armor.h>
#include <ansi.h>

inherit CLOTH;


void create()
{
        set_name(HIG "剑灵之魂" NOR, ({ "jianling zhihun", "zhihun" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", HIG "这是一件由蓝蝶仙子幻化而成并附身在爱人身上的宝衣，淡淡的蓝色光芒中隐现一只蝴蝶。\n" NOR);
                set("material", "steel");
                set("xy_money", 300);
                set("armor_prop/con", 10);
        }
        setup();
}

int query_autoload()
{
        return 1;
}
