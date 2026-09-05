#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(WHT"木签"NOR, ({ "mu qian", "qian", "label" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根黄裳给出的木签，据说只有建康府清凉寺的老和尚可以解签。\n");
                set("value", 10);
                set("material", "wood");
             }
       setup();
}

