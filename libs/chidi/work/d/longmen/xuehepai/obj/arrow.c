// arrow.c
#include <weapon.h>
#include <ansi.h>
inherit THROWING;
void create()
{
        set_name(HIC"游忍箭"NOR, ({ "youren jian", "arrow" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 200000);
                set("weight", 6000);
               set("no_break",1);
               set("endure",150);
                set("material", "iron");
                set("long", "游忍箭连珠箭发，势道凶猛。\n");
                set("wield_msg", HIC"$N从颈间取下一把游忍箭！\n"NOR);
                set("unwield_msg",HIC"$N把游忍箭套在颈间。\n"NOR);
        }
         init_throwing(50);
        setup();
}

