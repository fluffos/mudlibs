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

        ::setup();
}

