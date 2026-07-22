#include <weapon.h>
#include <ansi.h>
inherit MACE;


void create()
{
              set_name(HIG"金锏"NOR, ({ "jing", "mace" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                   set("unit", "根");
                   set("long", "这是一根无敌虎尾鞭。\n");
                   set("value", 0);
                   set("no_sell", 1);
                   set("material", "iron");
set("wield_msg", "$N操起一根$n，威猛地摆了个架式。\n");
set("unwield_msg", "$N小心翼翼将$n别回腰间。\n");
                   set("no_sell",1);
 
        }
         init_mace(70);
        setup();
}


