// kunxian fake
// created by mes, updated 6-30-97 pickle

#include <ansi.h>
#include <weapon.h>
inherit WHIP;
//inherit ITEM;

void create()
{
  set_name(RED "捆仙索" NOR,({"kunxian suo", "suo", "rope", "kunxiansuo", "kunxian"}));
  set_weight(5000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","条");
    set("value",0);
    set("long","一条暗红色的绳子，也不知道是什么做的。\n");
  }
  init_whip(20);
  setup();
}