// learnto.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string userid;
	object ob;
	int last_learnto,exp;

	if(!arg)
		return notify_fail("你要和谁交流？？\n");
	else if(sscanf(arg,"dizi %s",userid)==1)
	{
		if(!objectp(ob = find_player(userid))||!present(ob,environment(me))||ob->query("p_master/id")!=me->query("id")||!me->query("p_dizi/"+ob->query("id")))
			return notify_fail("你要指点谁？？\n");
		if(!(last_learnto=me->query("p_dizi/"+ob->query("id")+"/last_learnto")))
		{
			me->set("p_dizi/"+ob->query("id")+"/last_learnto",me->query("combat_exp"));
			return notify_fail("你们师徒之间经过一番交流，定下了以后的教学进度，接下来就是要努力的时刻了，加油吧！！\n");
		}
		if((last_learnto+10)>=me->query("combat_exp"))
			return notify_fail("你自上次教这徒弟之后还没有啥明显进步，暂时不能再指点这个徒弟了！！\n");
		if(ob->query("combat_exp")>1000000)
			return notify_fail("你这徒弟已经达到了出师的地步，无需你的指点了！！\n");
		exp = (me->query("combat_exp")-last_learnto)/10;
		if(exp>10000) exp = 10000;
		ob->add("combat_exp",exp);
		ob->add("potential",exp/3);
		me->set("p_dizi/"+ob->query("id")+"/last_learnto",me->query("combat_exp"));
		write("你的徒弟"HIG+ob->query("name")+NOR"在你的指点下获得了"HIY+exp+NOR"点修为和"HIY+exp/3+NOR"点潜能。\n");
		tell_object(ob,"你在你的师傅"HIG+me->query("name")+NOR"的指点下获得了"HIY+exp+NOR"点修为和"HIY+exp/3+NOR"点潜能。\n");
	}
	else if(sscanf(arg,"master %s",userid)==1)
	{
		if(!objectp(ob = find_player(userid))||!present(ob,environment(me))||me->query("p_master/id")!=ob->query("id")||!ob->query("p_dizi/"+me->query("id")))
			return notify_fail("你要向谁请安？？\n");
		if(!(last_learnto=me->query("p_master/last_learnto")))
		{
			me->set("p_master/last_learnto",me->query("combat_exp"));
			return notify_fail("你们师徒之间经过一番交流，定下了以后的教学进度，接下来就是要努力的时刻了，加油吧！！\n");
		}
		if((last_learnto+20)>=me->query("combat_exp"))
			return notify_fail("你自上向师傅请安之后还没有啥明显进步，这样去请安恐怕师傅会不满意吧！！\n");
		if(me->query("combat_exp")>1000000)
			return notify_fail("你已经达到了出师的地步，你现在还是先去出师吧！！\n");
		exp = (me->query("combat_exp")-last_learnto)/20;
		if(exp>10000) exp = 10000;
		ob->add("combat_exp",exp);
		ob->add("potential",exp/3);
		me->set("p_master/last_learnto",me->query("combat_exp"));
		write("你的师傅"HIG+ob->query("name")+NOR"对你的修炼十分满意，大为开怀之下修为获得了提升。\n");
		tell_object(ob,"你看到你的徒弟"HIG+me->query("name")+NOR"修为得到了明显提高，大喜之下豁然贯通，获得了"HIY+exp+NOR"点修为和"HIY+exp/3+NOR"点潜能。\n");
	}
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: time

玩家师徒之间的修为交流

HELP
    );
    return 1;
}
