// miantiao XiaoYao by 4/22/99

inherit ITEM;
inherit F_FOOD;

string *names = ({
                "麻辣肚丝",
                "松仁玉米",
		"梅菜扣肉",
		"五香腊肠",
		"鱼香肉丝",
		"红油鸡片",
		"清炒虾仁",
		"五花焖肉",
		"青丝熏鱼",
		"糖醋排骨",
		"京酱肉丝",
		"油炝大虾",
		"脆皮烤鸭",
		"红烧素鹅",
		"宫保鸡丁",
		"麻辣肚丝",
		"红油肺片",
		"嫩汆猪肝",
		"走油脆肠",
		"爆炒腰花",
		"麝香冬笋",
		"翡翠豆腐",
		"麻婆豆腐",
		"三鲜腐竹",
});

void create()
{
  set_name("各类菜肴", ({"cai yao", "cai", "food"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一盘令人垂涎的菜肴。\n");
    set("unit", "盘");
    set("value", 200);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}

void init()
{
  if (query("name")=="各类菜肴")
    set_name(names[random(sizeof(names))], ({"cai yao","cai","food"}));
  ::init();
}
