#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("古方", ({"gu fang", "fang","prescription"}));
        set_weight(50);
        set("long", "这是一张不知从何处流传下来的古代药方。\n");
        set("unit", "张");
		set("value",100);
}
//raws是药材配方数量，product是药品目录，product_no是炼成最大产量，period是炼成时间，maker_level是玩家允许炼药最低级别，improve_level是在多少级alchemy之前可以提升，phase_color只能使用0,1,2(MAG,HIW,HIR三种颜色)，代表火焰颜色。skill_points和提升alchemy技能有关，furnace_lv是要求的药炉等级，chance是获得概率，越高越难获得0-1000。
mapping * formulae()
{
	return REMEDY->player_formula(({"九转紫金丹"}));
}
mapping ObtainFormula(object me,int chance)
{
	mapping *formulae=formulae(),*backups=({});
	if (me)
	{
		for (int i=0;i<sizeof(formulae);i++)
		if (formulae[i]["chance"]<=chance)
		backups+=({formulae[i]});
		if (sizeof(backups)>0)
		return backups[random(sizeof(backups))];
	}
}
void init()
{
	add_action("do_yanjiu","yanjiu");
}
int do_yanjiu()
{
	object me=this_player();
	int chance=1000-random(1001);
	string *list=(me->query("myPrescriptionList")&&arrayp(me->query("myPrescriptionList")))?me->query("myPrescriptionList"):({});
	mapping pres,*myPres=(me->query("myPrescriptions")&&arrayp(me->query("myPrescriptions")))?me->query("myPrescriptions"):({});
	if (mapp(pres=ObtainFormula(me,chance))&&member_array(pres["name"],list)==-1)
	{
		myPres+=({pres});
		me->set("myPrescriptions",myPres);
		list+=({pres["name"]});
		me->set("myPrescriptionList",list);
		tell_object(me,HIG+"恭喜！你学到了"+pres["name"]+"的配方。\n"+NOR);
	}
	else
	{
		tell_object(me,"可惜这个古方晦涩难懂，你什么都没有学到。\n");
	}
	message_vision("$N化成纸屑，飘散在风中。\n",this_object());
	destruct(this_object());
	return 1;
}
