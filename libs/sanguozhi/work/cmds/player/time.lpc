// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/********************************************************
 *                                                      *
 *   uptime  -  reports how long the mud has been up.   *

 ** *  copied from ideaexchange where it was originally*
 *  created by beek@nightmare                     *

 *   copied by zifnab@zorkmud                           *
 *
 *********************************************************/
#include <mudlib.h>
#include <daemons.h>

inherit CMD;


private void main(string notused)
{
    string tm2 = CHINESE_D->chinese_time(time());
    int tm3 = time() - uptime();
    string tm4 = CHINESE_D->chinese_time(tm3);
    string str;
 
    int x;
   out("当地时间\t\t"+ tm2 +"\n");
   out(mud_name()+"启动于\t\t" + tm4 +"\n");
   out("本次运行时间为\t\t" + CHINESE_D->chinese_period(uptime())+"\n");
}
