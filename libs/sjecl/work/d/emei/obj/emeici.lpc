// emeici.c

#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
       set_name(WHT"分水峨嵋刺"NOR, ({ "emei ci","sword","ci","needle" }));
       set_weight(2000);
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("unit", "根");
               set("long", "这是一根打造精致的分水峨嵋刺。\n");
               set("value", 2000);
               set("material", "steel");
               set("wield_msg", "$N从怀中掏出一根$n。\n");
               set("unwield_msg", "$N将手中的$n放入怀中。\n");
       }
       init_dagger(30);
       setup();
}

