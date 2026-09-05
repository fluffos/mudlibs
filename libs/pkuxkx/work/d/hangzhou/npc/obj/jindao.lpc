
#include <weapon.h>
inherit BLADE;
#include <ansi.h>
void create()
{
	set_name(HIY"金背砍山刀"NOR, ({ "jinbei dao", "dao" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄金背砍山刀，韩世忠的成名兵刃。\n");
		set("value", 0);
		set("no_store",1);
		set("no_pawn",1);
		set("material", "leather");
		set("wield_msg", "$N「唰」的一声抖出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n别回腰间。\n");
		set("wield_restrict",
			([    
			"str":({"臂力",30,-1}),
			"query_str":({"后天臂力",50,-1}),
			"double_hand":({1}),
			])
		);
	}
	init_blade(350);
	setup();
	call_out("dest",7200);
}

int dest()
{
	object me;
	if (environment(this_object())&&userp(me=environment(this_object())))
	{
		tell_object(me,this_object()->query("name")+"上出现了皲裂，似乎是要损毁了。\n");
	}
	destruct(this_object());
	return 1;
}