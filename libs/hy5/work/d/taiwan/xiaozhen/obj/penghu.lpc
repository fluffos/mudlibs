inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("喷壶", ({"penghu", "peng hu", "hu"}));
  set_weight(5000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
     set("long", "一个用来给花木洒水的壶。\n");
     set("unit", "个");
     set("value", 2000);
     set("max_liquid", 15);
     set("mask","庄");
  }

  set("liquid", ([
        "type": "alcohol",
        "name": "脏泥水",
        "remaining": 15,
        "drunk_supply": 12,
      ]));
}

