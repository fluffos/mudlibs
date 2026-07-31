// mejian.c  峨嵋山入门必须品   海上飘(piao) 20/8/2001

#include <weapon.h>

inherit SWORD;

void create()
{
            seteuid(getuid());
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100);
                set("material", "bamboo");
                set("long", "这是一把峨嵋山睹光台舍身崖上的破剑。\n");
                set("wield_msg", "$N拿出一把$n，握在手中。只见本来破破烂烂的$n放出五色彩光。\n");
                set("unequip_msg", "$N放下手中的$n，剑上的五色彩光瞬间消失了。\n");
        }
        init_sword(120);
        setup();
}

void init()
{
  object me;
  seteuid(geteuid());

  me = this_player();
  if (me)
    set_name (me->name(1)+ "的剑", ({ "sword"}));
  else
    set_name ("破剑", ({ "po sword"}));

return ;
}

