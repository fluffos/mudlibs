// by XiaoYao 4/11/99

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("烧饼", ({"shao bing", "bing"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一个香喷喷的烧饼。\n");
    set("unit", "个");
    set("value", 200);
    set("food_remaining", 3);
    set("food_supply", 35);
  }
}
