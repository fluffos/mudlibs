// time.c					  
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string amr,str;
	if(!arg)
	{
		if(!me->query_temp("pindao"))
		{
			arg = "chat";
			str = "闲聊";
		}
	}
	else if(arg=="chat")
	{
		str = "闲聊";
	}
	else if(arg=="rumor")
	{
		str = "谣言";
	}
	else if(arg=="sos")
	{
		str = "求助";
	}
	else if(arg=="party")
	{
		str = "帮派";
	}
	else if(arg=="family")
	{
		str = "同门";
	}
	else if(arg=="jiaoyi")
	{
		str = "拍卖";
	}
	else if(arg=="bill")
	{
		str = "交易";
	}
	else if(arg=="ultra")
	{
		str = "大宗师";
	}
	else if(arg=="rultra")
	{
		str = "塞外宗师";
	}
	else if(arg=="inter")
	{
		str = "联盟";
	}
	else if(arg=="pindao")
	{
		write(ZJOBLONG"请选择聊天频道：\n"+ZJOBACTS2+ZJMENUF(3,3,9,30)
				+"闲聊:liaotian chat"ZJSEP"谣言:liaotian rumor"ZJSEP"求助:liaotian sos"ZJSEP"同门:liaotian family"ZJSEP"帮派:liaotian party"
				ZJSEP"交易:liaotian bill"ZJSEP"拍卖:liaotian jiaoyi"ZJSEP"巫师:liaotian wiz"ZJSEP"系统:liaotian sys"ZJSEP"调试:liaotian debug"ZJSEP"大宗师:liaotian ultra"ZJSEP"塞外宗师:liaotian rultra"ZJSEP"联盟:liaotian inter"+"\n");
		return 1;
	}
	else str = arg;

	if(arg)
	{
		me->set_temp("pindao/id",arg);
		me->set_temp("pindao/name",str);
	}
	write(INPUTTXT("当前频道【"+me->query_temp("pindao/name")+"】，请输入内容：",
			me->query_temp("pindao/id")+" $txt#")+"\n"+ZJOBACTS2+ZJMENUF(3,3,9,30)"选择频道:liaotian pindao"ZJSEP"表情动作:emote\n");
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: time

这个指令告诉你现实世界中现在的时间。

HELP
    );
    return 1;
}
