#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(CYN"唐氏家谱"NOR, ({ "ngjiapu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张唐氏家谱\n");
          }

    setup();
}

