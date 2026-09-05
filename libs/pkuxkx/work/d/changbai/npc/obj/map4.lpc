#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIC"宝藏地图残片"NOR , ({"map piece4", "map"}));
  set_weight(500);

  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "片");
    set("value", 10000);
    set("long","这是一片残片地图，横七竖八的标注了很多地点。\n");
    set("no_store", 1);
    set("no_sell", 1);
    set("no_pawn",1);
    set("no_put",1);
    set("is_map",1);
  }
  setup();
}
