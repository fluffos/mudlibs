// Weapon: /d/new_taohua/obj/skysword.c
// Copyright (C) 1997, by Kou Gang. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
     set_name( HIG "碧血剑" NOR, ({ "sword" }) );
 set_weight(1000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"这是一把杀气逼人的宝剑\n"
);
   set("value", 21500000);
                set("material", "steel");
                set("rigidity", 100000);
  set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }

   init_sword(150);
        setup();

}
