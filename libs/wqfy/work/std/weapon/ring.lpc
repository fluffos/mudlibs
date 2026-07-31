// dagger.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_ring(int damage, int flag)
{
	if( clonep(this_object()) ) return;
	set("weapon_prop/damage", damage);
	set("flag", flag | NO_HANDED);
	set("skill_type", "unarmed");
}

