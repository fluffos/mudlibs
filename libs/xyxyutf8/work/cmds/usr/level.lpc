#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i,p,lvl,need,now_level,f=0;
	object who;
	
	if( !arg )
	{
		who = me;
		lvl = 1;
	}
	else if( sscanf(arg,"%s %d",arg,lvl)==2 )
	{
		if( !wizardp(me) )
			return notify_fail("只有巫师才能查看他人信息。\n");
		who = find_player(arg);			
	}
	else 
	{
		who = me;
		if( sscanf(arg,"%d",lvl)!=1 )
			lvl = 1;
	}			
	if( lvl<0 || lvl>20 )
		return notify_fail("还是脚踏实地才是正道。\n");
	if( !who )
		return notify_fail("没有这个人。\n");		
	now_level = who->query_level();
	if( now_level>=140 )
		return notify_fail("140级后每次升级需要武学经验2000000000点，你自己算吧。\n");
	lvl = now_level+lvl;
	if( lvl<=now_level )
		return notify_fail("你现在的人物等级已不低于"+lvl+"了。\n");	
	need = 0;	
	for(i=now_level;i<lvl;i++ )
	{
		if( i>=140 )
			need+= 2000000000;
		else
		{	
			p = ((i*i*i+60)/5*((i-1)*2+60))/100*1000;
			if( p<10000 )
				p = 10000;  
			need+= p;
		}
	}
	need-= who->query("combat_exp");
	write((me==who?"你":who->name(1))+"升级到"+lvl+"，还需要武学经验"+need+"点(突破除外)。\n");
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : level [需升的等级]
 
这个指令可以显示你从当前等级再提升[需升的等级]，所需的武学经验(突破任务除外)。
只能查跨度20级之内所需的经验。
 
HELP
    );
    return 1;
}

