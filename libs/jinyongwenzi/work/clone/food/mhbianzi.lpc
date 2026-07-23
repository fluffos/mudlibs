// by XiaoYao 4/11/99

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("麻花辫子", ({"mahua bianzi", "mahua", "bianzi"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一条刚出炉的麻花辫子。\n");
    set("unit", "条");
    set("value", 120);
    set("food_remaining", 4);
    set("food_supply", 22);
  }
}
