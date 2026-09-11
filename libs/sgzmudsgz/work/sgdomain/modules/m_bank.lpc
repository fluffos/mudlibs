//**********************************************************************
// m_bank.c  by fire on Dec 14 1997  
#include <mudlib.h>
#include <move.h>
inherit INDOOR_ROOM;
#define MAXBANKMONEY 30000000
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
    if((n_bank+p_itemvalue)>MAXBANKMONEY)
    {
        write("目前钱庄最多只能存"+chinese_value(MAXBANKMONEY));
        return;
    }
    n_bank=n_bank+p_itemvalue;
    this_body()->set_all_con_money(p_buyersmoney - p_itemvalue);
    this_body()->set_money("bank", n_bank);
    p_act=chinese_number(number)+p_act;
    this_body()->simple_action("$N拿出"+p_act+"存入钱庄。\n");
    return;
}
void withdraw_salary()
{
   string p_id;
   int p_salary,p_with;
   int p_bank;
   p_id=(this_body()->query_id())[0];
   p_salary=CHAR_D->get_char(p_id,"gold");
   if(!p_salary)
   {  write("你目前没有库存俸银。\n");
      return;
   }
   p_with=1;
   if(p_salary>20) p_with=10;
   if(p_salary>200) p_with=100;
   p_bank=this_body()->query_amt_money("bank");
   if((p_bank+p_with*10000)>MAXBANKMONEY)
   {
      write("目前钱庄最多只能存"+chinese_value(MAXBANKMONEY));
      return;
   }
   p_bank+=(p_with*10000*0.9);
   write("你的库存俸银中的"+chinese_number(p_with)+"两黄金已转入你的私人账户。\n"
   +"手续费："+CHINESE_D->chinese_value(p_with*1000)+"。\n");
   this_body()->set_money("bank", p_bank);
   CHAR_D->set_char(p_id,"gold",p_salary-p_with);
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
        case "salary":
                withdraw_salary();
                return;
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
int is_bank() { return 1;}
