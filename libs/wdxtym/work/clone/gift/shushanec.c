
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
	set_name(HIY "天"HIW"宫" NOR, ({ "shushanec" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", MAG"这是一枚古朴发紫的令牌，听说在扬州广场使用它，能开启前往天宫之路。\n"NOR);
		set("base_unit", "块");
		set("where", "/d/beijing/tiannanmen");
		set("fuben_type", "shushanec");
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
	int i,w;
    object *players;
	object *t;
	 players = me->query_team();
      w = sizeof(players);
	message_vision(XYTISHI+CYN "$N" CYN "拿着一块" + name() + CYN "，开始观察四周。"NOR"\n", me);
	if(base_name(environment(me))!=query("where"))
	{
		tell_object(me,XYTISHI"你在这里仔细搜索了一阵，结果却毫无收获。\n");
		return 1;
	}

	if(FUBEN_D->create_fuben(me,query("fuben_type")))
	{
			if (! pointerp(t = me->query_team()))
		{
		  tell_object(me,XYTISHI+HIR "你还有"HIY+(me->query("shushanec")-1)+HIC"次天宫机会！\n"NOR); 
		}
	 for(i = 0; i<sizeof(players); i++)
         {
		  tell_object(players[i],XYTISHI+HIR "你还有"HIY+(players[i]->query("shushanec")-1)+HIC"次天宫机会！\n"NOR); 
	   }
		message_vision(XYTISHI+CYN "$N" CYN "发现了一个神秘的洞口，不知通向哪里？"NOR"\n", me);
		this_object()->add_amount(-1);
		tell_object(me,ZJFORCECMD("look"));
	}

	return 1;
}
