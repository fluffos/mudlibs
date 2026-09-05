#include <ansi.h>

int mbzengyuan(object me)
{
    int i;
    int bing;
    object fighter;
    bing=(int)me->query_temp("skf/qb2")-random(3);
	if (bing<1)
	bing=1;
    message_vision(HIC"大明的援军马不停蹄赶了过来。\n"NOR,me);
	for (i=0;i<bing;i++)
	{
		fighter=new(__DIR__"npc/fighter");
		fighter->set_temp("skf/huaquanpass",1);
		fighter->set_temp("skf/migong",1);
		fighter->set("skfleader",me->query("id"));
		fighter->move(environment(me));
		fighter->copy(me);
		fighter->gen(me);
	}
	return 1;
}

int do_qiuyuan()
{
    object me=this_player();
    int n=2+random(12);
    if (me->query_temp("skf/mbzengyuan"))
    {
        tell_object(me,"援军已经在来的路上了。\n");
        return 1;
    }
    if (!me->query_temp("skf/qbzengyuan"))
    {
        tell_object(me,"还没开打就要求援，也不怕被人笑掉大牙？\n");
        return 1;
    }
    else
    {
        message_vision("$N嘱托一个亲兵立刻回史督师处求援。\n",me);
        me->set_temp("skf/mbzengyuan",1);
        remove_call_out("mbzengyuan");
        call_out("mbzengyuan",n,me);
        return 1;
    }
}

int do_back()
{
    object fighter,me=this_player();
    int i=(int)me->query_temp("skf/bingnumber");
    if (me->query_temp("skf/canback"))
    {
        me->set_temp("skf/winwin",1);
        message_vision(HIW"$N大喝一声：班师，好不得意！\n"NOR,me);
        message("chat",HIW"【大明】"+me->query("name")+HIW+"在长江天险击退女真骑兵，胜利班师！\n"+NOR,users());
        for (i=(int)me->query_temp("skf/bingnumber")-1;i>=0;i--)
        {
            fighter=me->query_temp("skf/fighter"+i);
            if (fighter)
            {
                fighter->dest3();
            }
        }
        me->move("/d/city/junying");
        me->set_temp("skf/canceltimeup",1);
        return 1;
    }
    else
    {
        return 0;
    }
}

int occupy_msg(string side)
{
	if (side=="ming")
	{
		message( "channel:" + "rumor",HIM+"【谣言】某人: 大明军队夺回了"+this_object()->query("short")+HIM+"。\n"+NOR,users());
	}
	if (side=="qing")
	{
		message( "channel:" + "rumor",HIM+"【谣言】某人: 女真铁骑占领了"+this_object()->query("short")+HIM+"。\n"+NOR,users());
	}
}

int fighting(int flag)
{
    object qb,me,cj;
    int i,group;
    cj=load_object(__DIR__"changjiang-2");
    me=find_player(cj->query("user"));
    if (!me)
    {
        return 1;
    }
	if (flag==1)
    group=me->query_temp("skf/g1");
	if (flag==2)
    group=me->query_temp("skf/g2");
	if (flag==3)
    group=me->query_temp("skf/g3");
	if (flag==4)
    group=me->query_temp("skf/g4");
    for (i=0;i<group;i++)
    {
        qb=new(__DIR__"npc/nvzhen-qibing");
        qb->set("target",me->query("id"));
        qb->copy(me);
        qb->move(this_object());
    }
	if (flag==3||flag==4)
	{
		tell_object(me,HIR+chinese_number(group)+"队女真援军到了。\n"NOR);
	}
    return 1;
}

