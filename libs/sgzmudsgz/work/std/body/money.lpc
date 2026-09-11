// Updated by stefan on 10 Jan 1997 and by fire on Dec 13 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
//   
//   This is a simple money implementation
//
//    written by zifnab@lima bean 10/95
//
//  please comment away and feel free to modify anything you want
//
//  also please be kind this is my first attempt at anything like thi
//  this :).  please note that there are no checks of any kind in here yet
// to se if the type of currency is valid or not
//
#include <mudlib.h>
private   mapping money;
//  This is the functin to call to query the amount of a certain type
//  of currency you have.
//
int query_amt_money(string type)
{
    if(!money)
        return 0;
    if(!money[type])
        return 0;
    return money[type];
}
//
//  This is the function to call to add money to a person 
//   
void set_money(string type, int amount)
{
    if(!money)
        money = ([]);
    money[type] = amount;
}
void add_money(string type, int amount)
{
    if(!money)
        money = ([]);
    if(!type || !amount)
        return;
    if(!money[type])
        money[type] = amount;
    else
        money[type] += amount;
    if(money[type] < 1)
        map_delete(money, type);
}
void subtract_money(string type, int amount)
{
    add_money(type, -amount);
}
//   This function will return the current "types" of money you have
//
int *query_currencies()
{
    if(!money)
        return ({});
    return keys(money);
}
// this fun get the inf of the obj money amt
// and then keep it in the stored money sys
void put_m_money(string type)
{
	int p_num;
        p_num=this_object()->query_con_money(type);
	set_money( type , p_num);
}
void put_m_all_money()
{
	put_m_money("coin");
	put_m_money("silver");
	put_m_money("gold");
}
void get_m_money(string type)
{
	int p_num;
	p_num=query_amt_money(type);
	this_object()->set_con_money(type,  p_num);
}
void get_m_all_money()
{
	get_m_money("coin");
	get_m_money("silver");
	get_m_money("gold");
}
