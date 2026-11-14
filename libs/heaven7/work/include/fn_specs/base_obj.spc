#ifndef BASE_OBJ_H
#define BASE_OBJ_H


/*** function prototypes ***/

/*  general queries */

string query_object_type();
string query_create_room();

varargs string query_name(status arg);
string query_id();
string query_alias_name();
string query_alias();
string query_alt_name();
string query_short();
string query_long();
string query_extra_long();
string query_info();
string query_read();
string query_listen();
string query_smell();

int query_weight();
int query_value();
int query_light();
int query_light_value();

status query_enchanted();
status query_modified();
status query_quest_item();

status query_sell_destruct();

mixed query(string fun, mixed arg1, mixed arg2);



/* general sets */

string set_name(string s);
string set_id(string s);
string set_alias_name(string s);
string set_alias(string s);
string set_alt_name(string s);

string set_short(string s);
string set_long(string s);
string set_extra_long(string s);
string set_info(string s);
string set_read(string s);
string set_listen(string s);
string set_smell(string s);

int set_weight(int i);
int set_value(int i);

status set_enchanted(status s);
status set_modified(status s);
status set_quest_item(status s);

status set_sell_destruct(status s);

mixed set(string fun, mixed arg1, mixed arg2);

int adj_light(int i);


/* called by present() efun */

status id(string str);


/* called by the inventory of a 'look at' command, or brief mode */

string short(status wiz);


/* called by 'look at', or 'look' in room */

void long(status wiz);


/* called by 'examine' cmd */

void extra_long(status wiz);

/* show inventory */

varargs status show_inventory(object ob);

/* called by 'identify', 'divination' spells, or oracles */

void info();


/* from 'read' cmd */

status read_msg(string str);







/* init is called this is 1st moved, or something is moved into this */

void init();

/* end prototypes */

#endif /* end  BASE_OBJ_H */
