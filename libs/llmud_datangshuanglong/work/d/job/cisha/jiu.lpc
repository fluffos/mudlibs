
inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
   set_name(HIR"女儿红"NOR, ({"nver hong","jiu"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "这是一坛陈年的女儿红。\n");
     set("unit", "坛");
     set("value",200);
     set("max_liquid",30);
   }

  
   set("liquid", ([
     "type": "alcohol",
     "name": "女儿红",
     "remaining":30,
     "drunk_supply":15,
   ]));
}

