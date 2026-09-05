#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(CYN"青囊残篇"NOR, ({"qingnang canpian", "canpian","pian","qingnang","prescription"}));
        set_weight(50);
        set("long", "传说中华佗在狱中把一生所学装在青囊中赠与狱卒，可惜大部分却被人为损毁。\n留传下来的部分即为青囊残篇。\n");
        set("unit", "页");
		set("value",100);
}
//raws是药材配方数量，product是药品目录，product_no是炼成最大产量，period是炼成时间，maker_level是玩家允许炼药最低级别，improve_level是在多少级alchemy之前可以提升，phase_color只能使用0,1,2(MAG,HIW,HIR三种颜色)，代表火焰颜色。skill_points和提升alchemy技能有关，furnace_lv是要求的药炉等级，chance是获得概率，越高越难获得0-1000。
mapping * formulae()
{
	return REMEDY->player_formula(({"大始丹","坎离丹","噬嗑丹"}));
}
mapping ObtainFormula()
{
	mapping *backups=formulae();
	return backups[random(sizeof(backups))];
}
void init()
{
	add_action("do_yanjiu","yanjiu");
}
int do_yanjiu()
{
	object me=this_player();
	string *list=(me->query("myPrescriptionList")&&arrayp(me->query("myPrescriptionList")))?me->query("myPrescriptionList"):({});
	mapping formula,*myPres=(me->query("myPrescriptions")&&arrayp(me->query("myPrescriptions")))?me->query("myPrescriptions"):({});
	if (!me->query("tianmuQuests/dashigu/qingnang"))
	{
		formula=ObtainFormula();
		me->set("tianmuQuests/dashigu/qingnang",1);
		myPres+=({formula});
		me->set("myPrescriptions",myPres);
		list+=({formula["name"]});
		me->set("myPrescriptionList",list);
		tell_object(me,HIG+"恭喜！你从青囊残篇中学到了"+formula["name"]+"的配方。\n"+NOR);
		message_vision(CYN"$N"+CYN+"化成纸屑，飘散在风中。\n"+NOR,this_object());
		destruct(this_object());
	}
	else
	{
		tell_object(me,"你已经从青囊残篇中学到过东西了，做人不能太贪心。\n");
	}
	return 1;
}
