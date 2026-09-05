inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIY"羊皮碎片"NOR, ({ "yang pi", "pi",}) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "包");
               set("long", "这是一包从四十二章经里找到的碎羊皮，大概有好几百张。\n");
               set("value", 1);
               set("no_sell",1);
               set("material", "wood");
       }
       setup();
}