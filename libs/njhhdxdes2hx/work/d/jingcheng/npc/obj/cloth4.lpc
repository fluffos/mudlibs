#include <armor.h>
#include <ansi.h>
inherit CLOTH;
 void create()
{
    set_name(YEL"黄马褂"NOR,({ "huang magua" }));
    set_weight(2000);
    if( clonep() )
      set_default_object(__FILE__);
      else {
         set("unit","件");
         set("value",200);
         set("material","cloth");
         set("armor_prop/armor",3);
    }
        setup();
 }
