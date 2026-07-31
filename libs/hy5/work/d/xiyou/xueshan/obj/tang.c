inherit ITEM;

#include <ansi.h>


int do_he(string);

void create() 
  {
   set_name(YEL "五仙汤" NOR,({"tang"}));
   set("long","一碗花花绿绿的"+this_object()->query("name")+"，尝尝(he)味道？\n");
   set_weight(50);
   set("unit","碗");
   setup();
  }

