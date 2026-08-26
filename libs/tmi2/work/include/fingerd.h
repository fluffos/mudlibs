/*
// This is part of the TMI distribution mudlib.
// Please retain this header if you use this code.
// Coded by Jubal (91-12-11)
*/


#ifndef __FINGERD_H
#define __FINGERD_H


#define FINGERD "/adm/daemons/finger"

#define query_user_exists(x) (int) FINGERD -> _query_user_exists(x)
#define query_rname(x) (string) FINGERD -> _query_rname(x)
#define query_position(x) (string) FINGERD -> _query_position(x)
#define query_last_on(x) (string) FINGERD -> _query_last_on(x)
#define query_ip(x) (string) FINGERD -> _query_ip(x)
#define query_level(x) (int) FINGERD -> _query_level(x)
#define query_age(x) (int) FINGERD -> _query_age(x)
#define query_mail(x) (int) FINGERD -> _query_mail(x)
#define query_email(x) (string) FINGERD -> _query_email(x)
#define query_environment(x,y) (string) FINGERD -> _query_environment(x,y)


#endif !__FINGERD_H


/* EOF */
