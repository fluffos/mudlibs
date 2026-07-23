
inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("马奶酒", ({"ma naijiu","naijiu"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "一个用来装米酒的大酒袋，大概装了八、九升的马奶酒。\n");
     set("unit", "个");
     set("value", 20);
     set("max_liquid", 15);
   }

  
   set("liquid", ([
     "type": "alcohol",
     "name": "马奶酒",
     "remaining": 15,
     "drunk_supply": 6,
   ]));
}

