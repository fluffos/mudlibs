// hammer.c

#include <weapon.h>

inherit EQUIP;

varargs void init_unarmed(int damage, int flag)
{
        if( clonep(this_object()) ) return;
        
        set("weapon_prop/damage", damage);
        set("flag", flag );
}

void setup()
{
        ::setup();

        if( clonep(this_object()) ) return;

        set("skill_type", "unarmed");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "claw", "impale", "pierce"}) );
        }
}
