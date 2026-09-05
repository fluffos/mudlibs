// Book: gljing.c
// hubo 2008/4/19

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIB"古兰经"NOR, ({"gulan jing", "jing"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一本伊斯兰教唯一的根本经典。它是穆罕默德在23年\n"
                            "的传教过程中陆续宣布的“安拉启示”的汇集。\n");
                set("unit", "本");
                set("value", 10);
                set("material", "paper");
        }
        setup();
}

