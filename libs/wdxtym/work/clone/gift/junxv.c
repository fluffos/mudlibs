
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

string *types = ({
	"force",
	"dodge",
	"unarmed",
	"cuff",
	"strike",
	"finger",
	"hand",
	"claw",
	"sword",
	"blade",
	"staff",
	"hammer",
	"club",
	"whip",
	"parry",
});

void create()
{
	set_name("北凉军需", ({"junxv"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是北凉军需，里面含有北凉制式装备一套！\n");
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 10);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int i,num1,num2,num3,num4;
	object gong,bagua,jian,kai,dao,jia;

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	num1=200000;
	//me->add("combat_exp",num1);
	num2=200000;
	//me->add("potential",num2);
	num3=2000+random(100);
	//me->add("score",num3);
	num4=50+random(30);
	//me->add("weiwang",num4);
	me->set("p_master/last_learnto",me->query("combat_exp"));
	//me->add("zjvip/times",72*3600);

	message_vision("$N打开了一" + query("unit") + name() + "。\n", me);
	//write(YEL"恭喜您：获得了"+num1+"点修为。"NOR"\n");
	//write(YEL"恭喜您：获得了"+num2+"点潜能。"NOR"\n");
	//write(YEL"恭喜您：获得了"+num3+"点江湖阅历。"NOR"\n");
	//write(YEL"恭喜您：获得了"+num4+"点江湖威望。"NOR"\n");
	//write(YEL"恭喜您：获得了3天会员时长。"NOR"\n");

	gong = new("/clone/new/beiliang/blade");
	write(YEL"您：获得了"+gong->short()+"。"NOR"\n");
	gong->move(me);
	jian = new("/clone/new/beiliang/sword");
	write(YEL"您：获得了"+jian->short()+"。"NOR"\n");
	jian->move(me);
	bagua = new("/clone/new/beiliang/cloth");
	write(YEL"您：获得了"+bagua->short()+"。"NOR"\n");
	bagua->move(me);
	kai = new("/clone/new/beiliang/boots");
	write(YEL"您：获得了"+kai->short()+"。"NOR"\n");
	kai->move(me);
	dao = new("/clone/new/beiliang/hands");
	write(YEL"您：获得了"+dao->short()+"。"NOR"\n");
	dao->move(me);	
	jia = new("/clone/new/beiliang/pants");
	write(YEL"您：获得了"+jia->short()+"。"NOR"\n");
	jia->move(me);
	for(i=0;i<sizeof(types);i++)
	{
		if(me->query_skill(types[i],1)<100)
		{
			//me->set_skill(types[i],100);
			//tell_object(me,"你学会了了100级"+to_chinese(types[i])+"。\n");
		}
	}

	add_amount(-1);
	me->save();

	return 1;
}
