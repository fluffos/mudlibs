inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIC"衬衣"NOR, ({ "chen yi", "cloth" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "件");
               set("long", "这是一件破破烂烂的衬衣，衣服上不知道被谁捅了一堆窟窿，已经不能穿了。\n");
               set("no_store", 1);
               set("material", "cloth");
       }
   setup();
}
