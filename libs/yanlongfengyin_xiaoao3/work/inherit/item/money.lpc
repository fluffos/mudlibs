// money.c

#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;

int value() { return query_amount() * (int)query("base_value"); }

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
        int amt;

        if( sscanf(param, "%d", amt)==1 )
                set_amount(amt);
}


varargs void init_throwing(int damage, int flag)
{
        if( clonep(this_object()) ) return;

        set("weapon_prop/damage", damage);
        set("flag", flag);
}

void setup()
{
        // ::setup();
        seteuid(getuid());

        if( clonep(this_object()) ) return;

        set("skill_type", "throwing");
        if( !query("actions") ) {
                set("actions", (: call_other,WEAPON_D, "query_action" :));
                set("verbs", ({ "throw" }) );
        }
}

