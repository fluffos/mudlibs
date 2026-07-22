
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;

inherit WHIP;

void create()
{
        set_name(HIW"余地鞭"NOR, ({ "yudi bian", "bian","whip" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是一条镶着珠宝的余地鞭。此鞭乃血河三宝之一。\n");
          set("value", 500000);
               set("no_break",1);
               set("endure",120);
                set("material", "steel");
                set("wield_msg", HIR "$N嗖的一声，从腰间解下余地鞭。\n" NOR);
                set("unwield_msg", HIR "$N将余地鞭盘好，缠绕在腰间。\n" NOR);
        }
          init_whip(60);
        setup();
}

