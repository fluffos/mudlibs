#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"冷月宝刀"NOR, ({ "lengyue baodao" , "baodao", "blade"}) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIC"这是一把宝刀，刀柄上用金丝银丝镶著一钩眉毛月之形，江湖称之为“"+HIY"冷月宝刀"+HIC"”。\n");
                set("value", 30000);
                set("rigidity", 300);
                set("unique", 1);
                set("material", "steel");
                set("robpending",1); //不抢
                set("preorder",0);
                set("robinterval",36);  
        }
        init_blade(180);
        set("wield_msg", HIG"$N抓起刀柄，只觉眼前青光一闪，寒气逼人，手中已多了一柄的$n"+HIG"，刀光如水，流转不定。\n"NOR);
        setup();
}


