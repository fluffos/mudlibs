#include <ansi.h>;
inherit ITEM;
inherit F_FOOD;
void create()
{
     set_name(RED"野果"NOR, ({"ye guo","guo"}));
     set_weight(25);
     if (clonep())
     set_default_object(__FILE__);
     else {
     set("unit", "只");
     set("long", "这是一只红彤彤的野果，发出阵阵诱人的芳香。\n");
     set("food_remaining", 4);
     set("food_supply", 40); 
     setup();
     }
}
