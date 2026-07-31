//OBJECT: /d/suzhou/npc/obj/chafu.c
//by dwolf                   
//97.11.7

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( BLK"茶壶"NOR, ({ "cha hu", "hu" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
		set("long", YEL"一只装茶水的茶壶。"NOR);
                set("value", 1000);
        }
        setup();
}                                                    

