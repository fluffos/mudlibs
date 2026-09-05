// bow
#include "/d/menggu/obj/zhai.h"
#include <weapon.h>
inherit STAFF;

void create()
{
    set_name("猎弓", ({ "lie gong","gong","bow" }));
	set_weight(4500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把草原上的牧民常用的猎弓。\n");
		set("value", 1000);
		set("material", "wood");
		set("wield_msg", "$N从背后抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n挂回背后。\n");
        set("arrow_assist",65);
		set("is_hunterbow",1);
		set("is__bow",1);
		set("str_require",30);
		set("xt_str_require",15);
	}
  	init_staff(5);
	setup();
}
