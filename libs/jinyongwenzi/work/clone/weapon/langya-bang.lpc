// langya.c

#include <weapon.h>
#include <ansi.h>
inherit STICK;

void create()
{
       set_name(RED"狼牙棒"NOR, ({ "langya bang","bang" }));
       set_weight(15000);
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("unit", "根");
               set("long", "这是一根纯钢打造的狼牙棒。\n");
               set("value", 2000);
               set("material", "steel");
               set("wield_msg", "$N将一根$n握在手中。\n");
               set("unwield_msg", "$N将手中的$n放下。\n");
       }
 init_stick(50);
       setup();
}
