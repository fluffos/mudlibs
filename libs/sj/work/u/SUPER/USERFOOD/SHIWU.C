inherit F_FOOD;
inherit ITEM;
void create()
{
       int i;
     string arg = this_player()->query("make/food");
     object me=this_player();
      set_name(me->query("make/food"),({"food"}));
      set_weight(80);
     if (clonep())
set_default_object(__FILE__);
else {
set("long", "一个起霉的"+arg+"！\n");
set("unit", "个");
set("value", 0);
   i = me->query("make/food2")/10
;
 set("food_remaining", i);
set("food_supply", 20);
}
}
