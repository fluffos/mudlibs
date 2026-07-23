// zongzi.c 棕子

inherit ITEM;
inherit F_FOOD;

void create()
{
       set_name("棕子", ({"zongzi", "zong"}));
       set_weight(150);
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("long", "一个香喷喷的棕子。\n");
               set("unit", "个");
               set("value", 100);
               set("food_remaining", 3);
               set("food_supply", 30);
       }
}
