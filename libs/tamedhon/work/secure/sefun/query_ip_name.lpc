//
// Wunderland Mudlib
//
// secure/sefun/query_ip_name.c -- query_ip_name/number fuer ldmud 3.5
//
// $Log: query_ip_name.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

/* This sefun is to provide a replacement for the efuns query_ip_name() and
 * query_ip_number().
 * Feel free to add it to your mudlibs, if you have much code relying on that.
 */

#if ! __EFUN_DEFINED__(query_ip_name)

#include <interactive_info.h>

private varargs string efun_query_ip_name(object player)
{
    object ob = player;
    ob ||= efun::this_player();

    player = efun::interactive_info(ob, II_IP_ADDRESS);
    return efun::interactive_info(ob, II_IP_NAME);
}

private varargs string efun_query_ip_number(object player)
{
    object ob = player;
    ob ||= efun::this_player();

    player = efun::interactive_info(ob, II_IP_ADDRESS);
    return efun::interactive_info(ob, II_IP_NUMBER);
}

#else

#define efun_query_ip_name   efun::query_ip_name
#define efun_query_ip_number efun::query_ip_number

#endif
