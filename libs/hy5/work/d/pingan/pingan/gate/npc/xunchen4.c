#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(GRN"巡城报告4"NOR, ({ "xunchen4" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	         set("value", 100);
           set("unit", "本");
            set("material", "paper");
            set("long", "一本巡城报告。\n");
          }

    setup();
}
