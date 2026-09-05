inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIG"玉牌"NOR, ({ "yu pai", "pai" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "面");
               set("long", "这是一面精致的玉牌，上刻“鹰之眼”三个金字。\n");
               set("value", 100000);
               set("no_store", 1);
               set("material", "jade");
       }
   setup();
}
