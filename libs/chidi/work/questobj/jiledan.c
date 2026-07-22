#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"自赤気"NOR, ({ "jiledan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "来");
            set("material", "stone");
            set("long", "匯来自赤気\n");
          }

    setup();
}

