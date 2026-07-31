
inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("ÄÌ²è", ({"tea"}));
   set_weight(100);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "ÕâÊÇÒ»±­´óÄÌ²è¡£\n");
     set("unit", "±­");
     set("value", 30);
     set("max_liquid",30);
   }

  
   set("liquid", ([
     "type": "ÄÌ",
     "name": "ÄÌ²è",
     "remaining":30,
     "drunk_supply":20,
   ]));
}

