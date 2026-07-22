// moneyd.c  钱的功能
// Ronger 11/98
// by Xiang@XKX (95/12/22)

#include <ansi.h>

varargs string money_str(int amount,int no_color)
{
	string output;
	if( amount/10000) 
        {
        	output = chinese_number(amount / 10000) + "两"HIY"黄金"NOR;
        	amount %= 10000;
        }
	else    output = "";
	if( amount/100 ) 
        {
        	output = output + chinese_number(amount / 100) + "两"HIW"白银"NOR;
        	amount %= 100;
        }
	if( no_color )
        	output = COLOR_D->clean_color(output);        
	if( amount )
        {
        	if( !no_color )        
                	return output + chinese_number(amount) + "文"YEL"铜板"NOR;
        	else    return output + chinese_number(amount) + "文铜板";
        }
	return output;
}

int check_balance(object who)
{
	if( !who )
        	return 0;       
        return who->check_balance(1);	
}

//给钱
int pay_player(object who, int amount)
{
	object ob;
	if( !who )
        	return 0;
	if( amount < 1 ) 
        	return 0;
	who->money_add(amount);
	return 1;   
}
