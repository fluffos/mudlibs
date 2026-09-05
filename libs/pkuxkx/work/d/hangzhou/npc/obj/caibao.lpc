inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIY"财宝"NOR, ({ "cai bao", "treasure", "bao" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "包");
               set("long", "这是一包被飞贼盗窃的财宝，看来可以去卖个好价钱。\n");
               set("value", 125000);
               set("no_store", 1);
               set("material", "jade");
       }
       setup();
}
