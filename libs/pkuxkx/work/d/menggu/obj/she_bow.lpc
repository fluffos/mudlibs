// bow
#include "/d/menggu/obj/zhai.h"
#include <weapon.h>
inherit STAFF;

void create()
{
    set_name("硬弓", ({ "ying gong","gong","bow" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把硬弓，是草原上的战士喜用之物。\n");
		set("value", 5500);
		set("material", "steel");
		set("wield_msg", "$N从背后抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n挂回背后。\n");
        set("arrow_assist",100);
		set("is__bow",1);
		set("arrow",1);
		set("arrow_file","/d/menggu/obj/arrow");
		set("str_require",15);
		set("xt_str_require",10);
	}
  	init_staff(25);
	setup();
}
