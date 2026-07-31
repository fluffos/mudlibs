
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
	set_name(HIW"八卦盘"NOR, ({"ba gua"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "个");
		set("base_weight", 1);
		set("base_value", 2);
		set("unit", "个");
		set("long","这是一个八卦盘，能够占卜当前师门任务npc的精确位置！\n");
		set("only_do_effect", 1);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
	}
	setup();
}


int do_effect(object me)
{
	object ob;
	mapping q;
	string area;

	if(!mapp(q=me->query("quest")))
	{
		if(!mapp(q=me->query("bquest")))
		{
      		return notify_fail("你现在没有任务，使用八卦盘占卜什么?\n");  
		}
	}
	if(q["type"]!="kill")
	{
      		return notify_fail("你现在没有师门杀人任务，无需占卜。\n");  
	}
	if((ob=find_living(q["id"]))&&environment(ob))
	{
		sscanf(base_name(environment(ob)),"/d/%s/%*s",area);
        message_vision(HIW"$N从怀里掏出一个"+name()+""HIW"，往上撒了几个铜钱，嘴里念念有词，开始掐指细算。"NOR"\n" , me);
		tell_object(me,HIR+q["name"]+NOR"（"+q["id"]+"）目前正在"HIW+MAP_D->query_map_short(area)+NOR"的"HIW+environment(ob)->query("short")+NOR"活动。\n");
	}
	else
		tell_object(me,"无法占卜到目标人物，可能是目标人物已被杀死或者消失了。\n");

	add_amount(-1);
	return 1;
}
