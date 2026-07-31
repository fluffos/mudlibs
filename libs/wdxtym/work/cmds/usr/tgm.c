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
	/* if(m = VIP_D->query_qian(me->query("id")))
	{ */
		if(!arg || arg!="tixian")
		{
			line = keys(m);
			for(i=0;i<sizeof(line);i++)
			{
				if(line[i]=="jf_used") continue;
				sum += (m[line[i]]-1);
			}
			if(sum<0) sum = 0;
			sum2 = VIP_D->query_qian(me->query("id")+"/jf_used");
			sum2 = sum - sum2;
			txt = ZJOBLONG"你已经是推广员了，无需重复申请，目前推广点券 可用："+sum2+"/总："+sum+" 。"ZJBR
			"你的登陆帐号["+me->query("id")+"]就是你的推广码，新人在武庙输入你的推广码即可领取到推广礼盒，"
			"新人成长和在游戏里消费都会给与你一定的推广点券，每10点券可以申请提现1块钱或者兑换15灵石！\n";
			txt += ZJOBACTS2+ZJMENUF(3,3,10,30);
			txt += "兑换灵石:tg2yb";
			txt += ZJSEP"申请提现:tgm tixian";
			write(txt+"\n");
			return 1;
		}
		else
			return notify_fail("提现请联系管理员，请尽量累计超过100元再申请提现以减轻管理员负担！\n");
/*	}
	else
		return notify_fail("推广员自助申请已停止,如有需要请联系管理员！\n");
 */
	VIP_D->set_qian(me->query("id"),([]));
	write("推广员申请成功，你的登陆帐号["+me->query("id")+"]就是你的推广码，新人在武庙输入你的推广码即可领取到推广礼盒，"
		"新人成长和在游戏里消费都会给与你一定的推广点券，每10点券可以申请提现1块钱！\n");
	VIP_D->save();
	
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
