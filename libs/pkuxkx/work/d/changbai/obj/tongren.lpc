
// /d/changbai/obj/tongren.c

#include <weapon.h>
inherit HAMMER;

void create()
{
       set_name("独足铜人", ({"tong ren", "hammer"}));
       set_weight(10000);
       if( clonep() )
              set_default_object(__FILE__);
       else {
              set("long", "这铜人只有独足，手却有一对，双手过顶合拢，正是一把厉害的闭穴撅。\n");
              set("unit", "只");
              set("value", 5000);
              set("material", "bonze");
              set("wield_msg","$N从背上卸下独脚铜人握在手中。\n");
              set("unwield_msg","$N把独足铜人背在背后。\n");
       }

       init_hammer(80);

       setup();
}
