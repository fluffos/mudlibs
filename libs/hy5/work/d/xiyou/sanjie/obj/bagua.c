// bagua.c  伏曦八卦

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIC"伏曦八卦"NOR, ({ "fuxi bagua" }));
  set_weight(1000);
  set("long", "这是一个水晶做成的八卦图，不知道有什么用。\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "个");
    set("no_sell", 1);
    set("material", "bone");
  }
  setup();
}

