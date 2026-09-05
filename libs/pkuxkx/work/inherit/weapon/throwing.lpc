// throwing.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit COMBINED_EQUIP;
#endif


varargs void init_throwing(int damage, int flag)
{
  //如果没有设置数量，则设置初始化数量为1
  if ( !query_amount() )
    set_amount(1);
  
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag);
          set("skill_type", "throwing");
          if( !query("actions") ) {
                  set("actions", (: call_other, WEAPON_D, "query_action" :) );
                  set("verbs", ({ "throw" }) );
        }

}

