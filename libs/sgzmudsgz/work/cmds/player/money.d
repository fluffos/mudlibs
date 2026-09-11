// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit CMD;
private void main()
{
    int i;
    int amount;
    string currency;
    string retmsg;
    string *types;

    types = this_body()->query_currencies();
    i = sizeof(types);
    if(!i)
        out("你把口袋翻了个底朝天，结果一无所获。\n");
    else
    {
      out ("你有以下几种货币：\n");
        while(i--)
        {
            currency = types[i];
            amount = this_body()->query_amt_money(currency);
            outf("\n%10s %-30i\n", currency,amount);
        }
    }
}
