//Modified By Zine 2012/1/10 只是显示列别不扣分，显示详细状态才扣3分。
inherit "/cmds/guider/guidercmd";
#include <ansi.h>
int get_cost(object me) 
{
	if (time()<1358663315)//变更命令，给出一星期适应。
	return 0;
	if (me->query_temp("last_command")=="listapp -f")
	return 3;
	else
	return 0;
}

#include <ansi.h>
string get_status(object ob)
{
	if (ob->is_ghost())
	return HIB+"▇▇"+NOR;
	else if (ob->is_fighting())
	return HIR+"▇▇"+NOR;
	else if (ob->is_busy())
	return HIY+"▇▇"+NOR;
	else if (query_idle(ob) > 120)
	return HIM+"▇▇"+NOR;
	else
	return HIG+"▇▇"+NOR;
}
int detail(string *apps,string str)
{
	object ob;
	for(int i=0;i<sizeof(apps);i++)
	{
		write(sprintf("%d, %s",i+1,apps[i]));
		if (str=="-f")
		{
			ob = find_player(apps[i]);
			if(objectp(ob))
			{
				if(objectp(environment(ob)))
				write(sprintf("%s%s\n"," 目前正在" + TASK_D->place_belong(environment(ob))+"的"+environment(ob)->query("short")," "+get_status(ob)));
				else
				write(sprintf("%s%s\n"," 目前所在未知"," "+get_status(ob)));
			}
			else
			write(WHT"▇▇\n"NOR);
		}
		else
		write("\n");
	}
	return 1;
}
int exec_cmd(object me, string str)
{
    string* apps;
    int i;
    object ob;
    if(me->is_busy()) 
	{
		tell_object(me,"你正忙着呢。\n");
		return 0;
	}
	if(arrayp(apps=GUIDER_D->app_list(me->query("id")))&&sizeof(apps)>0)
	{
		write(HBBLU+HIR+"你的门下现在有以下新手学员聆听你的教诲：\n"+NOR);
		detail(apps,str);
	}
	if (arrayp(apps=GUIDER_D->oldapp_list(me->query("id")))&&sizeof(apps)>0)
	{
		write(HBBLU+HIW+"你的门下已经出师的学生：\n"+NOR);
		detail(apps,str);
	}
	if (str=="-f")
	write("\n状态说明："+WHT+"▇▇"+NOR+"-离线 "+HIB+"▇▇"+NOR+"-死亡 "+HIR+"▇▇"+NOR+"-战斗中 "+HIY+"▇▇"+NOR+"-忙 "+HIM+"▇▇"+NOR+"-发呆中 "+HIG+"▇▇"+NOR+"-无特殊状态。\n"+NOR);
    me->start_busy(2);
    return 1;
}


int help(object me)
{
        write(@HELP
指令格式: listapp
这个指令让你可以查看你所有的新手学员。
HELP
    );
    return 1;
}
