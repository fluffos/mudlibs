// hands.c

#include <armor.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void setup()
{
	if (! clonep(this_object()))
		set("armor_type", TYPE_HANDS);
set("armor_buwei", "手部");
 if( !query("armor_apply/dodge") &&	 weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );

	::setup();
}

