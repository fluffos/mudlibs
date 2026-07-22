#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"震天鼓"NOR,({"zhentian gu","gu"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一个鼓。\n");
                set("value", 0);
                set("material", "skin");
                set("no_drop","这东西不能离开你。\n");
              }
}


