#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
       set_name(HIW"龙象法杵"NOR, ({"jingang zuan", "zuan"}));
       set_weight(10000);
       if( clonep() )
              set_default_object(__FILE__);
       else {
              set("long", HIR"这是藏传佛教中的一种法器，约有七八迟长，入手沉重，上面刻满梵文。\n"NOR);
              set("unit", "跟");
              set("value", 5000);
              set("dalunsi",1);
              set("material", "steel");
              set("wield_msg","$N默念了几句，掏出一根$n握在手中。\n");
              set("unwield_msg","$N放下手中的$n。\n");
       }

       init_hammer(80);

       setup();
}

