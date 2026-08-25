// Quick command made by Radix, Sept 1996
#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup()
{
    position = 0;
}

string query_usage()
{
    return "command";
}


protected int cmd(string str, object me) {
    string *mem, mems2;
    int cols, i;
    mems2 = "";
    cols = (int)me->query_cols();
    mem = "/secure/ftpd"->query_connections();
    mems2 = implode(mem,"\n");
    write(sprintf("\n%*#-s\n",cols,mems2));
    return 1;
}
