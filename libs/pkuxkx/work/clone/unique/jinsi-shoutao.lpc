#include <armor.h>
#include <ansi.h>

inherit HANDS;
inherit F_UNIQUE;
void create()
{
        set_name(HIY +"金丝手套"+ NOR, ({ "jinsi shoutao","shoutao" }));
        set("long","这是一双有金丝制成的手套，坚韧无比，刀剑不能伤。\n");
        set_weight( 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit","双");
                set("no_get", 1);
                set("no_drop", 1);
                set("no_steal", 1);
                set("no_give",1);
                set("no_sell",1);
                set("no_pawn",1);
                set("value",1000000);
                set("material", "silk");
                set("wear_msg", HIY "$N戴上一双$n。\n" NOR);
                set("armor_prop/armor", 300);
//                set("weapon_prop/damage",100 + random(101));
        }
        setup();
}       

