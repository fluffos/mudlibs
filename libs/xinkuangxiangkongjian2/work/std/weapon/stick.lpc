
// stick.c

#include <weapon.h>

inherit EQUIP;

varargs void init_stick(int damage, int flag)
{
        if( clonep(this_object()) ) return;

        set("weapon_prop/damage", damage);
        set("flag", (int)flag | LONG );
}

void setup()
{
        ::setup();

        if( clonep(this_object()) ) return;

        set("skill_type", "stick");
        if( !query("actions") ) {
                set("actions", (: WEAPON_D, "query_action" :) );
                set("verbs", ({ "bash", "crush", "slam" }) );
        }
}
