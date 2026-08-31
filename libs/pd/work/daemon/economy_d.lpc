//      /daemon/mudlib/economy_d.c
//      from the Nightmare Mudlib
//      a daemon to handle currenciy inflation
//      created by Descartes of Borg 931114

#include <security.h>
#include <save.h>
#include <clock.h>

private mapping Currencies;
int LastInflation;

void create() {
    string *borg;
    float temps, tmp;
    int i;

    Currencies = ([]);
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_ECONOMY);
    seteuid(getuid());
    i = sizeof(borg = keys(Currencies));
/*    temps = percent(time()-LastInflation, YEAR)* 0.01;
    while(i--) { 
        tmp = temps * Currencies[borg[i]]["inflation"];
        Currencies[borg[i]]["rate"] += tmp*Currencies[borg[i]]["rate"];
    }
    LastInflation = time();
*/
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_ECONOMY);
    seteuid(getuid());
}

void add_currency(string type, float rate, float infl, float wt) {
    if(geteuid(previous_object()) != UID_APPROVAL) return;
    if(!mapp(Currencies)) Currencies = ([]);
    if(!type || !rate || !infl || !wt || Currencies[type]) return;
    Currencies[type] = ([ "rate":rate, "inflation":infl, "weight":wt ]);
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_ECONOMY);
    seteuid(getuid());
}

void change_currency(string type, string key, float x) {
    if(geteuid(previous_object()) != UID_APPROVAL) return;
    if(!mapp(Currencies)) Currencies = ([]);
    if(!type || !Currencies[type] || !key || !x) return;
    if(!Currencies[type][key]) return;
    Currencies[type][key] = x;
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_ECONOMY);
    seteuid(getuid());
}

float __Query(string type, string key) { 
if (!type || !key || type=="" || key=="") return 0;
if(!Currencies[type]) return 0;
return Currencies[type][key]; 
}

string *__QueryCurrencies() { return keys(Currencies); }
