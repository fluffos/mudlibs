
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("水火棒", ({ "shuihuo bang","bang","staff" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这是一把衙役用的水火棒。\n");
		set("value",60);
		set("material", "木头");
	}
	init_staff(120);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n放到地上。\n");

	setup();
}
