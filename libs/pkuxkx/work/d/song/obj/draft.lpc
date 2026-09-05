
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(CYN"已复核的案卷"NOR, ({ "an juan", }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "份");
                set("material", "paper");
        }
        setup();
}

void init()
{
	add_action("do_deliver","deliver");
}

int do_deliver()
{
	object ob=this_object(),me=this_player();
	if (me->query_temp("songtasks/junqi/2/finish"))
	{
		return notify_fail("你的任务圆满完成，可以回军器监复命了。\n");
	}
	if (base_name(environment(me))!="/d/song/junqi_zuofang")
	{
		return notify_fail("你可不能把新的兵器草图随便乱丢啊。\n");
	}
	if (me->query_temp("songtasks/junqi/task")!=2)
	{
		return notify_fail("你哪弄来的草图。\n");
	}
	if (ob->query("owner")!=me)
	{
		tell_object(me,"你赶紧把草图丢在一旁。\n");
		destruct(ob);
		return 1;
	}
	tell_object(me,"你把草图递送给军器监作坊里的工匠。\n");
	me->set_temp("songtasks/junqi/2/finish",1);
	tell_object(me,HIC+"你的任务圆满完成，可以回军器监复命了。\n"+NOR);
	destruct(ob);
	return 1;
}