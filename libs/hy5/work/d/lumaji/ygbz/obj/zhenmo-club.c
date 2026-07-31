// zhenmo-club.c     by yahoo 2002-3-17
#include <weapon.h>
inherit CLUB;
#include <ansi.h>

void create()
{
        set_name(HIY"震魔棒"NOR, ({ "zhenmo bang", "club", "bang" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", HIY"听说这是天上遗落在人间的仙物,凡人得之,将成为一件杀人利器。\n"NOR);
                set("value", 0);
                set("material", "steel");
                set("wield_msg", HIY"$N从背后拔出一根金光闪闪的震魔棒，天地为之失色。\n"NOR);
                set("unwield_msg", HIY"$N将手中震魔棒放下背在背后。\n");
        }
      init_club(1600);
    set("no_give",1);
    set("no_get",1);
        setup();
}

