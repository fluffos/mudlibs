
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
	set_name(HIC "卧龙令" NOR, ({ "wolong ling" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一枚古朴的令牌，上面刻着一幅地图，像是北京朝阳门外的一座庄园，不知是什么用意。\n");
		set("base_unit", "块");
		set("where", "/d/beijing/road1");
		set("fuben_type", "wolong");
		set("only_do_effect", 1);
		set("yuanbao",100);
		set("base_weight", 1);
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
		tell_object(me,"你在这里仔细搜索了一阵，结果却毫无收获。\n");
		return 1;
	}

	if(FUBEN_D->create_fuben(me,query("fuben_type")))
	{
		message_vision(CYN "$N" CYN "发现了一个神秘的洞口，不知通向哪里？"NOR"\n", me);
		this_object()->add_amount(-1);
	}

	return 1;
}
