#include <armor.h>
#include <ansi.h>
inherit CLOTH;
 void create()
{
    set_name(RED"红绸马褂"NOR, ({ "ma gua"}));
    set_weight(2000);
     if( clonep() )
          set_default_object(__FILE__);
       else {
              set("unit","件");
              set("value",100);
              set("material","cloth");
              set("armor_prop/armor",1);
      }
        setup();
 }
