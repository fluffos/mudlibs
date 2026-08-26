 
//  File  :  /include/login_macros.h
//
//  These macros are used by the login daemon
 
#ifndef __LOGIN__
#define NAME		query("name")
#define PASS		query("password")
#define BODY		query("body")
#define EMAIL		query("email")
#define RNAME		query("real_name")
#define BODY_OB		query("body_ob")
#define SET_NAME(x)	set("name", x)
#define SET_PASS(x)	set("password", x)
#define SET_BODY(x)	set("body", x)
#define SET_EMAIL(x)	set("email", x)
#define SET_RNAME(x)	set("real_name", x)
#define SET_BODY_OB(x)	set("body_ob", x)
#define CAP_NAME	query("cap_name")
#define LINK_CAP_NAME   link_data("cap_name")

#define __LOGIN__
#endif

