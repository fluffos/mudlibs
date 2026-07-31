 // staff.c
#include <weapon.h>
#include <ansi.h>
inherit SWORD; 
void create() {
        set_name(YEL"裹布木棍"NOR, ({ "staffs" }) );
        set_weight(1000);
        if(clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一把裹着黄布的普通木棍。");
                set("value", 2000);
                set("material", "steel");
                set("rigidity", 80);
                set("wield_msg", "$N把$n紧紧地握在手中。\n");
                set("unwield_msg", "$N松开了手中的$n。\n");
        }
    ::init_sword(40);
}
