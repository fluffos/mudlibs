inherit ITEM;
#include <ansi.h>
void create()
{
       set_name("五仙大补酒", ({"wuxian jiu", "jiu"}));
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "壶");
               set("long", "这好像是五仙大补药酒，不过有一股尿骚味，估计是不能喝了。\n");
               set("no_store", 1);
               set("value",0);
       }
   setup();
}
