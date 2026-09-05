#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"蛇胆川贝散炼法"NOR, ({"shedansan lianfa", "lianfa","fa","prescription"}));
        set_weight(50);
        set("long", "这是药铺老板家传的蛇胆川贝散炼制方法详解。\n");
        set("unit", "页");
		set("value",30000000);
}
//raws是药材配方数量，product是药品目录，product_no是炼成最大产量，period是炼成时间，maker_level是玩家允许炼药最低级别，improve_level是在多少级alchemy之前可以提升，phase_color只能使用0,1,2(MAG,HIW,HIR三种颜色)，代表火焰颜色。skill_points和提升alchemy技能有关，furnace_lv是要求的药炉等级，chance是获得概率，越高越难获得0-1000。
mapping * formulae()
{
	return REMEDY->player_formula(({"蛇胆川贝散"}));
}
mapping formula()
{
	mapping *formulae=formulae();
	return formulae[0];
}
void init()
{
	add_action("do_yanjiu","yanjiu");
}
int do_yanjiu()
{
	object me=this_player();
	string *list=(me->query("myPrescriptionList")&&arrayp(me->query("myPrescriptionList")))?me->query("myPrescriptionList"):({});
	mapping pres=formula(),*myPres=(me->query("myPrescriptions")&&arrayp(me->query("myPrescriptions")))?me->query("myPrescriptions"):({});
	if (member_array(pres["name"],list)!=-1)
	{
		tell_object(me,"你已经掌握了"+pres["name"]+"的配方，这个对你没有什么帮助了。\n");
		return 1;
	}
	else
	{
		myPres+=({pres});
		me->set("myPrescriptions",myPres);
		list+=({pres["name"]});
		me->set("myPrescriptionList",list);
		tell_object(me,HIG+"恭喜！你学到了"+pres["name"]+"的配方。\n"+NOR);
	}
	message_vision(HIY+"$N"+HIY+"化成纸屑，飘散在风中。\n"+NOR,this_object());
	destruct(this_object());
	return 1;
}
