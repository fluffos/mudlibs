#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(GRN"巡城报告3"NOR, ({ "xunchen3" }) );
    set_weight(1);
    set("no_drop",1);
set("no_get",1);
set("no_steal",1);
set("no_beg",1);
set("no_put",1);
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
