#ifndef __QUERY__
#define __QUERY__

//#include "/adm/daemons/itemd.lpc"

int add_char(object ob);
int del_char(int index);
mapping query_all_char();
mapping query_char(int index);

int add_eq(object ob);
int del_eq(int index);
mapping query_all_eq();
mapping query_eq(int index);

int add_wp(object ob);
int del_wp(int index);
mapping query_all_wp();
mapping query_wp(int index);

int add_food(object ob);
int del_food(int index);
mapping query_all_food();
mapping query_food(int index);

int add_other(object ob);
int del_other(int index);
mapping query_all_other();
mapping query_other(int index);

int add_item(object ob, int index);

#endif
