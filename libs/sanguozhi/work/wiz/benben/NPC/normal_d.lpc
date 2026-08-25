// normal_d.c write by fire on 26 Dec. 1997
// daemons NORMAL_D
#include <sanguo.h>
inherit M_DAEMON_DATA;
int query_money_value(int number,string str)
{
	if ((number<0)||(number>1000000))
		return 0;
	switch(str)
	{
		case "coin" :
			return number;
		case "silver" :
			return number*100;
		case "gold" :
			return number*10000;
		default :
			return 0;
	}
}
string get_dis1(int p_age, int p_gender)
{
	string p_tmp;
	int pp_age;
	pp_age=p_age/10;
	switch(pp_age)
	{
		case 0:
			p_tmp="儿童";
			break;
		case 1:
			p_tmp="少年";
			break;
		case 2:
			p_tmp="青年";
			break;
		case 3: 
			p_tmp="成年";
			break;
		case 4:
			p_tmp="中年";
			break;
		case 5:
		case 6:
			p_tmp="壮年";
			if(p_gender==2)
				p_tmp="中年";
			break;
		default :
			p_tmp="老年";
	}
	switch(p_gender)
	{
		case 1:
			p_tmp=p_tmp+"男子";
			break;
		case 2:
			p_tmp=p_tmp+"女子";
			break;
		default :
			p_tmp=p_tmp+"中性人";
	}
       return p_tmp;
}
string get_rongmao(int p_age,int p_rongmao, int p_gender )
{
	string p_res;
	if(p_gender==1) // a male
	{
		if(p_rongmao>20)
		{
			if(p_age>20)
                                return "长得如同梦中的白马王子。\n";
			else
			{
				if(random(2))
                                        return "是一个俊俏的小男孩。\n";


				else
                                        return "看上去可爱又调皮。\n";
			}
		}
		else
		{
			if(p_age>20)
                                return "长得象一个杀猪的。\n";
			else
			{
				if(random(2))
                                        return "是一个丑小子。\n";
				else
                                        return "看上去将来很难找到媳妇。\n";

			}
		}
	}
	else // for female
	{
		if(p_rongmao>20)
                        return "看上去象个美女。\n";
                return "是一个象貌平庸的女人。\n";
	}
}
