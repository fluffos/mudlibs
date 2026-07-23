
inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("冰酒", ({"bing jiu","jiu"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "据说这是用三年的雪水酿成的酒，味道极好。\n");
     set("unit", "瓶");
     set("value", 300);
     set("max_liquid", 35);
   }

  
   set("liquid", ([
     "type": "alcohol",
     "name": "冰酒",
     "remaining": 15,
     "drunk_supply": 6,
   ]));
}

