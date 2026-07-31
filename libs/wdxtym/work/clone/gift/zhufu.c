
#include <ansi.h>
inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIR "为民除害" NOR, ({ "zhufu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", MAG"这是一枚古朴发紫的令牌，听说在扬州广场使用它，能开启前往朱府之路。\n"NOR);
		set("base_unit", "块");
		set("where", "/d/beijing/huodong");
		set("fuben_type", "zhufu");
		set("only_do_effect", 1);
		set("tydbl",100);
		set("base_weight", 1);
			set("no_put", 1);
	set("no_give", 1);
	set("no_drop", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_hand", 1);

	}
	setup();
}


int do_effect(object me)
{
	string family,*skills;
	int i;

	message_vision(CYN "$N" CYN "拿着一块" + name() + CYN "，开始观察四周。"NOR"\n", me);
	if(base_name(environment(me))!=query("where"))
	{
		tell_object(me,XYTISHI"你在这里仔细搜索了一阵，结果却毫无收获。\n");
		return 1;
	}

	if(FUBEN_D->create_fuben(me,query("fuben_type")))
	{
		message_vision(XYTISHI+CYN "$N" CYN "发现了一个神秘的洞口，不知通向哪里？"NOR"\n", me);
		this_object()->add_amount(-1);
		tell_object(me,ZJFORCECMD("look"));
	}

	return 1;
}
