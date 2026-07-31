// hammer.c



#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;

void setup()
{
        // ::setup();
        seteuid(getuid());

        if( clonep(this_object()) ) return;


        set("skill_type", "finger");
        if( !query("actions") )
           {
        set("actions", (: call_other, WEAPON_D, "query_action" :) );
        set("verbs", ({ "chuo" }) );
           }
}





varargs void init_finger(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag );

}

