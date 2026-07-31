// sp.c

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string txt,*line;
	int i,k,sum=0,sum2;
	mapping m;
	
	if (!wizardp(me)) return 0;
	if(!(m = VIP_D->query_qian(me->query("id"))))
		return notify_fail("你还没有推广员资质！\n");

	line = keys(m);
	for(i=0;i<sizeof(line);i++)
	{
		if(line[i]=="jf_used") continue;
		sum += (m[line[i]]-1);
	}
	if(sum<0) sum = 0;
	sum2 = VIP_D->query_qian(me->query("id")+"/jf_used");

	if(!arg || sscanf(arg,"%d",k)!=1)
	{
		write(INPUTTXT("你目前推广点券 可用："+(sum-sum2) + "/总：" + sum+" ，每2点券可以兑换3灵石，你想消耗多少点券兑换？","tg2yb $txt#")+"\n");
		return 1;
	}

	if(k<1)
		return notify_fail("你想干什么！\n");

	if(k>(sum-sum2))
		return notify_fail("你没有那么多可用点券了！\n");

	sum2 += k;
	VIP_D->save();
	VIP_D->set_qian(me->query("id")+"/jf_used",sum2);
	me->add("yuanbao",k*3/2);
	log_ufile(me,"tg2yb","消耗 "+k+" 推广点券，灵石增加 "+(k*3/2)+" 。\n");
	write("你消耗 "+k+" 推广点券，灵石增加 "+(k*3/2)+" 。\n");

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: tgm 
设定推广员
HELP );
	return 1;
}
