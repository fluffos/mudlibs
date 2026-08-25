// experimental
#include <mudlib.h>
#include <sanguo.h>
#include "/wiz/lcm/trade/trade.h"

inherit CMD;

private void main(string arg)
{
    string uid, op;
    object who;
    int id;
    if (!arg)
    {
        write("use testtrade userid\n");
        return;
    }
    if (sscanf(arg, "%s %d", op, id) == 2)
    {
        if (op == "rm")        
          (DATA_TRADE)->removeTrade(id);
        return;
    }
// only allow one form of input
    if (sscanf(arg, "%s", uid) != 1)
    {
        write("use testtrade userid\n");
        return;
    }
//    who = CHAR_D->find_char(uid);
    who = find_body(uid);
    if (!(objectp(who)))
    {
        printf(uid + " is not an object\r\n");
        return;
    }
    (GEN_TRADE)->initiate(this_body(), who);
    return;
}
