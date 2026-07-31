// sp.c

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string msg,type,tx_id;
	int num1,num2,tx_num;
	mapping jfs;
	
	if(!arg) 
	{
		msg = ZJOBLONG"请选择你想进行的以下操作：\n";
		if( !VIP_D->query_tgy(me->query("id")) )
		{
			msg += ZJOBACTS2+ZJMENUF(1,1,10,30);
			if(!me->query("tgy_id"))
			msg += "填写推广码:tg -lb"ZJSEP;
			msg += "申请推广码:tg -app";
			msg += ZJSEP"推广福利:help tg";
		}
		else
		{
			msg += ZJOBACTS2+ZJMENUF(2,2,10,30);
			if(!me->query("tgy_id"))
			msg += "填写推广码领:tg -lb"ZJSEP;
			msg += "查询推广点券:tg -query";
			msg += ZJSEP"点券兑换灵石:tg -convert";
			msg += ZJSEP"点券提现:tg -tixian";
		}
		if(SECURITY_D->valid_grant(me, "(admin)"))
			msg += ZJSEP+HIM"重置推广"NOR":tg -reset";
		
		write(msg+"\n");
		return 1;
	}
	
	if(arg == "-reset")
	{
		if(!SECURITY_D->valid_grant(me, "(admin)") ) return notify_fail("你不是天神，无法使用推广点券重置功能\n");
		else VIP_D->reset_tg(me);
		return 1;
	}
	
	
	if(sscanf(arg,"-wiz_tixian %s %d",tx_id,tx_num) == 2)
	{//巫师进行提现点券扣除
		if(!wizardp(me)) return notify_fail("你不是游戏管理员，不要乱来！~\n");
		if(tx_num <= 0) return notify_fail("点券提现只能在ID后面输入大于0的正整数\n");
		tx_num = 0-tx_num;
		num1 = VIP_D->add_tgy_jf(tx_id,tx_num);
		if(num1 == -1) return notify_fail("没有这个("+tx_id+")推广员\n");
		if(num1 == -2) return notify_fail("推广员("+tx_id+")的点券不足"+tx_num+"点\n");
		
		tell_object(me,"成功扣除("+tx_id+")推广点券"+tx_num+"点\n");
		return 1;
	}
	else if(sscanf(arg,"%s %d",type,num1) != 2)
		type = arg;
	// write("当前type"+type+"| num1=="+num1+"| arg=="+arg+"\n");
	
	switch(type)
	{
		case "-lb":
			return notify_fail(INPUTTXT("请填写你要使用的推广码：","tg $txt#")+"\n");
			break;
		case "-app"://申请成为推广员
			num1 = VIP_D->set_tgy(me);
			if(num1 == 0)
				return notify_fail("当前玩家状态出错，判定为非玩家物件\n");
			else if(num1 == -1)
				return notify_fail("你已经成是推广员了，无需重复申请\n");
			else if(num1 == 1)
				write("恭喜你成为的推广员，你的游戏ID("+me->query("id")+")即是你的推广号码。\n");
			break;
		case "-query"://查询推广点券
			jfs = VIP_D->query_tgy(me->query("id"));
			num1 = jfs["jf_all"];
			num2 = jfs["jf_use"];
			write("你当前的推广点券如下：\n推广总点券："+num1+"\n剩余点券："+(num1-num2)+"\n已使用点券："+num2+"。\n");
			break;
		case "-convert"://点券兑换灵石
			if(!num1 || num1 <= 0)
				return notify_fail(INPUTTXT("请输入你要兑换多少点券的灵石：","tg -convert $txt#")+"\n");
			
			num2 = VIP_D->tgy_convert(me,num1);
			if(num2 == -1) return notify_fail("你还不是推广员，无法兑换灵石\n");
			if(num2 == -2) return notify_fail("你的推广点券不足"+num1+"点\n");
			tell_object(me,"成功兑换推广点券"+num1+"点，获得灵石"+num2+"\n");
			break;
		case "-tixian"://点券提现
			if(!wizardp(me))
				return notify_fail("提现请联系管理员，请尽量累计超过100元再申请提现以减轻管理员负担！\n");
			else
				return notify_fail(INPUTTXT("请填写你要提现的ID和数量以空格隔开，如下："ZJBR"abc123 500","tg -wiz_tixian $txt#")+"\n");
			break;
		default ://填写推广码领取礼包
			//领取条件
			if(!VIP_D->query_tgy(type))
				return notify_fail("当前推广码对应的ID并未申请成为推广员，无法领取推广礼包\n");
			if(type == me->query("id"))
				return notify_fail("你无法使用自己的推广码来领取推广礼包\n");
			if(me->query("tgy_id"))
				return notify_fail("你已经领取过推广礼包，无法重复领取\n");
			//进行推广码的填写
			VIP_D->use_tgm(type,me);
			break;
	}

	return 1;
}

int help (object me)
{
	write(@HELP
推广福利：每2点券可以换3灵石，被推广者可以领取礼包
HELP );
	return 1;
}
