
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
   set_name("衙役帽", ({ "mao"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是衙门衙役所戴的帽子。\n");
     set("material", "粗布");
     set("unit", "顶");
     set("value",10);
     set("armor_prop/armor",1);
     
   }
   setup();
}
