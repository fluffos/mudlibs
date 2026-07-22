
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
   set_name(MAG"披巾"NOR, ({ "pi jin","jin"}) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一个女人戴的披巾。\n");
     set("material", "细纱布");
     set("unit", "条");
     set("value",10);
     set("armor_prop/armor",3);
     set("female_only",1);
     
   }
   setup();
}
