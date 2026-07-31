// Created By Longer@SJSH
#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif
#include <ansi.h>
// axe.c
varargs void init_axe(int damage, int flag)
{

        set("weapon_prop/damage", damage);
        set("flag", (int)flag | EDGED);
        set("skill_type", "axe");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "chop", "slice", "hack" }) );
        }
}


// blade.c
varargs void init_blade(int damage, int flag)
{

        set("weapon_prop/damage", damage);
        set("flag", (int)flag | EDGED);
        set("skill_type", "blade");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "hack" }) );
        }
}

// stick.c
varargs void init_stick(int damage, int flag)
{

        set("weapon_prop/damage", damage);
        set("flag", (int)flag | LONG );
        set("skill_type", "stick");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "stick", }) );
        }
}

// spear.c

varargs void init_spear(int damage, int flag)
{


        set("weapon_prop/damage", damage);
        set("flag", flag | EDGED | SECONDARY );
        set("skill_type", "spear");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "spear" }) );
        }
}

// fork.c

varargs void init_fork(int damage, int flag)
{


        set("weapon_prop/damage", damage);
        set("flag", (int)flag | POINTED);
        set("skill_type", "fork");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "thrust" }) );
        }
}

// hammer.c

varargs void init_hammer(int damage, int flag)
{


        set("weapon_prop/damage", damage);
        set("flag", flag );
        set("skill_type", "hammer");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "bash", "crush", "slam" }) );
        }
}

// staff.c

varargs void init_staff(int damage, int flag)
{


        set("weapon_prop/damage", damage);
        set("flag", (int)flag | LONG );
        set("skill_type", "staff");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "bash", "crush", "slam" }) );
        }
}

// sword.c


varargs void init_sword(int damage, int flag)
{


        set("weapon_prop/damage", damage);
        set("flag", (int)flag | EDGED);
        set("skill_type", "sword");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "thrust" }) );
        }
}

// whip.c

varargs void init_whip(int damage, int flag)
{


        set("weapon_prop/damage", damage);
        set("flag", flag );
        set("skill_type", "whip");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "whip" }) );
        }
}

// mace.c

varargs void init_mace(int damage, int flag)
{


        set("weapon_prop/damage", damage);
        set("flag", flag );
        set("skill_type", "mace");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "mace" }) );
        }
}

