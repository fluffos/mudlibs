/*    /cmds/adm/_currency.c
 *    from Nightmare 3.3
 *    a balance tool to see what currency is in the game right now
 *    created by Descartes of Borg 941002
 */

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_currency(string arg) {
    mapping borg;
    object *who;
    string *money;
    string str;
    int i, x, j, y, z;

    if(arg) i = sizeof(who = ({ find_player(convert_name(arg)) }));
    else i = sizeof(who = users());
    str = "";
    while(i--) {
        string tmp;

        x = 0;
        tmp = "";
        if(who[i]) j = sizeof(money = (string *)who[i]->query_currencies());
        else {
            j = 0;
            str = capitalize(arg)+"\n";
        }
        while(j--) {
            z = currency_rate(money[j]);
            if(z) x += (y=(int)who[i]->query_money(money[j]))/z;
            tmp += sprintf("%:-15s: %d (%d base)\n", money[j], y, (z ? y/z : 0));
        }
        if(who[i]) str += sprintf("%:-20s\n%:-15s %d\n%s\n",
          (string)who[i]->query_CapName(), "BASE", x, tmp);
        if(who[i]) borg=(mapping)BANK_D->account_summary((string)who[i]->query_name());
        else borg = (mapping)BANK_D->account_summary(convert_name(arg));
        str += sprintf("In various banks...\n%:-15s %d\n",
          "BASE", borg["base"]);
        j = sizeof(money = keys(borg));
        while(j--) {
            if(money[j] == "base") continue;
            z = currency_rate(money[j]);
            if(z) y = borg[money[j]]/z;
            else y = 0;
            str += sprintf("%:-15s: %d (%d base)\n", money[j], borg[money[j]], y);
        }
        str += "\n\n";
    }
    this_player()->more(explode(str, "\n"), "system");
    return 1;
}
