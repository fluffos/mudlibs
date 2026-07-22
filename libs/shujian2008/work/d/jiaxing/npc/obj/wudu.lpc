// wudu.c 五毒秘传

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"五毒秘传"NOR, ({ "wudu mizhuan", "mizhuan", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "一本记载诸般毒药和解药的抄本。\n");
                set("value", 1000);
                set("material", "paper");
                set("no_give", 1);
                set("no_drop", 1);
                set("no_get", 1);
        }
}
