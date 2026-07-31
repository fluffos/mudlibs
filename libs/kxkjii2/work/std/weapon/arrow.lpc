// arrows.c

#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;
varargs void init_arrow(int damage, int flag)
{
        if( clonep(this_object()) ) return;

        set("weapon_prop/damage", damage);
        set("flag", (int)flag | POINTED | SECONDARY );
}

void setup()
{
        ::setup();
        if( clonep(this_object()) ) return;
        set("skill_type","throwing");
        set("unit","ֻ");
        set("type","is_arrows");
        if( !query("actions") ) {
                set("actions", (: WEAPON_D, "query_action" :) );
        set("verbs", ({ "throw" }) );
        }
}
