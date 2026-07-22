#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name(HIY"金龙鞭"NOR, ({ "whip", "jinlong bian" , "bian" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "这是一条金光闪闪，镶满宝石的长鞭。\n");
		set("value", 1000000);
		set("material", "leather");
		set("wield_msg", "$N「唰」的一声抖出一条$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n卷回腰间。\n");
	}
	init_whip(200);
	setup();
}
