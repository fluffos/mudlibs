//**********************************************************************
// m_bank.c  by fire on Dec 14 1997  
#include <mudlib.h>
#include <move.h>
#include <sanguo.h>
inherit CHINESE_DA;
void deposit_sth(string item, int number)
{
    int p_buyersmoney;
    int p_itemvalue;
    int n_bank;
    string p_act;
    if(number<1)
    {
	write("醒醒，想啥呢？\n");
	return;
    }
    switch(item)
    {
	case "coin" :
		p_itemvalue=number;
                p_act="文钱";
		break;
	case "silver" :
		p_itemvalue=number*100;
  		p_act="两银子";
		break;
	case "gold" :
		p_itemvalue=number*10000;
		p_act="两金子";
		break;
	default :
		write("存钱方法：“deposit 货币数量 货币种类 例如：deposit 3 silver”\n");
		return;
    }
    p_buyersmoney=this_body()->query_all_con_money();
    if(p_buyersmoney<p_itemvalue)
    {
	write("在看看你身上有那么多钱吗？\n");
	return;
    }
    n_bank=this_body()->query_amt_money("bank");
    n_bank=n_bank+p_itemvalue;
    this_body()->set_all_con_money(p_buyersmoney - p_itemvalue);
    this_body()->set_money("bank", n_bank);
    p_act=chinese_number(number)+p_act;
    this_body()->simple_action("$N拿出"+p_act+"存入钱庄。\n");
    return;
}
void withdraw_sth(string item, int number)
{
    int p_buyersmoney;
    int p_itemvalue;
    int n_bank;
    string p_act,p_act2;
    if(number<1)
    {
	write("醒醒，想啥呢？\n");
	return;
    }
    switch(item)
    {
	case "coin" :
		p_itemvalue=number;
                p_act="文钱";
		break;
	case "silver" :
		p_itemvalue=number*100;
  		p_act="两银子";
		break;
	case "gold" :
		p_itemvalue=number*10000;
		p_act="两金子";
		break;
	default :
		write("取钱方法：“withdraw 货币数量 货币种类 例如：withdraw 3 silver”\n");
		return;
    }
    n_bank=this_body()->query_amt_money("bank");
    p_buyersmoney=this_body()->query_all_con_money();
    if(n_bank<p_itemvalue)
    {
	write("你在钱庄没有存这么多钱呀？\n");
	return;
    }
    n_bank=n_bank-p_itemvalue;
    this_body()->set_money("bank", n_bank);
    p_act=chinese_number(number)+p_act;
    p_itemvalue=p_itemvalue*BANKINTEREST;
    p_act2=chinese_value(p_itemvalue);
    this_body()->set_all_con_money(p_buyersmoney + p_itemvalue);
    this_body()->simple_action("$N从钱庄取出"+p_act+"实际拿到了"+p_act2);
    return;
}
mixed deposit(string item, int number)
{
	deposit_sth(item,number);
	return 1;
}	
mixed withdraw(string item, int number)
{
	withdraw_sth(item,number);
	return 1;
}	
