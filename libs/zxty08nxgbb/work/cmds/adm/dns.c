#include <net/daemons.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
   if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
   write("网际互连已经关闭， 打开互连请用update dns_master\n");
   return 1;
}
