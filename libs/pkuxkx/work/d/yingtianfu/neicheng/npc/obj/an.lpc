
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
	add_action("do_place","fangzhi");
}

int do_place(string arg)
{
	object ob=this_object(),me=this_player();
	if (!arg||arg!="an juan")
	{
		return notify_fail("你要放置什么东西？\n");
	}
	if (!me->query("mingpin"))
	{
		return 0;
	}
	if (base_name(environment(me))!="/d/yingtianfu/neicheng/xing_ku")
	{
		return notify_fail("案卷可不能乱放啊！\n");
	}
	if (me->query_temp("mingtasks/dalisi/task")!=2)
	{
		return notify_fail("你别弄乱了这里的宗卷。\n");
	}
	if (ob->query("owner")!=me)
	{
		tell_object(me,"你帮忙把宗卷放了下来。\n");
		destruct(ob);
		return 1;
	}
	tell_object(me,"你帮忙把宗卷放了下来。\n");
	me->add("ming/credit",3);
	me->delete_temp("mingtasks");
	tell_object(me,HIC+"你的任务圆满完成，你的大明功勋增加了。\n"+NOR);
	destruct(ob);
	return 1;
}