#include <ansi.h>

inherit ITEM;

void create()
{
  set_name("断了的"+HIG+"翠竹"+NOR, ({ "bamboo" }));
  set_weight(8000);
  set("long","一根颜色"+HIG+"碧绿"+NOR+"的翠竹,可惜给砍断了.\n");
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "根");
    set("material", "bamboo");
    set("no_get",1);
       set("no_drop",1);
  }
  setup();
}
