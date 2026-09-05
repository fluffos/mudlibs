// baozi.c 各类包子

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "豆沙包",
  "素菜包",
  "小笼包",
  "鲜肉包",
  "海鲜包",
  "梅记招牌包",
  "牛肉包",
  "虾肉包",
  "香菇菜包",
});

void create()
{
      set_name("各类包子", ({"bao zi", "baozi"}));
      set_weight(100);
      if (clonep())
      set_default_object(__FILE__);
      else {
      set("long", "一个香喷喷的包子。\n");
      set("unit", "个");
      set("value", 200);
      set("food_remaining", 5);
      set("food_supply", 45);
      }
}

void init()
{
  if (query("name")=="各类包子")
    set_name(names[random(sizeof(names))], ({"bao zi","baozi"}));
  ::init();
}

