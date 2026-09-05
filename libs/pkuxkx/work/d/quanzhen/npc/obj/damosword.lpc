// Weapon: /d/shaolin/obj/damosword.c
// Copyright (C) 1997, by Hacker. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( BLU "达摩剑" NOR, ({ "damo sword","sword","damo" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"这是一把湛蓝湛蓝的长剑,剑刃间波光闪动,一看便知是一把神器。\n"
);
                set("value", 1500000);
                set("material", "steel");
                set("rigidity", 100000);
                set("wield_msg", HIY "铮地一声,$N的手中已多了一把古色古香的$n。\n" NOR);
                set("unequip_msg", HIY "$N将手中的$n插入腰间的剑鞘。\n" NOR);
        }

       init_sword(200);
        setup();

}
