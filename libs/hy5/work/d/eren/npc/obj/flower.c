 inherit ITEM;
#include <ansi.h>
void create()
{
  set_name(HIG"七枝一叶花"NOR,({ "flower" }) );
  if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value",1000);
                set("unit","朵");
                set("long", "一朵看上去十分普通的野花，散发着奇异的香味。\n");
                }
}   
