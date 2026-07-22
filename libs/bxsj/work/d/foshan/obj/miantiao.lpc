// miantiao XiaoYao by 4/22/99

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "刀削面",
  "阳春面",
  "肉丝面",
  "鸡丝面",
  "牛肉面",
  "盖浇面",
  "卤味面",
  "排骨面",
  "豆丝面",
  "海鲜面",
  "馄饨面",
  "担担面",
  "肉煮面",
  "长寿面",
});

void create()
{
  set_name("各式面条", ({"mian tiao", "miantiao", "mian"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一碗热气腾腾的面条。\n");
    set("unit", "碗");
    set("value", 200);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}

void init()
{
  if (query("name")=="各式面条")
    set_name(names[random(sizeof(names))], ({"mian tiao","miantiao","mian"}));
  ::init();
}
