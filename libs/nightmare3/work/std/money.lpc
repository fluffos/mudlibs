//      /std/money.c
//      from the Nigttmare mudlib
//      an inheritable money object, for hard and soft currencies
//      created by Descartes of Borg 24 april 1994

#include <daemons.h>

private mapping money;

string *query_currencies();

int query_money(string str) {
    if(!money) money = ([]);
    if(!str || !stringp(str)) return 0;
    return money[str];
}

void add_money(string str, int amount) {
    string logging;

    if(!str || !stringp(str) || !intp(amount)) return;
    if(!money) money = ([]);
    if(!money[str]) money[str] = amount;
    else money[str] += amount;
    if(money[str] < 1) map_delete(money, str);
    if(creatorp(this_object()) || !this_object()->is_player()) return;
    switch(str) {
        case "platinum": amount *=10; break;
        case "gold": break;
        case "silver": amount /=10; break;
        case "electrum": amount /=50; break;
        case "copper": amount /= 100; break;
        default: return;
    }
    if(amount < 700) return;
    if(!this_player() || this_player() == this_object())
      logging = "PRIV: "+query_privs(previous_object())+" ("+file_name(previous_object())+")";
    else logging = (string)this_player()->query_name();
    log_file("money", this_object()->query_name()+" received "+
      amount + " gold in "+str+" from "+logging+"\n");
    log_file("money", ctime(time())+"\n");
}

void set_money(string type, int amount) {
    if(this_object()->is_player()) return;
    if(amount < 0) return;
    if(!type || !stringp(type) || !intp(amount)) return;
    if(!money) money = ([]);
    money[type] = amount;
}


string *query_currencies() { 
    if(!money) return ({});
    else return keys(money);
}
