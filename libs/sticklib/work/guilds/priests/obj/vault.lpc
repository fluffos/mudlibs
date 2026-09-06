/* Vault of the Treasury */

#include "../priest.h"
#include <treasure.h>

void
create_treasure() {
    set_name("vault");
    set_short("A picture has been moved aside, revealing a hidden vault");
    set_long("An indestructable steel-lined vault is set into the \
wall here. It seems to contian a great deal of money and some ledger sheets. \
Maybe you should tally these.");
    set_id(({"vault","safe","kooch"}));/*sorry, it makes debug easier*/
}

get(){return 0;}

init_treasure() {
    add_action("account","tally");
    add_action("deposit","deposit");
    add_action("withdraw","withdraw");
    if(this_player()->query_guild() != "priest"){
	add_action("take_cmd","take");}

}

account(){
    if(this_player()->query_guild() != "priest"){
	notify_fail("Why would you bother with that?\n");
	return 0;
    }
    this_player()->tell_me("You quickly total the debit/credit columns \
on the accounting sheet attached to the vault door. You find that there is \
a balance of "+CASH_D->query_cash()+" gold coins.");
    return 1;
}

deposit(string dumb){
    int my_cash,new_amount,amount;
    my_cash=(int)this_player()->query_money();
    if(sscanf(dumb,"%d",amount)<1){return 0;}
    if(my_cash < (int)amount){
	notify_fail("You do not have that many coins.\n");
	return 0;
    }

    new_amount=(int)CASH_D->add_money(amount,this_player()->query_real_name());
    this_player()->add_money(-amount);
    this_player()->tell_me("The new balance is: "+new_amount+".");
    return new_amount;
}

withdraw(string dumb){
    int my_cash,old_amount,new_amount,amount;
    if(this_player()->query_guild() != "priest"){
	notify_fail("Like you would really bother with all this.\n"+
	  "Wouldn't you simply take the cash?\n");
	return 0;
    }

    if(sscanf(dumb,"%d",amount)<1){return 0;}
    my_cash=(this_player()->query_money());
    old_amount=(int)CASH_D->query_cash();

    if(old_amount<amount){
	notify_fail("But the vault only contains "+
	  old_amount+" coins.\n");
	return 0;
    }

    new_amount=(int)CASH_D->subtract_money(amount,this_player()->query_real_name());
    this_player()->tell_me("You withdraw "+amount+" coins form the \
vault, leaving a balance of "+new_amount+" gold coins.");
    this_player()->add_money(amount);
    return new_amount;
}
take_cmd(string s){
    object *priests,me,*tmp;
    int ingame,amount,i,stolen,available;

    if(s!="cash" && s!="money" && s!="coins" && s!="gold coins"){
	return 0;
    }

    me=this_player();

    if(!(CASH_D->query_stolen())) {
	tmp = SERVER->query_priests();
	priests = filter_array(tmp, #'interactive);

	for(i=0;i<sizeof(priests);i++){
	    if(priests[i]->query_level()>27 &&
	      priests[i]->query_coder_level() == 0) ingame+=1;
	}

	amount = 25000 + ingame*500000;

	if((available=(int)SERVER->query_cash()) < amount)
	    amount=available;

	me->tell_me("You manage to steal "+amount+" from the vault!");
	environment(me)->tell_here(me->query_name()+
	  " steals some coins from the vault.",me);
	CASH_D->subtract_money(amount,me->query_real_name());
	me->set_money((me->query_money())+amount);
	CASH_D->set_stolen();
	return 1;
    }

    if(CASH_D->query_stolen()) {
	this_player()->tell_me("Someone has already cleaned out \
the vault. Better luck next time.");
	return 1;
    }

}
