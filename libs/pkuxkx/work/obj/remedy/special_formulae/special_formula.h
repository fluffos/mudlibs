#include <ansi.h>
void init()
{
	add_action("do_yanjiu","yanjiu");
}
mapping formula()
{
	mapping *formulae=REMEDY->player_formula(({replace_string(COLOR_D->uncolor(this_object()->query("name")),"古方","")}));
	return formulae[0];
}
int do_yanjiu()
{
	object me=this_player();
	string *list=(me->query("myPrescriptionList")&&arrayp(me->query("myPrescriptionList")))?me->query("myPrescriptionList"):({});
	mapping pres=formula(),*myPres=(me->query("myPrescriptions")&&arrayp(me->query("myPrescriptions")))?me->query("myPrescriptions"):({});
	if (member_array(pres["name"],list)!=-1)
	{
		tell_object(me,"你已经掌握了"+pres["name"]+"的配方，这个对你没有什么帮助了。\n");
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
