 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("Í­·ð¹Ä", ({ "fogu" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("value", 500);
                set("material", "wood");
                set("long", "Ò»¸öÂÌ°ß°ßµÄÍ­·ð¹Ä¡£\n");
                set("weapon_prop/karma",1);
        }
        ::init_hammer(5);
} 
