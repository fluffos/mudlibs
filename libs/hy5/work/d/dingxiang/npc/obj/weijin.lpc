
#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
   set_name("围巾", ({ "wei jin","jin"}) );
   set_weight(150);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "羊皮");
     set("unit", "条");
     set("value",100);
     set("armor_prop/armor",3);
   }
   setup();
}
