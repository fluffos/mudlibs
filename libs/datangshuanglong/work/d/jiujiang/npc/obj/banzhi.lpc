
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
   set_name(HIG"玛瑙扳指"NOR, ({ "ban zhi","zhi"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "玛瑙");
     set("unit", "枚");
     set("value",200);
     set("armor_prop/armor",10);
     set("armor_prop/dodge",1);
   }
   setup();
}
