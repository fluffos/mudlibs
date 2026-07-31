// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "猪头肉",
  "猪排肉",
  "猪耳",
  "猪心",
  "猪尾",
  "猪手",
  "猪脚",
  "猪肥肉",
});

void create()
{
 set_name(names[random(sizeof(names))], ({"zhu rou","rou","zhurou"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一块血淋淋的肉。\n");
    set("unit", "块");
    set("value", 200);
    set("food_remaining", 5);
    set("food_supply", 85);
  }
}

void init()
{
  if (query("name")=="各式面条")
    set_name(names[random(sizeof(names))], ({"mian tiao","miantiao","mian"}));
  ::init();
}
