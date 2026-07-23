
inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("奶茶", ({"tea"}));
   set_weight(100);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "这是一杯大奶茶。\n");
     set("unit", "杯");
     set("value", 30);
     set("max_liquid",30);
   }

  
   set("liquid", ([
     "type": "奶",
     "name": "奶茶",
     "remaining":30,
     "drunk_supply":20,
   ]));
}

