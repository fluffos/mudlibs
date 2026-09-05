#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIG"闯王宝藏藏宝图"NOR , ({"cangbao tu", "map"}));
  set_weight(500);

  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "张");
    set("value", 10000);
    set("long","这是一张闯王宝藏的藏宝图，不过很可惜，上面标识的地点你不认识。\n");
    set("no_store", 1);
    set("no_sell", 1);
    set("no_pawn",1);
    set("no_put",1);
    set("is_map",1);
  }
  setup();
}
