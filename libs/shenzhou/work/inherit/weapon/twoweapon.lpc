#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

// blade.c
varargs void init_blade(int damage, int flag)
{
        
        set("weapon_prop/damage", damage);
        set("flag", flag | EDGED | SECONDARY );
        set("skill_type", "blade");
        if( !query("actions") ) {
                set("actions", (: call_other,WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "hack" }) );
        }
}
// sword.c
varargs void init_sword(int damage, int flag)
{
        set("weapon_prop/damage", damage);
        set("flag", flag | EDGED | SECONDARY );
        set("skill_type", "sword");
        if( !query("actions") ) {
                set("actions", (: call_other,WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "thrust" }) );
        }
}
