

#include <weapon.h>

inherit DAGGER;

void create()
{
   set_name("匕首", ({ "dagger" }) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 500);
     set("material", "iron");
     set("long", "这是一寻常的匕首。\n");
     set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n插回腰间。\n");
   }
   init_dagger(120);
   setup();
}
