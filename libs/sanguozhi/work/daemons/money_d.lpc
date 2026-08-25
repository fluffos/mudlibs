// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** money_d.c -- money daemon
**
** This daemon manages the legal types of money within the game and their
** exchange rates.
**
** Objects have an inherent "value".  This is then translated into a
** particular currency via that currency's value -> actual exchange rate.
**
** 951205, Zifnab: created
** 951213, Deathblade: installed as money_d.c
*/

//### this daemon needs interfaces with admtool to manage the types and
//### the exchange rates.
//### Note: if these should only be adjustable by an admin, then this
//### daemon must move to /secure/daemons to prevent tampering with any
//### security restrictions that are added.


//### these should probably be singular
private mapping VALID_MONEY =  ([ "gold" : 1, "zorkmid" : 3 ]);


//:FUNCTION query_exchange_rate
//Returns the exchange rate to map from an object's inherent value to its
//actual value in a particular currency.
int query_exchange_rate(string type)
{
    return VALID_MONEY[type];
}

//:FUNCTION query_valid_currencies
//Returns the names of the currencies that are valid within the mud
string *query_valid_currencies()
{
    return keys(VALID_MONEY);
}

int get_poket_money(object o) {
	return o->query_all_con_money();
}
int get_bank_money (object o) {
	return o->query_amt_money("bank");
}
int get_salary_money (object o) {
	string p_id=o->query_primary_id();
	return CHAR_D->get_char(p_id,"gold")*10000;
}
int get_all_money (object o) {
	return get_poket_money(o)+get_bank_money(o)+get_salary_money(o);
}


int add_poket_money(object o,int v) {
	o->set_all_con_money(get_poket_money(o)+v);
	return 1;
}
int add_bank_money(object o,int v) {
	o->set_money("bank", get_bank_money(o)+v);
	return 1;
}
int add_salary_money(object o,int v) {
	string p_id=o->query_primary_id();
	CHAR_D->set_char(p_id,"gold",CHAR_D->get_char(p_id,"gold")+v/10000);
	return 1;
}

int sub_poket_money(object o,int v) {
	int va;
	va=get_poket_money(o);
	if(va<v) return -1; // not enough
	o->set_all_con_money(va-v);
	return 1;
}
int sub_bank_money(object o,int v) {
	int va;
	va=get_bank_money(o);
	if(va<v) return -1; // not enough
	o->set_money("bank",va-v);
	return 1;
}
int sub_salary_money(object o,int v) {
	int va;
	string p_id=o->query_primary_id();
	va=get_salary_money(o);
	if(va<v) return -1; // not enough
	CHAR_D->set_char(p_id,"gold",CHAR_D->get_char(p_id,"gold")-v/10000);
	return 1;
}
int sub_all_money(object o, int v) {
	int va,vv,tmp;
	int vs,vb,vp;
	va=get_all_money(o);
	if(va<v) return -1; // not enough

	vv=v/10000;
	vv=vv*10000;
	v=v-vv;  // used to determained the gold part

	vs=get_salary_money(o);
	tmp=bmin(vv,vs);
	sub_salary_money(o,tmp);
	vv-=tmp;
	v+=vv;
	if(!v) return 1;

	vb=get_bank_money(o);
	tmp=bmin(v,vb);
	sub_bank_money(o,tmp);
	v-=tmp;
	if(!v) return 1;

	vp=get_poket_money(o);
	tmp=bmin(v,vp);
	if(sub_poket_money(o,tmp)==-1) {
		sub_salary_money(o,10000);
		add_poket_money(o,10000);
		sub_poket_money(o,tmp);
	}
	return 1;
}
