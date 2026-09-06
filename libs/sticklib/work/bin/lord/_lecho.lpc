#include <lord.h>
/*
	Lord command:	lecho
	Syntax:		lecho [none,ok,all]
	Conditions:	need to be a lord
	Effects:	alters the amount of returned info from lord channel
*/

#define ECHO            "CHANNEL_ECHO"

int lecho_cmd(string str, object who) {
    int x;

    if((LL < SQUIRE) && !(CODER)) return 0;

    if(!(str) || ((x=member(({"none","ok","all"}), str)) == -1))
	return notify_fail("Usage: lecho [none,ok,all].\n"),0;

    switch(x) {
    case 0: who->set_env(ECHO,-1); who->tell_me("lchan: no echo"); break;
    case 1: who->set_env(ECHO,1);  who->tell_me("lchan: ok echo"); break;
    default: who->set_env(ECHO,0); who->tell_me("lchan: message echo"); break;
    }
    return 1;
}
