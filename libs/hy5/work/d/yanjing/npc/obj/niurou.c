 

inherit ITEM;
inherit F_FOOD;

void create()
{
set_name("牛肉",({"niu rou","meat"}));
set_weight(600);
  if (clonep())
    set_default_object(__FILE__);
  else {
set("long","一盘切好的牛肉,下酒最好了.\n");
set("unit","盘");
set("value",250);
    set("food_remaining", 5);
    set("food_supply", 35);
set("eat_msg","$N夹起几片$n细细的咬了几口.\n");
  }
}
